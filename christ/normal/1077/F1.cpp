#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

vector<int> a(MAXN);
vector<deque<pair<long long, int>>> buf(MAXN);

int main()
{
    int n, k, x;
    scanf("%i%i%i", &n, &k, &x);
    for (int y = 0; y < n; y++)
        scanf("%i", &a[y]);
    buf[0].push_back({0ll, -1});
    for (int y = 0; y < n; y++)
    {
        for (int z = x; z >= 1; z--)
        {
            if (!buf[z - 1].empty())
            {
                auto p = buf[z - 1].front();
                if (p.second < y - k)
                    buf[z - 1].pop_front();
                if (!buf[z - 1].empty())
                {
                    p = buf[z - 1].front();
                    long long nval = p.first + a[y];
                    while (!buf[z].empty() && buf[z].back().first <= nval)
                        buf[z].pop_back();
                    buf[z].push_back({p.first + a[y], y});
                }
            }
        }
    }
    long long ans = -1;
    if (!buf[x].empty())
    {
        while (!buf[x].empty() && buf[x].front().second < n - k)
            buf[x].pop_front();
        if (!buf[x].empty())
            ans = buf[x].front().first;
    }
    printf("%lli\n", ans);
}