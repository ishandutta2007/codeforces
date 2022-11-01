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
        int n,x;
        cin >> n >> x;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        bool ok=1;
        for(int i=n;i>=1;i--)
        {
            int b;
            cin >> b;
            ok&=(a[i]+b<=x);
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}