#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int INF = (int) 1e8;

int n, m;
int d[N][N];
int cost = 0;
int deg[N];


bool seen[N];

void dfs(int nod)
{
        seen[nod] = 1;
        for (int nou = 0; nou < n; nou++)
        {
                if (seen[nou] == 0 && d[nou][nod] != INF)
                {
                        dfs(nou);
                }
        }
}

int sol[(1 << N)];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < N; j++)
                {
                        d[i][j] = INF;
                }
        }
        for (int i = 0; i < m; i++)
        {
                int a, b, c;
                cin >> a >> b >> c;
                a--, b--;
                d[a][b] = min(d[a][b], c);
                d[b][a] = d[a][b];
                cost += c;
                deg[a]++;
                deg[b]++;
        }

        dfs(0);
        for (int i = 0; i < n; i++)
        {
                if (seen[i] == 0 && deg[i] > 0)
                {
                        cout << "-1\n";
                        return 0;
                }
        }

        for (int k = 0; k < n; k++)
        {
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < n; j++)
                        {
                                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                        }
                }
        }

        int want = 0;
        for (int i = 0; i < n; i++)
        {
                if (deg[i] & 1)
                {
                      //  cout << " : " << i + 1 << "\n";
                        want += (1 << i);
                }
        }

        for (int i = 0; i < (1 << n); i++)
        {
                sol[i] = INF;
        }

        for (int mask = 0; mask <= want; mask++)
        {
                vector <int> active;
                for (int i = 0; (1 << i) <= mask; i++)
                {
                        if (mask & (1 << i))
                        {
                                active.push_back(i);
                        }
                }
                if ((int) active.size() <= 1)
                {
                        sol[mask] = 0;
                        continue;
                }
                for (auto &cur : active)
                {
                        for (auto &ant : active)
                        {
                                if (cur != ant)
                                {
                                        sol[mask] = min(sol[mask], sol[mask - (1 << cur) - (1 << ant)] + d[cur][ant]);
                                }
                        }
                }
        }

      //  cout << want << "\n";
        cout << sol[want] + cost << "\n";
}