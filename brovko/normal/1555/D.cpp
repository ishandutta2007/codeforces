#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, ps[200005][6];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 6; j++)
            ps[i + 1][j] = ps[i][j];

        if(i % 3 == 0)
        {
            if(s[i] == 'a')
            {
                ps[i + 1][0]++;
                ps[i + 1][1]++;
            }

            if(s[i] == 'b')
            {
                ps[i + 1][2]++;
                ps[i + 1][3]++;
            }

            if(s[i] == 'c')
            {
                ps[i + 1][4]++;
                ps[i + 1][5]++;
            }
        }

        if(i % 3 == 1)
        {
            if(s[i] == 'a')
            {
                ps[i + 1][2]++;
                ps[i + 1][4]++;
            }

            if(s[i] == 'b')
            {
                ps[i + 1][0]++;
                ps[i + 1][5]++;
            }

            if(s[i] == 'c')
            {
                ps[i + 1][1]++;
                ps[i + 1][3]++;
            }
        }

        if(i % 3 == 2)
        {
            if(s[i] == 'a')
            {
                ps[i + 1][3]++;
                ps[i + 1][5]++;
            }

            if(s[i] == 'b')
            {
                ps[i + 1][1]++;
                ps[i + 1][4]++;
            }

            if(s[i] == 'c')
            {
                ps[i + 1][0]++;
                ps[i + 1][2]++;
            }
        }
    }

    while(m--)
    {
        int l, r;
        cin >> l >> r;

        int ans = 0;

        for(int i = 0; i < 6; i++)
            ans = max(ans, ps[r][i] - ps[l - 1][i]);

        cout << r - l + 1 - ans << "\n";
    }
}