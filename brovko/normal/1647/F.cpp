#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[500005], dp[500005], dp2[500005], dp3[500005][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int Max = 0;

    for(int i = 0; i < n; i++)
        if(a[i] > a[Max])
            Max = i;

    dp[0] = -2e9;

    for(int i = 1; i < n; i++)
    {
        dp[i] = 2e9;

        if(a[i] > a[i - 1])
            dp[i] = min(dp[i], dp[i - 1]);

        if(a[i] > dp[i - 1])
            dp[i] = min(dp[i], a[i - 1]);
    }

    dp2[n - 1] = -2e9;

    for(int i = n - 2; i >= 0; i--)
    {
        dp2[i] = 2e9;

        if(a[i] > a[i + 1])
            dp2[i] = min(dp2[i], dp2[i + 1]);

        if(a[i] > dp2[i + 1])
            dp2[i] = min(dp2[i], a[i + 1]);
    }

    dp3[Max][0] = dp2[Max];
    dp3[Max][1] = 2e9;

    for(int i = Max - 1; i >= 0; i--)
    {
        dp3[i][0] = 2e9;
        dp3[i][1] = -2e9;

        if(a[i + 1] > a[i])
            dp3[i][0] = min(dp3[i][0], dp3[i + 1][0]);

        if(dp3[i + 1][1] > a[i])
            dp3[i][0] = min(dp3[i][0], a[i + 1]);

        if(a[i + 1] < a[i])
            dp3[i][1] = max(dp3[i][1], dp3[i + 1][1]);

        if(dp3[i + 1][0] < a[i])
            dp3[i][1] = max(dp3[i][1], a[i + 1]);
    }

    dp3[Max][0] = dp[Max];

    for(int i = Max + 1; i < n; i++)
    {
        dp3[i][0] = 2e9;
        dp3[i][1] = -2e9;

        if(a[i - 1] > a[i])
            dp3[i][0] = min(dp3[i][0], dp3[i - 1][0]);

        if(dp3[i - 1][1] > a[i])
            dp3[i][0] = min(dp3[i][0], a[i - 1]);

        if(a[i - 1] < a[i])
            dp3[i][1] = max(dp3[i][1], dp3[i - 1][1]);

        if(dp3[i - 1][0] < a[i])
            dp3[i][1] = max(dp3[i][1], a[i - 1]);
    }

//    for(int i = 0; i < n; i++)
//        cout << dp3[i][0] << ' ';
//
//    cout << endl;
//
//    for(int i = 0; i < n; i++)
//        cout << dp3[i][1] << ' ';
//
//    cout << endl;

    int k = 0;

    for(int i = 0; i < n; i++)
        if(i < Max && dp3[i][1] > dp[i] || i > Max && dp3[i][1] > dp2[i])
            k++;

    cout << k;
}