#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int m;
int a[N];
int b[N];
string s;
string t;
bool ha[26];
bool hb[26];
int u[N][26];
int f[26];

int solve()
{
        for (int c = 0; c < 26; c++)
                if (hb[c] && ha[c] == 0)
                        return -1;
        for (int c = 0; c < 26; c++)
                f[c] = -1;
        for (int i = 1; i <= n; i++)
                if (f[a[i]] == -1)
                        f[a[i]] = i;
        for (int c = 0; c < 26; c++)
                u[n + 1][c] = -1;
        for (int i = n; i >= 1; i--)
        {
                for (int c = 0; c < 26; c++)
                        u[i][c] = u[i + 1][c];
                u[i][a[i]] = i;
        }
        int jumps = 1, cur = 1;
        for (int i = 1; i <= m; i++)
        {
                int c = b[i];
                if (u[cur][c] == -1)
                {
                        jumps++;
                        cur = f[c];
                }
                else
                {
                        cur = u[cur][c];
                }
                if (i == m)
                        break;
                cur++;
                if (cur == n + 1)
                {
                        jumps++;
                        cur = 1;
                }
        }
        return jumps;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int tt;
        cin >> tt;
        while (tt--)
        {
                cin >> s >> t;
                n = (int) s.size();
                m = (int) t.size();
                for (int c = 0; c < 26; c++)
                        ha[c] = hb[c] = 0;
                for (int i = 1; i <= n; i++)
                        a[i] = s[i - 1] - 'a';
                for (int i = 1; i <= m; i++)
                        b[i] = t[i - 1] - 'a';
                for (int i = 1; i <= n; i++)
                        ha[a[i]] = 1;
                for (int i = 1; i <= m; i++)
                        hb[b[i]] = 1;
                cout << solve() << "\n";
        }
}