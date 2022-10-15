#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;

int n;
int cnt[N], cost[N];
int dist[N];

bool seen[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;

                queue <int> q;
                q.push(x);
                seen[x] = 1;
                vector <int> cur;

                while (!q.empty())
                {
                        x = q.front();
                        cnt[x]++;
                        q.pop();
                        cur.push_back(x);
                        if (2 * x < N && seen[2 * x] == 0)
                        {
                                dist[2 * x] = 1 + dist[x];
                                seen[2 * x] = 1;
                                q.push(2 * x);

                        }
                        if (seen[x / 2] == 0)
                        {
                                dist[x / 2] = 1 + dist[x];
                                seen[x / 2] = 1;
                                q.push(x / 2);
                        }
                }

                for (auto &it : cur)
                {
                        cost[it] += dist[it];
                        seen[it] = 0;
                        dist[it] = 0;
                }

        }

        int res = (1 << 30);

        for (int i = 1; i < N; i++)
        {
                if (cnt[i] == n)
                {
                        res = min(res, cost[i]);
                }
        }
        cout << res << "\n";

        return 0;
}