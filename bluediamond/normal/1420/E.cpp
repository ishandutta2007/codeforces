#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int f(int x)
{
    return x * (x - 1) / 2;
}

const int N = 80 + 7;
int n;
int y;
int init[N];
int a[N];
int dp[N][N][N * N]; /// dp[pref][sum][steps] = minim sum of f(x)
int kek[N];
int now[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> ones;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> init[i];
        if (init[i] == 1)
        {
            ones.push_back(i);
        }
    }
    int limit = f(n);
    if (ones.empty())
    {
        for (int i = 0; i <= limit; i++)
        {
            cout << 0 << " ";
        }
        cout << "\n";
        return 0;
    }
    a[++y] = ones[0] - 1;
    for (int i = 0; i + 1 < (int) ones.size(); i++)
    {
        a[++y] = ones[i + 1] - ones[i] - 1;
    }
    a[++y] = n - ones.back();
    n = y;
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            kek[++total] = i;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int s = 0; s <= total; s++)
        {
            for (int steps = 0; steps <= limit; steps++)
            {
                dp[i][s][steps] = (int) 1e9;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s <= total; s++)
        {
            for (int j = 1; j <= total; j++)
            {
                if (j > s)
                {
                    now[j] = max(kek[j], i + 1);
                }
            }
            for (int steps = 0; steps <= limit; steps++)
            {
                if (dp[i][s][steps] == (int) 1e9)
                {
                    continue;
                }
                for (int x = 0; x + s <= total; x++)
                {
                    int cost = steps;
                    for (int j = s + 1; j <= s + x; j++)
                    {
                        cost += now[j] - (i + 1);
                    }
                    for (int j = s + x + 1; j <= total; j++)
                    {
                        if (now[j] == i + 1)
                        {
                            cost++;
                        }
                    }
                    dp[i + 1][s + x][cost] = min(dp[i + 1][s + x][cost], dp[i][s][steps] + f(x));
                }
            }
        }
    }
    for (int i = 0; i <= limit; i++)
    {
        if (i)
        {
            dp[n][total][i] = min(dp[n][total][i], dp[n][total][i - 1]);
        }
        cout << f(total) - dp[n][total][i] << " ";
    }
}