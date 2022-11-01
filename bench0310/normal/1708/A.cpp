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
        int a;
        cin >> a;
        bool ok=1;
        for(int i=2;i<=n;i++)
        {
            int b;
            cin >> b;
            ok&=((b%a)==0);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}