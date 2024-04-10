#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;
const int N=1000000;
vector<ll> tree(4*(N+5),0);

void update(int idx,int l,int r,int pos,ll val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=(tree[2*idx]+tree[2*idx+1])%mod;
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return (query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr))%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    update(1,0,N,0,1);
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin >> a;
        ll x=query(1,0,N,0,a);
        update(1,0,N,a,(a*x)%mod);
    }
    cout << query(1,0,N,1,N) << "\n";
    return 0;
}