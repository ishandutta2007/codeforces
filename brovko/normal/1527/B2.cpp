#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        int f = 0;

        if(n % 2 != 0 && s[n / 2] == '0')
            f = 1;

        int k = 0;

        for(int i = 0; i < n / 2; i++)
            k += '1' - s[i];

        int F = 0;

        for(int i = 0; i < n; i++)
            if(s[i] != s[n - 1 - i])
                F = 1;

        int c = 0;

        for(int i = 0; i < n; i++)
            c += '1' - s[i];

        if(F == 0)
        {
            if(f == 1)
            {
                if(k == 0)
                    cout << "BOB\n";
                else cout << "ALICE\n";
            }
            else
            {
                cout << "BOB\n";
            }
        }
        else
        {
            if(f == 1 && c == 2)
                cout << "DRAW\n";
            else cout << "ALICE\n";
        }

    }
}