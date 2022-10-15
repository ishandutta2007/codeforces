#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000000 + 7;
int n, m, qq, t[N], dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1}, d[N];
vector<pair<int, bool>> g[N];
int single[N], a[N];

bool inside(int r, int c)
{
        return (0 <= r && 0 <= c && r < n && c < m);
}

int comp(int a)
{
        if (t[a] == a)
                return a;
        else
                return t[a] = comp(t[a]);
}

void unite(int a, int b)
{
        a = comp(a);
        b = comp(b);
        if (a == b)
                return;
        t[a] = b;
        single[b] = 0;
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n >> m >> qq;
        for (int i = 0; i < n; i++)
        {
                string s;
                cin >> s;
                for (int j = 0; j < m; j++)
                        a[i * m + j] = s[j] - '0';
        }
        for (int i = 0; i < n * m; i++)
        {
                t[i] = i;
                single[i] = 1;
        }
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        for (int k = 0; k < 4; k++)
                        {
                                int in = i + dr[k], jn = j + dc[k];
                                if (inside(in, jn))
                                {
                                        if (a[i * m + j] != a[in * m + jn])
                                        {
                                                g[i * m + j].push_back({in * m + jn, 1});
                                                g[in * m + jn].push_back({i * m + j, 1});
                                        }
                                        else
                                        {
                                                g[i * m + j].push_back({in * m + jn, 0});
                                                g[in * m + jn].push_back({i * m + j, 0});
                                                unite(i * m + j, in * m + jn);
                                        }
                                }
                        }
        bool all = 1;
        for (int i = 0; i < n * m; i++)
                if (t[i] != i)
                        all = 0;
        if (all)
        {
                while (qq--)
                {
                        int r, c;
                        ll val;
                        cin >> r >> c >> val;
                        r--;
                        c--;
                        cout << a[r * m + c] << "\n";
                }
                return 0;
        }
        deque<int> q;
        for (int i = 0; i < n * m; i++)
                if (single[comp(i)] == 0)
                        q.push_front(i);
                else
                        d[i] = -1;
        while (!q.empty())
        {
                auto a = q.front();
                q.pop_front();
                for (auto &it : g[a])
                {
                        int b = it.first;
                        bool k = it.second;
                        if (d[b] != -1)
                                continue;
                        if (k == 0)
                        {
                                d[b] = d[a];
                                q.push_front(b);
                        }
                        else
                        {
                                d[b] = 1 + d[a];
                                q.push_back(b);
                        }
                }
        }
        while (qq--)
        {
                int r, c;
                ll val;
                cin >> r >> c >> val;
                r--;
                c--;
                int i = r * m + c;
                if (val <= d[i])
                        cout << a[i] << "\n";
                else
                {
                        val -= d[i];
                        val %= 2;
                        cout << (a[i] ^ val) << "\n";
                }
        }
}