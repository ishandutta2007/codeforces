#include <algorithm>
#include <cstdio>
#include <cstring>

struct el
{
    int x, y, t;
    double p;
    bool operator<(const el& e) const
    {
        return t < e.t;
    }
};

int n;
el e[1024];

double dp[1024];

bool can_reach(int s, int t)
{
    long long dt = e[t].t - e[s].t;
    dt = dt * dt;
    return dt >= (e[s].x - e[t].x) * (e[s].x - e[t].x) + (e[s].y - e[t].y) * (e[s].y - e[t].y);
}

double getDP(int a)
{
    if (dp[a] == dp[a])
        return dp[a];
    if (a == n)
        return 0.0;
    dp[a] = e[a].p;
    for (int i = a + 1; i < n; ++i)
    {
        if (can_reach(a, i))
        {
            dp[a] = std::max(e[a].p + getDP(i), dp[a]);
        }
    }
    return dp[a];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d %lf", &e[i].x, &e[i].y, &e[i].t, &e[i].p);
    }
    std::sort(e, e + n);

    memset(dp, -1, sizeof(dp));
    double mx = 0.0;
    for (int i = 0; i < n; ++i)
    {
        mx = std::max(mx, getDP(i));
    }

    printf("%.10lf\n", mx);

    return 0;
}