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
        ll res=0;
        for(int i=1;i<n;i++) res=max(res,a[i]*a[i+1]);
        cout << res << "\n";
    }
    return 0;
}