#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
const int K = 30;

int q;
int cnt[N * K];
int nxt[N * K][2];
int last = 1;

bool bt(int x, int j)
{
    return (x & (1 << j)) > 0;
}

void add(int x, int sgn)
{
    int v = 1;
    cnt[v] += sgn;
    for (int i = K - 1; i >= 0; i--)
    {
        if (nxt[v][bt(x, i)] == 0)
        {
            nxt[v][bt(x, i)] = ++last;
        }
        v = nxt[v][bt(x, i)];
        cnt[v] += sgn;
    }
}

int solve(int x, int y)
{
    int v = 1;
    int ans = 0;
    for (int i = K - 1; i >= 0 && v; i--)
    {
        ans += (bt(y, i) == 1) * cnt[nxt[v][bt(x, i)]];
        v = nxt[v][bt(x, i) ^ bt(y, i)];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            add(x, +1);
        }
        if (t == 2)
        {
            int x;
            cin >> x;
            add(x, -1);
        }
        if (t == 3)
        {
            int x, y;
            cin >> x >> y;
            cout << solve(x, y) << "\n";
        }

    }

}