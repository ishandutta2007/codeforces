#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=110000;
ll n,m,v[N+5],aux[N+5];
ll add=0,ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    v[1]=0;
    for(ll i=2;i<=n+1;i++)
        cin>>v[i];
    v[n+2]=m;
    n+=2;
    ll poz=n-1;
    while(poz%2)poz--;
    for(ll i=poz;i>=1;i-=2)
    {
        aux[i]=aux[i+2]+v[i+1]-v[i];
    }
    for(ll i=1;i<n;i+=2)
    {
        if(v[i]+1!=v[i+1])
        {
            ans=max(ans,add+v[i+1]-v[i]-1+aux[i+1]);
        }
        add+=v[i+1]-v[i];
        ans=max(ans,add);
        if(i+1<=n && v[i+1]+1!=v[i+2])
        {

            ans=max(ans,add+v[i+2]-v[i+1]-1+aux[i+3]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**

3 10
4 6 7


**/