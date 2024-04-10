#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1,0);
    vector<int> d(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> d[i];
    vector<ll> sum(n+2,0);
    for(int i=n;i>=1;i--) sum[i]=sum[i+1]+a[i];
    vector<int> mn(n+1,(1<<30));
    for(int i=1;i<=n;i++) mn[i]=min(mn[i-1],d[i]);
    ll res=0;
    vector<ll> best(n+2,0);
    for(int i=n;i>=1;i--) best[i]=max(best[i+1],sum[i]-d[i]);
    vector<ll> x(n+1,0);
    for(int i=1;i<=n;i++) x[i]=max(x[i-1],sum[i]-d[i]);
    if(k==0) res=best[1];
    else if(k==1)
    {
        for(int i=1;i<n;i++)
        {
            res=max(res,max(0ll,sum[1]-sum[i+1]-mn[i])+best[i+1]);
            res=max(res,x[i]-a[i+1]+max(0,a[i+1]-d[i+1]));
        }
    }
    else res=max({0ll,sum[1]-mn[n-1],(ll)a[n]-d[n]});
    cout << res << "\n";
    return 0;
}