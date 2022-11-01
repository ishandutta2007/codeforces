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
        int n,k;
        cin >> n >> k;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        ll res=(ll(n)*(n-1)-k*(a[n]|a[n-1]));
        for(int i=n;i>=1;i--)
        {
            for(int j=i-1;j>=1&&ll(i)*j>res;j--)
            {
                res=max(res,ll(i)*j-k*(a[i]|a[j]));
            }
        }
        cout << res << "\n";
    }
    return 0;
}