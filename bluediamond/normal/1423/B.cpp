#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;

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

int n;
int m;
const int M=(int)1e4+7;

struct T
{
        int x;
        int y;
        int d;
};

vector<T> v;

bool ok(int t)
{
        flow f(2+2*n);
        for (int i=1;i<=n;i++)
                f.add(1,i+1,1),
                f.add(1+n+i,2+2*n,1);
        for (auto &it : v)
                if (it.d<=t)
                        f.add(1+it.x,1+n+it.y,1);
        return f.get()==n;
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

       // freopen ("input","r",stdin);

        cin>>n>>m;
        v.resize(m);
        for (int i=0;i<m;i++)
                cin>>v[i].x>>v[i].y>>v[i].d;
        int l=0,r=(int) 1e9,sol=-1;
        while (l<=r)
        {
                int m=(l+r)/2;
                if (ok(m))
                {
                        sol=m;
                        r=m-1;
                }
                else
                        l=m+1;
        }
        cout<<sol<<"\n";

}