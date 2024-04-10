#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

mt19937 rnd(time(NULL));

int f(int x)
{
    if(x == 0)
        return 0;

    return x % 2 + f(x / 2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    char a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = 0;
    string s;

    for(int i = 0; i < m; i++)
        s += "0";

    for(int q = 0; q < 100; q++)
    {

        int z = rnd() % n;

        vector <int> v;

        for(int i = 0; i < m; i++)
            if(a[z][i] == '1')
                v.pb(i);

        int k = v.size();

        int b[1 << k];

        for(int i = 0; i < (1 << k); i++)
            b[i] = 0;

        for(int i = 0; i < n; i++)
        {
            int mask = 0;

            for(int j = 0; j < v.size(); j++)
                if(a[i][v[j]] == '1')
                    mask += (1 << j);

            b[mask]++;
        }

        int mask = 0;

        for(int i = 0; i < (1 << k); i++)
        {
            int y = 0;

            for(int x = i; x < (1 << k); x = ((x + 1) | i))
                y += b[x];

            if(y >= (n + 1) / 2 && f(i) > f(mask))
            {
                mask = i;
            }
        }

//        cout << mask << endl;

        if(f(mask) > f(ans))
        {
            ans = mask;

            for(int i = 0; i < m; i++)
                s[i] = '0';

            for(int i = 0; i < k; i++)
                if(mask & (1 << i))
                    s[v[i]] = '1';
        }
    }

    cout << s;
}