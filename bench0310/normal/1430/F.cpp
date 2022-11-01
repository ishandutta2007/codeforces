#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> l(n);
    vector<ll> r(n);
    vector<ll> a(n);
    vector<ll> req(n);
    for(int i=0;i<n;i++)
    {
        cin >> l[i] >> r[i] >> a[i];
        req[i]=max(0ll,a[i]-(r[i]-l[i])*k);
    }
    const ll inf=(1ll<<60);
    vector<ll> dp(n,inf);
    ll sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum+=a[i];
        ll now=k;
        bool ok=1;
        for(int j=i;j<n;j++)
        {
            if(i!=j&&r[j-1]!=l[j]) dp[i]=min(dp[i],now+dp[j]);
            if(now<req[j])
            {
                ok=0;
                break;
            }
            if(j<n-1&&r[j]==l[j+1]&&l[j]<r[j]&&now+(r[j]-l[j]-1)*k>=a[j]) dp[i]=min(dp[i],((now-a[j])%k+k)%k+dp[j+1]);
            now=((now-a[j])%k+k)%k;
        }
        if(ok) dp[i]=0;
    }
    if(dp[0]!=inf) cout << sum+dp[0] << "\n";
    else cout << "-1\n";
    return 0;
}