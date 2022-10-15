#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 5;

int n;
int a[N];
vector<int>g[N];
bool seen[N];

int ans[N];

inline void no0 (int nod, int gcd)
{
    seen[nod] = 1;
    ans[nod] = max (ans[nod], gcd);
    for (auto &nou : g[nod])
    {
        if (seen[nou])
        {
            continue;
        }
        no0 (nou, __gcd (gcd, a[nou]));
    }
}

vector<int>divi[N];

int cnt[N];

inline void add (int x, int val)
{
    for (auto &j : divi[x])
    {
        cnt[j] += val;
    }
}

inline void yes0 (int nod, int len)
{
    seen[nod] = 1;
    add (a[nod], 1);
    for (auto &it : divi[a[1]])
    {
        if (cnt[it] >= len - 1)
        {
            ans[nod] = max (ans[nod], it);
        }
    }
    for (auto &nou : g[nod])
    {
        if (seen[nou])
        {
            continue;
        }
        yes0 (nou, len + 1);
    }
    add (a[nod], -1);
}

int main()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                divi[i].push_back (j);
                if (j * j != i)
                {
                    divi[i].push_back (i / j);
                }
            }
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back (y);
        g[y].push_back (x);
    }
    no0 (1, 0);
    for (int i = 1; i <= n; i++)
    {
        seen[i] = 0;
    }
    yes0 (1, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
/**

6
2

**/