#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;

int n, m;

struct road
{
        int no;
        int co;
        int id;
};

vector <road> g[N];

bool seen[N];

vector <int> kek;

void dfs(int nod, int val)
{
        seen[nod] = 1;
        for (auto &it : g[nod])
        {
                if (seen[it.no] == 0 && it.co > val)
                {
                        dfs(it.no, val);
                }
        }
        kek.push_back(nod);
}

int when[N];

bool test(int val)
{
        kek.clear();
        for (int i = 1; i <= n; i++)
        {
                seen[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
                if (seen[i] == 0)
                {
                        dfs(i, val);
                }
        }
        reverse(kek.begin(), kek.end());
        for (int i = 0; i < kek.size(); i++)
        {
                when[kek[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
                for (auto &it : g[i])
                {
                        if (it.co > val && when[it.no] < when[i])
                        {
                                return false;
                        }
                }
        }
        return true;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     //   freopen ("stress_test", "r", stdin);
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
                int a, b, d;
                cin >> a >> b >> d;
                g[a].push_back({b, d, i});
        }
        int res = 0;
        int m;
        int l = 0;
        int r = (int) 1e9 + 7;
        while (l <= r)
        {
                m = (l + r) >> 1;
                if (test(m))
                {
                        res = m;
                        r = m - 1;
                }
                else
                {
                        l = m + 1;
                }
        }
        test(res);
        vector <int> ids;
        for (int i = 0; i < kek.size(); i++)
        {
                for (auto &it : g[kek[i]])
                {
                        if (when[it.no] < i)
                        {
                                ids.push_back(it.id);
                        }
                }
        }
        sort(ids.begin(), ids.end());
        cout << res << " " << ids.size() << "\n";
        for (auto &it : ids)
        {
                cout << it << " ";
        }
        cout << "\n";
        return 0;
}
/**



**/