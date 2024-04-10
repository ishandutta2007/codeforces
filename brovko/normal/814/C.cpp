#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, q, m, a[1505][128];
string s;
char c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for(int i = 'a'; i <= 'z'; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int k = 0;
            int z = 0;

            for(int x = j; x < n; x++)
            {
                if(s[x] == i)
                    k++;
                else z++;

                a[z][i] = max(a[z][i], k + z);
            }
        }
    }

    for(int i = 'a'; i <= 'z'; i++)
        for(int z = 1; z <= n; z++)
            a[z][i] = max(a[z][i], a[z - 1][i]);

    cin >> q;
    while(q--)
    {
        cin >> m >> c;
        cout << min(n, a[m][c]) << "\n";
    }
}