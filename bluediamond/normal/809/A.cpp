#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=300000+5;
const ll MOD=1000000007;

int n,v[N];
ll p2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    p2[0]=1;
    for(int i=1;i<N;i++) p2[i]=(p2[i-1]*2)%MOD;
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v+1,v+n+1);
    ll scd=0LL;
    ll add=0LL;
    ll ans=0LL;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            scd*=2; scd%=MOD;
            scd+=v[i]; scd%=MOD;
            continue;
        }
        add=v[i]*(p2[i-1]-1)%MOD-scd;
        add%=MOD; add+=MOD; add%=MOD;
        ans+=add; ans%=MOD;
       /// cout<<scd<<" ";
        scd*=2; scd%=MOD;
        scd+=v[i]; scd%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}