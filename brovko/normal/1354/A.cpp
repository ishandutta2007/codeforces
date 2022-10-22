#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi

using namespace std;

int t, a, b, c, d;

int divide(int x, int y)
{
    return (x+y-1)/y;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d;

        if(b>=a)
            cout << b << "\n";
        else if(d>=c)
            cout << "-1\n";
        else cout << divide(a-b, c-d)*c+b << "\n";
    }
}