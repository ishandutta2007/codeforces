#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        char a[2][n];

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];

        int dpl[2][n], dpr[2][n];

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                dpl[0][i] = 0;
                dpl[1][i] = 0;
            }
            else
            {
                dpl[0][i] = min(dpl[0][i - 1] + (a[1][i - 1] == '*') + 1, dpl[1][i - 1] + 2);
                dpl[1][i] = min(dpl[0][i - 1] + 2, dpl[1][i - 1] + (a[0][i - 1] == '*') + 1);
            }
        }

        for(int i = n - 1; i >= 0; i--)
        {
            if(i == n - 1)
            {
                dpr[0][i] = 0;
                dpr[1][i] = 0;
            }
            else
            {
                dpr[0][i] = min(dpr[0][i + 1] + (a[1][i + 1] == '*') + 1, dpr[1][i + 1] + 2);
                dpr[1][i] = min(dpr[0][i + 1] + 2, dpr[1][i + 1] + (a[0][i + 1] == '*') + 1);
            }
        }

        int Max = 0, Min = 1e9;

        for(int i = 0; i < n; i++)
            if(a[0][i] == '*' || a[1][i] == '*')
                Max = i, Min = min(Min, i);

        int ans = min(dpl[0][Max] + (a[1][Max] == '*'), dpl[1][Max] + (a[0][Max] == '*')) - Min;

        cout << ans << "\n";
    }
}