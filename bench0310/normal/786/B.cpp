#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
const ll inf=(1ll<<60);
vector<array<int,3>> v[N]; //l,r,d
//one
vector<ll> tree(4*N,inf); //current distance from src
vector<int> id(4*N,0); //id of vertex with min distance in a subtree
vector<ll> lazy(4*N,inf); //lazy updates
vector<int> cnt(4*N,0); //number of unused vertices in a subtree
//two
vector<array<int,4>> medges; //l,r,to,d
vector<array<int,2>> ini[N]; //initial medges
vector<vector<array<int,2>>> st(4*N); //values in segment tree
vector<int> mx(4*N,0); //maximum r in a subtree
vector<int> mxid(4*N,0); //id of maximum r in a subtree

void build_one(int idx,int l,int r)
{
    if(l==r)
    {
        cnt[idx]=1;
        id[idx]=l;
    }
    else
    {
        int m=(l+r)/2;
        build_one(2*idx,l,m);
        build_one(2*idx+1,m+1,r);
        cnt[idx]=cnt[2*idx]+cnt[2*idx+1];
        id[idx]=id[2*idx];
    }
}

void push_one(int idx)
{
    if(cnt[2*idx]>0)
    {
        tree[2*idx]=min(tree[2*idx],lazy[idx]);
        lazy[2*idx]=min(lazy[2*idx],lazy[idx]);
    }
    if(cnt[2*idx+1]>0)
    {
        tree[2*idx+1]=min(tree[2*idx+1],lazy[idx]);
        lazy[2*idx+1]=min(lazy[2*idx+1],lazy[idx]);
    }
    lazy[idx]=inf;
}

void update_one(int idx,int l,int r,int ql,int qr,ll val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        if(cnt[idx]>0)
        {
            tree[idx]=min(tree[idx],val);
            lazy[idx]=min(lazy[idx],val);
        }
    }
    else
    {
        int m=(l+r)/2;
        push_one(idx);
        update_one(2*idx,l,m,ql,min(qr,m),val);
        update_one(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
        if(cnt[2*idx]>0&&tree[2*idx]<=tree[2*idx+1]) id[idx]=id[2*idx];
        else id[idx]=id[2*idx+1];
    }
}

void rm_one(int idx,int l,int r,int pos)
{
    if(l==r)
    {
        cnt[idx]=0;
        tree[idx]=inf;
    }
    else
    {
        push_one(idx);
        int m=(l+r)/2;
        if(pos<=m) rm_one(2*idx,l,m,pos);
        else rm_one(2*idx+1,m+1,r,pos);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
        cnt[idx]=cnt[2*idx]+cnt[2*idx+1];
        if(cnt[2*idx]>0&&tree[2*idx]<=tree[2*idx+1]) id[idx]=id[2*idx];
        else id[idx]=id[2*idx+1];
    }
}

array<ll,2> query_one()
{
    return {tree[1],id[1]};
}

void build_two(int idx,int l,int r)
{
    if(l==r)
    {
        st[idx].push_back({0,0});
        sort(ini[l].begin(),ini[l].end());
        for(array<int,2> a:ini[l]) st[idx].push_back(a);
        mx[idx]=st[idx].back()[0];
        mxid[idx]=l;
    }
    else
    {
        int m=(l+r)/2;
        build_two(2*idx,l,m);
        build_two(2*idx+1,m+1,r);
        mx[idx]=max(mx[2*idx],mx[2*idx+1]);
        if(mx[2*idx]>=mx[2*idx+1]) mxid[idx]=mxid[2*idx];
        else mxid[idx]=mxid[2*idx+1];
    }
}

int rm_two(int idx,int l,int r,int pos)
{
    if(l==r) return st[idx].back()[1];
    int m=(l+r)/2;
    if(pos<=m) return rm_two(2*idx,l,m,pos);
    else return rm_two(2*idx+1,m+1,r,pos);
}

void update_two(int idx,int l,int r,int pos)
{
    if(l==r)
    {
        st[idx].pop_back();
        mx[idx]=st[idx].back()[0];
    }
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update_two(2*idx,l,m,pos);
        else update_two(2*idx+1,m+1,r,pos);
        mx[idx]=max(mx[2*idx],mx[2*idx+1]);
        if(mx[2*idx]>=mx[2*idx+1]) mxid[idx]=mxid[2*idx];
        else mxid[idx]=mxid[2*idx+1];
    }

}

array<int,2> query_two(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {0,0};
    if(l==ql&&r==qr) return {mx[idx],mxid[idx]};
    int m=(l+r)/2;
    return max(query_two(2*idx,l,m,ql,min(qr,m)),query_two(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q,src;
    cin >> n >> q >> src;
    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int a,b,c;
            cin >> a >> b >> c;
            v[a].push_back({b,b,c});
        }
        else
        {
            int a,l,r,c;
            cin >> a >> l >> r >> c;
            if(t==2) v[a].push_back({l,r,c});
            else
            {
                medges.push_back({l,r,a,c});
                ini[l].push_back({r,(int)medges.size()-1});
            }
        }
    }
    build_one(1,1,n);
    build_two(1,1,n);
    vector<ll> res(n+1,inf);
    res[src]=0;
    update_one(1,1,n,src,src,0);
    for(int z=1;z<=n;z++)
    {
        auto [dist,a]=query_one();
        if(dist==inf) break;
        res[a]=dist;
        rm_one(1,1,n,a);
        for(auto [l,r,d]:v[a]) update_one(1,1,n,l,r,dist+d);
        array<int,2> tmp;
        while((tmp=query_two(1,1,n,1,a))[0]>=a)
        {
            int x=tmp[1];
            int idx=rm_two(1,1,n,x);
            update_two(1,1,n,x);
            int to=medges[idx][2];
            int d=medges[idx][3];
            update_one(1,1,n,to,to,dist+d);
        }
    }
    for(int i=1;i<=n;i++) cout << (res[i]!=inf?res[i]:-1) << " \n"[i==n];
    return 0;
}