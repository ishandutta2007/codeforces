#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int f[70];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector <ll> a;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x > 0)
        {
            a.push_back(x);
        }
    }

    n = (int) a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; (1LL << j) <= a[i]; j++)
        {
            if (a[i] & (1LL << j))
            {
                f[j]++;
                if (f[j] == 3)
                {
                    cout << "3\n";
                    return 0;
                }
            }
        }
    }

    vector <vector <int>> g(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] & a[j])
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int ans = (1 << 30);

    for (int i = 0; i < n; i++)
    {
        for (auto &j : g[i])
        {
            if (j > i)
            {
                /// sterg i, j
                vector <int> dist(n);
                for (int k = 0; k < n; k++)
                {
                    dist[k] = -1;
                }
                dist[i] = 0;
                queue <int> q;
                q.push(i);
                while (!q.empty() && dist[j] == -1)
                {
                    auto nod = q.front();
                    q.pop();
                    for (auto &nou : g[nod])
                    {
                        if (dist[nou] == -1)
                        {
                            if (min(nod, nou) == min(i, j) && max(nod, nou) == max(i, j)) continue;
                            dist[nou] = 1 + dist[nod];
                            q.push(nou);
                        }
                    }
                }
                if (dist[j] != -1)
                {
                    ans = min(ans, dist[j] + 1);
                }
            }
        }
    }

    if (ans == (1 << 30))
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }

}