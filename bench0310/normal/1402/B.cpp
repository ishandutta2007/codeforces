#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin()+1,a.end());
        vector<ll> sum(n+1,0);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        double res=-1e18;
        for(int i=1;i<=n;i++)
        {
            int j=n-i;
            res=max(res,double(sum[i])/i+double(sum[n]-sum[i])/j);
        }
        cout << fixed << setprecision(9) << res << "\n";
    }
    return 0;
}