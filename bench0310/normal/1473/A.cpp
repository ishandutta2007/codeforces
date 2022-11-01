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
        int n,d;
        cin >> n >> d;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        ranges::sort(a);
        bool ok=1;
        for(int i=1;i<=n;i++) ok&=(min(a[i],a[1]+a[2])<=d);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}