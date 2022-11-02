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
        vector<int> mx(n+1,0);
        for(int i=1;i<=n;i++) mx[i]=max(mx[i-1],a[i]);
        vector<int> mn(n+2,(1<<30));
        for(int i=n;i>=1;i--) mn[i]=min(mn[i+1],a[i]);
        bool ok=0;
        for(int i=1;i<n;i++) ok|=(mx[i]>mn[i+1]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}