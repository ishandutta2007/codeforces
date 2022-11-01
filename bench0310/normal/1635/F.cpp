#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
vector<array<ll,2>> tree[4*N];

void add(int idx,int l,int r,int pos,array<ll,2> a)
{
    if(tree[idx].empty()||tree[idx].back()[1]>a[1]) tree[idx].push_back(a);
    if(l<r)
    {
        int m=(l+r)/2;
        if(pos<=m) add(2*idx,l,m,pos,a);
        else add(2*idx+1,m+1,r,pos,a);
    }
}

ll query(int idx,int l,int r,int ql,int qr,int lim)
{
    if(ql>qr) return (1ll<<60);
    if(l==ql&&r==qr)
    {
        auto it=ranges::lower_bound(tree[idx],array<ll,2>{lim+1,0});
        if(it!=tree[idx].begin()) return (*prev(it))[1];
        else return (1ll<<60);
    }
    else
    {
        int m=(l+r)/2;
        return min(query(2*idx,l,m,ql,min(qr,m),lim),query(2*idx+1,m+1,r,max(ql,m+1),qr,lim));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<ll> x(n+1,0);
    vector<ll> w(n+1,0);
    for(int i=1;i<=n;i++) cin >> x[i] >> w[i];
    auto d=[&](int i,int j)->ll{return ((x[j]-x[i])*(w[i]+w[j]));};
    vector<array<int,2>> opt;
    stack<int> s;
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&w[i]<w[s.top()]) s.pop();
        if(!s.empty()) opt.push_back({i,s.top()});
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&w[i]<w[s.top()]) s.pop();
        if(!s.empty()) opt.push_back({s.top(),i});
        s.push(i);
    }
    ranges::sort(opt,[&](const auto &a,const auto &b){return (a[1]<b[1]);});
    for(auto [l,r]:opt) add(1,1,n,l,{r,d(l,r)});
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << query(1,1,n,l,r,r) << "\n";
    }
    return 0;
}