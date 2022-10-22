#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, p, q;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> q >> s;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            if(i * p + j * q == n)
            {
                int x = 0;
                cout << i + j << "\n";

                for(int y = 0; y < i; y++)
                {
                    for(int z = 0; z < p; z++)
                        cout << s[x++];

                    cout << "\n";
                }

                for(int y = 0; y < j; y++)
                {
                    for(int z = 0; z < q; z++)
                        cout << s[x++];

                    cout << "\n";
                }

                return 0;
            }

    cout << -1;
}