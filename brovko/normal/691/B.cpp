#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

string s;

int f(char x, char y)
{
    return (x == 'A' && y == 'A' || x == 'H' && y == 'H' || x == 'I' && y == 'I' || x == 'M' && y == 'M' || x == 'O' && y == 'O' || x == 'T' && y == 'T' || x == 'U' && y == 'U' || x == 'V' && y == 'V' || x == 'W' && y == 'W' || x == 'X' && y == 'X' || x == 'Y' && y == 'Y' || x == 'b' && y == 'd' || x == 'd' && y == 'b' || x == 'o' && y == 'o' || x == 'p' && y == 'q' || x == 'q' && y == 'p' || x == 'v' && y == 'v' || x == 'w' && y == 'w' || x == 'x' && y == 'x');
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        if(f(s[i], s[n - i - 1]) == 0)
        {
            cout << "NIE";
            return 0;
        }
    }

    cout << "TAK";
}