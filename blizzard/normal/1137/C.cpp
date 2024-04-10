#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

typedef long long ll;

const int MAXN = 100031;
const int MAXD = 71;
int n, m, d;


vector<int> e[MAXN];
vector<int> rev[MAXN];
bool used[MAXN][MAXD];
int component[MAXN][MAXD];

vector<pair<int, int>> topsort;
int cnt[MAXN * MAXD];
int dp[MAXN * MAXD];

int day;
void dfs1 (int v, int dd)
{
    used[v][dd] = true;
    for (auto p : e[v])
    {
        day = (dd == d - 1) ? 0 : (dd + 1);
        if (!used[p][day])
            dfs1(p, day);
    }
    topsort.emplace_back(v, dd);
}

string open[MAXN];
int comp = 0;
void dfs2 (int v, int dd)
{
    used[v][dd] = true;
    component[v][dd] = comp;
    for (auto p : rev[v])
    {
        day = (dd == 0) ? (d - 1) : (dd - 1);
        if (!used[p][day])
            dfs2(p, day);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//freopen("input.txt", "r", stdin);
    cin >> n >> m >> d;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        e[x].emplace_back(y);
        rev[y].emplace_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> open[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            used[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (!used[i][j])
            {
                dfs1(i, j);
            }
        }
    }
    reverse(topsort.begin(), topsort.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            used[i][j] = false;
        }
    }

    for (auto& p : topsort)
    {
        if (!used[p.first][p.second])
        {
            dfs2(p.first, p.second);
            comp++;
        }
    }

    vector<bool> visited(comp);
    for (int i = 0; i < comp; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < comp; i++)
    {
        cnt[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (open[i][j] == '0') continue;
            int c = component[i][j];
            if (!visited[c])
            {
                visited[c] = true;
                cnt[c]++;
            }
        }

        for (int j = 0; j < d; j++)
        {
            if (open[i][j] == '0') continue;
            visited[component[i][j]] = false;
        }
    }

//    for (int i = 0; i < comp; i++)
//    {
//        cerr << cnt[i] << " ";
//    }
//    cerr << endl;

    reverse(topsort.begin(), topsort.end());
    for (int i = 0; i < comp; i++)
    {
        dp[i] = cnt[i];
    }

//    for (auto& p : topsort)
//    {
//        cerr << p.first << " " << p.second << " ";
//    }
//    cerr << endl;
//    cerr << comp << endl;
//    for (int i = 0; i < comp; i++)
//    {
//        cerr << cnt[i] << " ";
//    }
    for (auto& p : topsort)
    {
        int c = component[p.first][p.second];
//        cerr << p.first<< " " << p.second << " " << c;
        for (auto u : e[p.first])
        {
            int day = (p.second == d - 1) ? 0 : p.second + 1;
            int cnew = component[u][day];
//            cerr << " " << cnew;
            if (cnew != c)
                dp[c] = max(dp[c], dp[cnew] + cnt[c]);
        }
//        cerr << endl;
    }


    cout << dp[component[0][0]];
    return 0;
}