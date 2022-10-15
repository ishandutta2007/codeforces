#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int) 1e5+7;
int n, m0, m1, t[N], eg[N];
set<int> c;

int root(int a)
{
        if (t[a]==a)
                return a;
        else
                return t[a]=root(t[a]);
}

void unite(int a, int b)
{
        a=root(a);
        b=root(b);

        assert(a!=b);


        c.erase(b);
        t[b]=a;
}

bool vis[N];
vector<int> g[N], kek;

set<int> guys;
int some[N];

void dfs(int i)
{
        vis[i]=1;
        kek.push_back(i);
        guys.insert(root(i));
        some[root(i)]=i;

        for (auto &j : g[i])
                if (!vis[j])
                        dfs(j);
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);


        cin>>n>>m0>>m1;
        for (int i=1; i<=n; i++)
        {
                t[i]=i;
        }

        for (int i=1; i<=m0; i++)
        {
                int a, b;
                cin>>a>>b;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        for (int i=1; i<=m1; i++)
        {
                int a, b;
                cin>>a>>b;
                unite(a, b);
        }

        vector<pair<int, int>> sol;

        for (int r=1; r<=n; r++)
        {
                if (vis[r]) continue;
                guys.clear();
                kek.clear();
                dfs(r);
                bool found=0;
                for (auto &x : guys)
                {
                        for (auto &y : c)
                        {
                                if (x==y)
                                {
                                        continue;
                                }
                                int i=some[x];
                                int j=eg[y];

                                assert(root(i)==x);
                                assert(root(j)==y);


                                assert(root(i) != root(j));

                                unite(i, j);

                                sol.push_back({i, j});
                                found=1;

                                if (found) break;
                        }
                        if (found) break;
                }

                for (auto &i : kek)
                {
                        eg[root(i)]=i;
                        c.insert(root(i));
                }
        }
        cout<<(int) sol.size()<<"\n";
        for (auto &it : sol)
        {
                cout<<it.first<<" " <<it.second<<"\n";
        }

        return 0;
}