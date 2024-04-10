#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

const int N=1200005;
vector<int> tree(4*N,0);
vector<int> sz(4*N,0);
vector<int> lazy(4*N,2);
vector<int> val(N,0);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=sz[idx]=val[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=sz[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

void push(int idx)
{
    tree[2*idx]=(lazy[idx]==1?sz[2*idx]:0);
    tree[2*idx+1]=(lazy[idx]==1?sz[2*idx+1]:0);
    lazy[2*idx]=lazy[2*idx+1]=lazy[idx];
    lazy[idx]=2;
}

void update(int idx,int l,int r,int ql,int qr,int k)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]=(k==1?sz[idx]:0);
        lazy[idx]=k;
    }
    else
    {
        int m=(l+r)/2;
        if(lazy[idx]!=2) push(idx);
        update(2*idx,l,m,ql,min(qr,m),k);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,k);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> tmp={1,n};
    vector<array<int,3>> v(q);
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<3;j++) cin >> v[i][j];
        for(int j=0;j<2;j++) tmp.push_back(v[i][j]);
        v[i][2]--;
    }
    sort(tmp.begin(),tmp.end());
    vector<int> s={tmp[0]};
    for(int i=1;i<(int)tmp.size();i++) if(tmp[i]!=tmp[i-1]) s.push_back(tmp[i]);
    unordered_map<int,int> id;
    id.reserve(1<<15);
    id.max_load_factor(0.25);
    int idx=0;
    int now=s[0];
    id[now]=++idx;
    val[idx]=1;
    for(int i=1;i<(int)s.size();i++)
    {
        if(s[i]-now-1>0) val[++idx]=(s[i]-now-1);
        now=s[i];
        id[now]=++idx;
        val[idx]=1;
    }
    build(1,1,idx);
    for(auto [l,r,k]:v)
    {
        update(1,1,idx,id[l],id[r],k);
        cout << tree[1] << "\n";
    }
    return 0;
}