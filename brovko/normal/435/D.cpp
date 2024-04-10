#include <bits/stdc++.h>
#define int long long
//#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, r[405][405], d[405][405], ld[405][405], rd[405][405];
char a[405][405];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
        {
            if(a[i][j] == '1')
                r[i][j] = j;
            else if(j == m - 1)
                r[i][j] = m;
            else r[i][j] = r[i][j + 1];

            if(a[i][j] == '1')
                d[i][j] = i;
            else if(i == n - 1)
                d[i][j] = n;
            else d[i][j] = d[i + 1][j];

            if(a[i][j] == '1')
                ld[i][j] = i;
            else if(i == n - 1 || j == 0)
                ld[i][j] = n;
            else ld[i][j] = ld[i + 1][j - 1];

            if(a[i][j] == '1')
                rd[i][j] = i;
            else if(i == n - 1 || j == m - 1)
                rd[i][j] = n;
            else rd[i][j] = rd[i + 1][j + 1];
        }
//
//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < m; j++)
//            cout << r[i][j] << ' ';
//
//        cout << endl;
//    }

    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 1; k < min(n, m); k++)
            {
                if(i - k >= 0 && j - k >= 0 && j + k < m && r[i - k][j - k] > j + k && rd[i - k][j - k] > i && ld[i - k][j + k] > i)
                    ans++;

                if(i - k >= 0 && i + k < n && j + k < m && rd[i][j] > i + k && ld[i - k][j + k] > i && d[i - k][j + k] > i + k)
                    ans++;

                if(i + k < n && j - k >= 0 && j + k < m && ld[i][j] > i + k && rd[i][j] > i + k && r[i + k][j - k] > j + k)
                    ans++;

                if(i - k >= 0 && i + k < n && j - k >= 0 && ld[i][j] > i + k && rd[i - k][j - k] > i && d[i - k][j - k] > i + k)
                    ans++;

                if(i - k >= 0 && j + k < m && r[i][j] > j + k && d[i - k][j] > i && rd[i - k][j] > i)
                    ans++;

                if(i + k < n && j + k < m && r[i][j] > j + k && d[i][j] > i + k && ld[i][j + k] > i + k)
                    ans++;

                if(i + k < n && j - k >= 0 && d[i][j] > i + k && r[i][j - k] > j && rd[i][j - k] > i + k)
                    ans++;

                if(i - k >= 0 && j - k >= 0 && d[i - k][j] > i && r[i][j - k] > j && ld[i - k][j] > i)
                    ans++;
            }

    cout << ans;
}
/*
4 4
0000
1010
1100
1110

*/