#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int dp[MAXN]; 

vector<int> umb(MAXN, INT_MAX);

int main()
{
    int a, n, m;
    scanf("%i%i%i", &a, &n, &m);
    deque<pair<int,int>> arr(n);
    for (auto &x : arr)
        scanf("%i%i", &x.first, &x.second);
    sort(arr.begin(), arr.end());
    while (m--)
    {
        int b, c;
        scanf("%i%i", &b, &c);
        umb[b] = min(umb[b], c);
    }
    int right_bound = -1;
    for (int x = 0; x <= a; x++)
    {
        if (right_bound < x)
            right_bound = -1;
        while (!arr.empty() && arr.front().first < x)
            right_bound = arr.front().second, arr.pop_front();
        bool need_umbrella = right_bound >= 0;
        if (!need_umbrella)
            dp[x] = (x ? dp[x-1] : 0);
        else
            dp[x] = (x ? INT_MAX : 0);
        for (int y = 0; y < x; y++)
        {
            if (umb[y] == INT_MAX || dp[y] == INT_MAX)
                continue;
            dp[x] = min(dp[x], dp[y] + umb[y] * (x - y));
        }
    }
    printf("%i\n", dp[a] == INT_MAX ? -1 : dp[a]);
}