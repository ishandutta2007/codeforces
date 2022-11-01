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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<ll> s(n+2,0);
        for(int i=n;i>=1;i--) s[i]=a[i]+s[min(n+1,i+a[i])];
        ll res=0;
        for(int i=1;i<=n;i++) res=max(res,s[i]);
        cout << res << "\n";
    }
    return 0;
}