#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e6 + 7;
int n;
int a[N];
string s;


int t[4 * N];

void build(int v, int tl, int tr)
{
       /// cout << " : " << tl << ", " << tr << "\n";
        if (tl == tr)
                t[v] = a[tl];
        else
        {
                int tm = (tl + tr) / 2;
                build(2 * v, tl, tm);
                build(2 * v + 1, tm + 1, tr);
                t[v] = min(t[2 * v], t[2 * v + 1]);
        }
}

int get(int v, int tl, int tr, int l, int r)
{
        if (tr < l || r < tl)
                return (1 << 30);
        if (l <= tl && tr <= r)
                return t[v];
        else
        {
                int tm = (tl + tr) / 2;
                return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
        }
}

vector <int> zub;
map <int, vector <int>> u;

int main()
{
        ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

        ///freopen ("input", "r", stdin);

        cin >> s;
        n = (int) s.size();
        for (int i = 1; i <= n; i++)
                if (s[i - 1] == '(')
                        a[i] = 1;
                else
                        a[i] = -1;
        for (int i = 1; i <= n; i++)
                a[i] += a[i - 1];
        for (int i = 0; i <= n; i++)
                u[a[i]].push_back(i);
        build(1, 1, n);

        for (auto &it : u)
        {
                int x = it.first;
                vector <int> p = it.second;
                int sz = (int) p.size();
                vector <bool> con(sz - 1);
                for (int i = 0; i + 1 < sz; i++)
                        if (get(1, 1, n, p[i], p[i + 1]) == a[p[i]])
                                con[i] = 1;
                        else
                                con[i] = 0;
                int i = 0;
                while (i < sz)
                {
                        int j = i;
                        while (i < sz - 1 && con[i])
                                i++;
                        /// j...i
                        zub.push_back(p[i] - p[j]);
                        i++;
                }
        }
        zub.push_back(0);
        int mx = 0, cnt = 0;
        for (auto &it : zub)
                mx = max(mx, it);
        for (auto &it : zub)
                cnt += (it == mx);
        if (mx == 0)
                cnt = 1;
        cout << mx << " " << cnt << "\n";

        return 0;
}