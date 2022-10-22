#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[300005], ps[300005], Min[300005][21], kMin[300005][21];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
        {
            ps[i + 1] = a[i] - ps[i];

            Min[i + 1][1] = ps[i + 1];
            kMin[i + 1][1] = 1;
//            Max[i + 1][1] = ps[i + 1];
        }

        for(int j = 2; j <= 20; j++)
            for(int i = 0; i + (1 << j) <= n + 1; i++)
            {
                if(Min[i][j - 1] == Min[i + (1 << j - 1)][j - 1])
                    kMin[i][j] = kMin[i][j - 1] + kMin[i + (1 << j - 1)][j - 1];
                else
                    if(Min[i][j - 1] < Min[i + (1 << j - 1)][j - 1])
                        kMin[i][j] = kMin[i][j - 1];
                    else
                        kMin[i][j] = kMin[i + (1 << j - 1)][j - 1];

                Min[i][j] = min(Min[i][j - 1], Min[i + (1 << j - 1)][j - 1]);
//                Max[i][j] = max(Max[i][j - 1], Max[i + (1 << j - 1)][j - 1]);
            }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int x = i + 2;

            for(int j = 20; j >= 1; j--)
                if(x + (1 << j) <= n + 1 && Min[x][j] >= ps[i])
                    x += (1 << j);

            while(x <= n && ps[x] >= ps[i])
                x += 2;

            int y = i + 1;

            for(int j = 20; j >= 1; j--)
                if(y + (1 << j) <= n + 1 && Min[y][j] >= -ps[i])
                    y += (1 << j);

            while(y <= n && ps[y] >= -ps[i])
                y += 2;

//            cout << i << ' ' << x << ' ' << y << endl;

            int z = min(x - 1, y - 1);
//            cout << z << endl;

            int x2 = i + 2;

            for(int j = 20; j >= 1; j--)
                if(x2 + (1 << j) <= z)
                {
                    if(Min[x2][j] == ps[i])
                        ans += kMin[x2][j];

                    x2 += (1 << j);
                }

            while(x2 <= z)
            {
                if(ps[x2] == ps[i])
                    ans++;

                x2 += 2;
            }

            int y2 = i + 1;

            for(int j = 20; j >= 1; j--)
                if(y2 + (1 << j) <= z)
                {
                    if(Min[y2][j] == -ps[i])
                        ans += kMin[y2][j];

                    y2 += (1 << j);
                }

            while(y2 <= z)
            {
                if(ps[y2] == -ps[i])
                    ans++;

                y2 += 2;
            }
        }

        cout << ans << "\n";
    }
}

/*
1
2
2 2

*/