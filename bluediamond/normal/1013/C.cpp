#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2*100000+5;
int n,sz;
ll v[N];

inline ll d(ll x,ll y)
{
    x=v[x];
    y=v[y];
    return abs(x-y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n; sz=n+n;
    for(int i=1;i<=sz;i++)
        cin>>v[i];
    sort(v+1,v+sz+1);
    ll ans;
    ans=(ll)d(1,n)*d(n+1,sz);
    if(n==1)
    {
        cout<<"0\n";
        return 0;
    }
    for(int st=2;st<=n;st++)
    {
        ans=min(ans,(ll)d(st,st+n-1)*d(1,sz));
    }
    cout<<ans<<"\n";
    return 0;
}
/**
**/