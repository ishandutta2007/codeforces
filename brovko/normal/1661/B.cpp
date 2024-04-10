#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, ans[32768];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 32768; i++)
    {
        int x = i;

        while(x)
        {
            x = x * 2 % 32768;
            ans[i]++;
        }
    }

    for(int i = 32767; i >= 0; i--)
        ans[i] = min(ans[i], ans[(i + 1) % 32768] + 1);

    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;

        cout << ans[x] << ' ';
    }
}