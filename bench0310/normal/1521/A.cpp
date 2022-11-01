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
        ll a,b;
        cin >> a >> b;
        if(b>1)
        {
            cout << "YES\n";
            cout << a << " " << (2*b-1)*a << " " << 2*a*b << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}