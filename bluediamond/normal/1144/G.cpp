#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
const int INF = (int) 1e9;

int n;
int v[N];
int first[N];
pair<int, int>t[4 * N];
int dp[N];
int papa[N];
int take[N];

void upd(int v, int tl, int tr, int p, int x)
{
        if(tr < p || p < tl)
        {
                return;
        }
        if(tl == tr)
        {
                t[v] = {x, p - 1};
        }
        else
        {
                int tm = (tl + tr) >> 1;
                upd(2 * v, tl, tm, p, x);
                upd(2 * v + 1, tm + 1, tr, p, x);
                if(t[2 * v].first < t[2 * v + 1].first)
                {
                        t[v] = t[2 * v];
                }
                else
                {
                        t[v] = t[2 * v + 1];
                }
        }
}

pair<int, int> get(int v, int tl, int tr, int l, int r)
{
        if(tr < l || r < tl)
        {
                return {INF, 0};
        }
        if(l <= tl && tr <= r)
        {
                return t[v];
        }
        else
        {
                int tm = (tl + tr) >> 1;
                pair<int, int> a = get(2 * v, tl, tm, l, r);
                pair<int, int> b = get(2 * v + 1, tm + 1, tr, l, r);
                if(a.first < b.first)
                {
                        return a;
                }
                else
                {
                        return b;
                }
        }
}

void upd(int p, int x)
{
        upd(1, 1, n, p, x);
}

pair<int, int> get(int l, int r)
{
        return get(1, 1, n, l, r);
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                upd(i, INF);
                cin >> v[i];
                if(i > 1 && v[i - 1] > v[i])
                {
                        first[i] = first[i - 1];
                }
                else
                {
                        first[i] = i;
                }
        }
        int last = 1;
        for(int i = 2; i <= n; i++)
        {
                if(v[i - 1] < v[i])
                {
                        last++;
                }
                else
                {
                        break;
                }
        }
        for(int i = 1; i <= last; i++)
        {
                papa[i] = i - 1;
                dp[i] = INF;
                if(dp[i - 1] > v[i])
                {
                        upd(i, v[i - 1]);
                }
        }
        for(int i = last + 1; i <= n; i++)
        {
                dp[i] = -1;
                if(v[i - 1] < v[i])
                {
                        dp[i] = dp[i - 1];
                        papa[i] = i - 1;
                }
                int l = first[i - 1];
                int r = i - 1;
                pair<int, int>a = get(l, r);
                if(l <= r && v[i - 1] > dp[i] && a.first < v[i])
                {
                        papa[i] = a.second;
                        dp[i] = v[i - 1];
                }
                if(v[i - 1] > dp[i] && first[i - 1] == 1)
                {
                        dp[i] = v[i - 1];
                }
                if(dp[i - 1] > v[i])
                {
                        upd(i, v[i - 1]);
                }
        }
        last = n;
        for(int i = n - 1; i >= 1; i--)
        {
                if(v[i] > v[i + 1])
                {
                        last--;
                }
                else
                {
                        break;
                }
        }
        for(int i = last; i <= n; i++)
        {
                if(dp[i] == -1) continue;
                bool ok = 0;
                if(i == n)
                {
                        ok = 1;
                }
                else
                {
                        if(dp[i] > v[i + 1])
                        {
                                ok = 1;
                        }
                }
                if(!ok) continue;
                int j = i;
                while(j)
                {
                        take[j] = 1;
                        j = papa[j];
                }
                cout << "YES\n";
                for(int j = 1; j <= n; j++)
                {
                        cout << 1 - take[j] << " ";
                }
                cout << "\n";
                return 0;
        }
        cout << "NO\n";
}