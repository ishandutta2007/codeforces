#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string s, t;
int n, a[200][200];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int T, m;
        char x, y;

        cin >> T >> x >> m >> y;

        if(a[x][m] < 2)
        {
            if(y == 'r')
                a[x][m] += 2;
            else a[x][m]++;

            if(a[x][m] >= 2)
                cout << (x == 'h' ? s : t) << ' ' << m << ' ' << T << "\n";
        }
    }
}