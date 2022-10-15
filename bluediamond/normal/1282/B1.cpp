#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, p, k, a[N], dp[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i < k)
            {
                dp[i] = dp[i - 1] + a[i];
            }
            else
            {
                dp[i] = dp[i - k] + a[i];
            }
        }
        bool fo = 0;
        for (int i = n; i >= 1; i--)
        {
            if (dp[i] <= p)
            {
                fo = 1;
                cout << i << "\n";
                break;
            }
        }
        if (fo == 0)
        {
            cout << "0\n";
        }
    }
}