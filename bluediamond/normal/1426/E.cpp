#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 2e9;

struct flow
{
    int n;
    vector<pair<int, int>> edges;
    vector<vector<int>> g;
    vector<int> level;
    vector<int> pos;
    flow(int nn)
    {
        n = nn;
        pos.resize(n + 1);
        level.resize(n + 1);
        g.resize(n + 1);
        edges.clear();
    }
    void add(int a, int b, int c)
    {
        g[a].push_back((int) edges.size());
        g[b].push_back((int) edges.size() + 1);
        edges.push_back({b, c});
        edges.push_back({a, 0});
    }
    int dfs(int a, int pre)
    {
        if (a == n || pre == 0)
        {
            return pre;
        }
        while (pos[a] < (int) g[a].size())
        {
            int i = g[a][pos[a]];
            int b = edges[i].first;
            int c = edges[i].second;
            pos[a]++;
            if (c == 0 || level[b] != level[a] + 1)
            {
                continue;
            }
            int total = dfs(b, min(pre, c));
            if (total)
            {
                edges[i].second -= total;
                edges[i ^ 1].second += total;
                return total;
            }
        }
        return 0;
    }
    int get()
    {
        int sol = 0;
        while (1)
        {
            for (int i = 1; i <= n; i++)
            {
                level[i] = -1;
                pos[i] = 0;
            }
            level[1] = 0;
            queue<int> q;
            q.push(1);
            while (!q.empty())
            {
                int a = q.front();
                q.pop();
                for (auto &i : g[a])
                {
                    int b = edges[i].first;
                    int c = edges[i].second;
                    if (c && level[b] == -1)
                    {
                        level[b] = 1 + level[a];
                        q.push(b);
                    }
                }
            }
            if (level[n] == -1)
            {
                break;
            }
            while (1)
            {
                int x = dfs(1, INF);
                if (x)
                {
                    sol += x;
                }
                else
                {
                    break;
                }
            }
        }
        return sol;
    }
};


int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        /// 1 > 2
        /// 2 > 3
        /// 3 > 1
        int n,a1,a2,a3,b1,b2,b3;
        cin>>n>>a1>>a2>>a3>>b1>>b2>>b3;
        flow f(8);
        f.add(1,2,a1);
        f.add(1,3,a2);
        f.add(1,4,a3);
        f.add(5,8,b1);
        f.add(6,8,b2);
        f.add(7,8,b3);

        f.add(2,5,INF);
        f.add(2,7,INF);

        f.add(3,5,INF);
        f.add(3,6,INF);

        f.add(4,6,INF);
        f.add(4,7,INF);

        /// 2  5
        /// 3  6
        /// 4  7
        cout<<n-f.get()<<" "<<min(a1,b2)+min(a2,b3)+min(a3,b1)<<"\n";
}