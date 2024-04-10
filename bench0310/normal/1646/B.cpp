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
        ranges::sort(a);
        ll sl=a[1],sr=0;
        bool ok=0;
        for(int i=1;2*i+1<=n;i++)
        {
            sr+=a[n-i+1];
            sl+=a[i+1];
            ok|=(sl<sr);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}