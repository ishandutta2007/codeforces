#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    if(n == 0)
    {
        cout << "O-|-OOOO";
        return 0;
    }

    while(n > 0)
    {
        int x = n % 10;

        if(x >= 5)
            cout << "-O|";
        else cout << "O-|";

        x %= 5;

        for(int i = 0; i < x; i++)
            cout << "O";

        cout << "-";

        for(int i = 0; i < 4 - x; i++)
            cout << "O";

        cout << "\n";

        n /= 10;
    }
}