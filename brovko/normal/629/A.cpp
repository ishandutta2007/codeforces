#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n;
char a[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == 'C')
    {
        for(int k = 0; k < i; k++)
            if(a[k][j] == 'C')
                ans++;

        for(int k = 0; k < j; k++)
            if(a[i][k] == 'C')
                ans++;
    }

    cout << ans;
}