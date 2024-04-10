#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j], a[i][j]--;

    int cnt[n * n] = {};
    int kd = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cnt[a[i][j]]++;

            if(cnt[a[i][j]] == 1)
                kd++;
        }

    if(kd <= k)
    {
        cout << k - kd;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        int j = 0, d = 0, cur = kd;

        vector <int> b(n * n);

        for(int p = 0; p < n * n; p++)
            b[p] = cnt[p];

        while(true)
        {
            if(cur == k || cur == k - 1)
            {
                cout << 1;
//                cout << endl << i << ' ' << j << ' ' << d << endl;
//                cout << cur;
                return 0;
            }

            if(cur > k)
            {
                d++;

                if(j + d > n || i + d > n)
                    break;

                for(int p = j; p < j + d; p++)
                {
                    int x = a[i + d - 1][p];
                    b[x]--;

                    if(b[x] == 0)
                        cur--;
                }

                for(int p = i; p < i + d - 1; p++)
                {
                    int x = a[p][j + d - 1];
                    b[x]--;

                    if(b[x] == 0)
                        cur--;
                }
            }
            else
            {
                j++;
                d--;

                for(int p = i; p <= i + d; p++)
                {
                    int x = a[p][j - 1];
                    b[x]++;

                    if(b[x] == 1)
                        cur++;
                }

                for(int p = j; p < j + d; p++)
                {
                    int x = a[i + d][p];
                    b[x]++;

                    if(b[x] == 1)
                        cur++;
                }
            }
        }
    }

    cout << 2;
}