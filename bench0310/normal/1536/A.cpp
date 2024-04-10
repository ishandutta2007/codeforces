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
        bool ok=1;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            mx=max(mx,a);
            ok&=(a>=0);
        }
        if(ok)
        {
            cout << "YES\n";
            cout << mx+1 << "\n";
            for(int i=0;i<=mx;i++) cout << i << " \n"[i==mx];
        }
        else cout << "NO\n";
    }
    return 0;
}