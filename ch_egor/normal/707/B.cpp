#include <bits/stdc++.h>

typedef long long int ll;
typedef long double ld;

using namespace std;

const int MAX_N = 1000 * 100 + 5;
const int INF = (1ll << 31) - 1;

int n, m, k;
vector<pair<int, int>> graph[MAX_N];
bool good[MAX_N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    int v, u, l;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &v, &u, &l);
        graph[v].push_back(make_pair(u, l));
        graph[u].push_back(make_pair(v, l));
    }

    memset(good, 0, sizeof(good));

    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &v);
        good[v] = true;
    }

    int answer = INF;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < graph[i].size(); ++j)
        {
            if (good[i] && !good[graph[i][j].first])
            {
                answer = min(answer, graph[i][j].second);
            }
        }
    }

    printf("%d", answer == INF ? -1 : answer);

    fclose(stdin);
    fclose(stdout);

    return 0;
}