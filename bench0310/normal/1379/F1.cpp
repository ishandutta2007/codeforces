#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> tree(4*N,0);
vector<int> lazy(4*N,0);
vector<int> on(4*N,0);
vector<int> res(N,1);

void pull(int idx)
{
    tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    on[idx]=on[2*idx]+on[2*idx+1];
}

void build(int idx,int l,int r)
{
    if(l==r) on[idx]=1;
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        pull(idx);
    }
}

void apply(int idx,int x)
{
    if(on[idx]>0)
    {
        tree[idx]=max(tree[idx],x);
        lazy[idx]=max(lazy[idx],x);
    }
}

void push(int idx)
{
    for(int i=0;i<2;i++) apply(2*idx+i,lazy[idx]);
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,x);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        pull(idx);
    }
}

void descend(int idx,int l,int r,int ql,int qr,int lim)
{
    if(ql>qr) return;
    if(on[idx]==0||tree[idx]<lim) return;
    if(l==r)
    {
        tree[idx]=0;
        on[idx]=0;
        res[l]=0;
    }
    else
    {
        int m=(l+r)/2;
        push(idx);
        descend(2*idx,l,m,ql,min(qr,m),lim);
        descend(2*idx+1,m+1,r,max(ql,m+1),qr,lim);
        pull(idx);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<array<int,3>> v(q);
    for(int i=1;auto &[r,c,id]:v)
    {
        cin >> r >> c;
        id=(i++);
    }
    ranges::sort(v);
    vector<array<int,5>> u;
    int l=0;
    while(l<q)
    {
        int nl=l;
        int x=v[l][0];
        int y=v[l][1];
        int r=(x-1)/2+1;
        int c=(y-1)/2+1;
        int tp=(x&1)+1;
        while(nl+1<q&&v[nl+1][0]==x&&v[nl+1][1]==y) nl++;
        vector<int> t;
        for(int i=l;i<=nl;i++) t.push_back(v[i][2]);
        if(t.size()&1) t.push_back(q+1);
        for(int i=0;i+1<(int)t.size();i+=2) u.push_back({c,r,-tp,t[i],t[i+1]-1});
        l=nl+1;
    }
    ranges::sort(u,greater<>());
    build(1,1,q);
    for(auto [c,r,t,tl,tr]:u)
    {
        if(t==-1) update(1,1,q,tl,tr,r);
        else descend(1,1,q,tl,tr,r);
    }
    for(int i=1;i<=q;i++)
    {
        if(res[i]==1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}