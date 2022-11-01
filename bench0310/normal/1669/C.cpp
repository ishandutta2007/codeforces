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
        bool ok=1;
        for(int i=3;i<=n;i+=2) ok&=(((a[i]-a[1])%2)==0);
        for(int i=2;i<=n;i+=2) ok&=(((a[i]-a[2])%2)==0);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}