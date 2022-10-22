#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int L = 0, R = 1e9 + 7;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        bitset <1005> b[n];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                b[i][j] = (a[i][j] >= M);

        bool F = 0;

        for(int i = 0; i < n && F == 0; i++)
            for(int j = 0; j < i; j++)
                if((b[i] & b[j]).count() >= 2)
                {
                    F = 1;
                    break;
                }

        if(F)
            L = M;
        else R = M;
    }

    cout << L;
}