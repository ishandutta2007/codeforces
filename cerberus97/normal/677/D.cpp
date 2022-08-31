#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair <int, int> pii;

const int N = 305, N2 = N*N, INF = 1e9;
const int neighbor[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector <pii> a[N2];
set <pair <int, pii>> temp;
queue <pii> q;
int dp[N][N], dist[N][N];

void fill(int n, int m, int val);

int main()
{
    int n, m, p, x;
    cin >> n >> m >> p;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            a[x].push_back(make_pair(i, j));
        }
    }

    for (auto &i : a[1])
    {
        dp[i.x][i.y] = i.x + i.y;
    }

    for (int i = 2; i <= p; ++i)
    {     
        if (a[i].size()*a[i-1].size() <= size_t(n*m))
        {
            for (auto &j : a[i])
            {
                dp[j.x][j.y] = INF;
                for (auto &k : a[i-1])
                {   
                    ll path = abs(j.x - k.x) + abs(j.y - k.y);
                    if (dp[k.x][k.y] + path < dp[j.x][j.y])
                        dp[j.x][j.y] = dp[k.x][k.y] + path;
                }
            }
        }

        else
        {
            fill(n, m, -1);
            temp.clear();
            for (auto &j : a[i-1])
                temp.insert({dp[j.first][j.second], {j.first, j.second}});

            auto st = *(temp.begin());
            temp.erase(temp.begin());
            q.push(st.second);
            dist[st.second.x][st.second.y] = st.first;
            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                int cur_distance = dist[cur.x][cur.y];

                while (!temp.empty() and temp.begin()->first <= cur_distance+1)
                {
                    st = *(temp.begin());
                    temp.erase(temp.begin());
                    q.push(st.second);
                    dist[st.second.x][st.second.y] = st.first;
                }

                for (int k = 0; k < 4; ++k)
                {
                    int x_n = cur.x + neighbor[k][0], y_n = cur.y + neighbor[k][1];

                    if (x_n < 0 or x_n > n or y_n < 0 or y_n > m)
                        continue;

                    if (dist[x_n][y_n] == -1)
                    {
                        dist[x_n][y_n] = cur_distance + 1;
                        q.push({x_n, y_n});
                    }
                }
            }

            for (auto &j : a[i])
                dp[j.x][j.y] = dist[j.x][j.y];
        }
    }
    auto dest = a[p][0];
    cout << dp[dest.x][dest.y];
}

void fill(int n, int m, int val)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j] = val;
}