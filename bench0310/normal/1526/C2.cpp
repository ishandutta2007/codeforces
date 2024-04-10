#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<ll> tree(4*N,0);
vector<ll> lazy(4*N,0);

void push(int idx)
{
    for(int i=0;i<2;i++)
    {
        tree[2*idx+i]+=lazy[idx];
        lazy[2*idx+i]+=lazy[idx];
    }
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,ll x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]+=x;
        lazy[idx]+=x;
    }
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return (1ll<<60);
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    vector<array<ll,2>> v;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]>=0)
        {
            update(1,1,n,i,n,a[i]);
            res++;
        }
        else v.push_back({-a[i],i});
    }
    sort(v.begin(),v.end());
    for(auto [x,i]:v)
    {
        if(query(1,1,n,i,n)>=x)
        {
            res++;
            update(1,1,n,i,n,-x);
        }
    }
    cout << res << "\n";
    return 0;
}