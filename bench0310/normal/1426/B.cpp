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
        int n,m;
        cin >> n >> m;
        bool ok=0;
        for(int i=0;i<n;i++)
        {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            ok|=(b==c);
        }
        if(m&1) ok=0;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}