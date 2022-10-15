#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+7;
int n, t[2][N];

int root(int k, int a)
{
        if (t[k][a]==a)
                return a;
        else
                return t[k][a]=root(k, t[k][a]);
}

void unite(int k, int a, int b)
{
        a=root(k, a);
        b=root(k, b);
        t[k][a]=b;
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n;
        for (int i=1; i<=n; i++)
        {
                t[0][i]=t[1][i]=i;
        }

        int m0, m1;
        cin>>m0>>m1;
        for (int i=1; i<=m0; i++)
        {
                int a, b;
                cin>>a>>b;
                unite(0, a, b);
        }
        for (int i=1; i<=m1; i++)
        {
                int a, b;
                cin>>a>>b;
                unite(1, a, b);
        }

        vector<pair<int, int>> sol;
        for (int i=1; i<=n; i++)
        {
                for (int j=i+1; j<=n; j++)
                {
                        if (root(0, i)!=root(0, j) && root(1, i)!=root(1, j))
                        {
                                unite(0, i, j);
                                unite(1, i, j);
                                sol.push_back({i, j});
                        }
                }
        }

        cout<<(int) sol.size()<<"\n";
        for (auto &it : sol)
        {
                cout<<it.first<<" "<<it.second<<"\n";
        }

        return 0;
}