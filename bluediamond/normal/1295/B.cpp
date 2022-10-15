#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int x;
int p[N];

int solve()
{
        if (p[n] == 0)
        {
                for (int i = 0; i <= n; i++)
                        if (p[i] == x)
                                return -1;
                return 0;
        }
        int sol = (x == 0);
        for (int i = 1; i <= n; i++)
        {
                int val = x - p[i];
                if (val % p[n] == 0 && val / p[n] >= 0)
                {
                        sol++;
                }
        }
        return sol;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

       // freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--)
        {
                string s;
                cin >> n >> x >> s;
                for (int i = 1; i <= n; i++)
                        if (s[i - 1] == '0')
                                p[i] = p[i - 1] + 1;
                        else
                                p[i] = p[i - 1] - 1;
                /// i * p[n] + p[i] = x
                /// i * p[n] = x - p[i]
                /// i = (x - p[i]) / p[n]
                cout << solve() << "\n";
        }
}