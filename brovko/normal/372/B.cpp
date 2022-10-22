#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, q, k[45][45], ps[45][45], ps2[45][45][45][45];
bool good[45][45][45][45];
char a[45][45];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + a[i][j] - '0';

    for(int A = 0; A < n; A++)
        for(int B = 0; B < m; B++)
            for(int C = A; C < n; C++)
                for(int D = B; D < m; D++)
                    good[A][B][C][D] = (ps[C + 1][D + 1] - ps[A][D + 1] - ps[C + 1][B] + ps[A][B] == 0);

    for(int A = 0; A < n; A++)
        for(int B = 0; B < m; B++)
            for(int C = 0; C < n; C++)
                for(int D = 0; D < m; D++)
                {
                    for(int mask = 0; mask < 15; mask++)
                    {
                        int a1 = A, b1 = B, c1 = C, d1 = D;

                        if(mask & 1)
                            a1++;

                        if(mask & 2)
                            b1++;

                        if(mask & 4)
                            c1++;

                        if(mask & 8)
                            d1++;

                        ps2[A + 1][B + 1][C + 1][D + 1] += ps2[a1][b1][c1][d1] * (__builtin_popcount(mask) % 2 == 0 ? -1 : 1);
                    }

                    ps2[A + 1][B + 1][C + 1][D + 1] += good[A][B][C][D];

//                    cout << A + 1 << ' ' << B + 1 << ' ' << C + 1 << ' ' << D + 1 << ' ' << ps2[A + 1][B + 1][C + 1][D + 1] << ' ' << good[A][B][C][D] << endl;
                }

    while(q--)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        A--;
        B--;

        int ans = 0;

        for(int mask = 0; mask < 16; mask++)
        {
            int a1 = A, b1 = B, c1 = A, d1 = B;

            if(mask & 1)
                a1 = C;

            if(mask & 2)
                b1 = D;

            if(mask & 4)
                c1 = C;

            if(mask & 8)
                d1 = D;

            ans += ps2[a1][b1][c1][d1] * (__builtin_popcount(mask) % 2 == 0 ? 1 : -1);
        }

        cout << ans << "\n";
    }
}