#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<array<int,3>> tree[4*N]; //[1,r,val] or [2,r,id]

void add_update(int idx,int l,int r,int pos,array<int,3> a)
{
    tree[idx].push_back(a);
    if(l<r)
    {
        int m=(l+r)/2;
        if(pos<=m) add_update(2*idx,l,m,pos,a);
        else add_update(2*idx+1,m+1,r,pos,a);
    }
}

void add_query(int idx,int l,int r,int ql,int qr,array<int,3> a)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) tree[idx].push_back(a);
    else
    {
        int m=(l+r)/2;
        add_query(2*idx,l,m,ql,min(qr,m),a);
        add_query(2*idx+1,m+1,r,max(ql,m+1),qr,a);
    }
}

vector<ll> res(N,0);
vector<ll> bit(N,0);

void add(int x,ll d)
{
    for(;x<N;x=x|(x+1)) bit[x]+=d;
}

ll sum(int x)
{
    ll r=0;
    for(;x>=0;x=(x&(x+1))-1) r+=bit[x];
    return r;
}

void solve(int idx,int l,int r)
{
    for(auto [t,lim,x]:tree[idx])
    {
        if(t==1) add(lim,x);
        else res[x]+=sum(lim);
    }
    for(auto [t,lim,x]:tree[idx]) if(t==1) add(lim,-x);
    if(l<r)
    {
        int m=(l+r)/2;
        solve(2*idx,l,m);
        solve(2*idx+1,m+1,r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1,0);
    vector<set<int>> s(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s[a[i]].insert(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i].empty()) continue;
        for(auto it=s[i].begin();next(it)!=s[i].end();it++) add_update(1,1,n,*it,{1,*next(it),(*next(it))-(*it)});
    }
    auto prv=[&](int i,int x)->int
    {
        auto it=s[i].lower_bound(x);
        if(it==s[i].begin()) return -1;
        else return (*prev(it));
    };
    auto nxt=[&](int i,int x)->int
    {
        auto it=s[i].upper_bound(x);
        if(it==s[i].end()) return -1;
        else return (*it);
    };
    int q=0;
    auto go=[&](int i,int d)
    {
        int l=prv(a[i],i);
        int r=nxt(a[i],i);
        if(l!=-1) add_update(1,1,n,l,{1,i,d*(i-l)});
        if(r!=-1) add_update(1,1,n,i,{1,r,d*(r-i)});
        if(l!=-1&&r!=-1) add_update(1,1,n,l,{1,r,-d*(r-l)});
    };
    for(int i=1;i<=m;i++)
    {
        int t,l,r;
        cin >> t >> l >> r;
        if(t==1)
        {
            go(l,-1);
            s[a[l]].erase(l);
            a[l]=r;
            s[a[l]].insert(l);
            go(l,1);
        }
        else add_query(1,1,n,l,r,{2,r,++q});
    }
    solve(1,1,n);
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}