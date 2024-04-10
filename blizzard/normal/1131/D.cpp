#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2031;
const int MOD = (int) 1e9+7;
int a[MAXN];
const int INF = 1e9;

int readInt();
void readWord( char *s );

int dp[MAXN][5][3];
vector<int> e[MAXN];
vector<int> ee[MAXN];

inline void update(int& a, int b)
{
    a = max(a, b);
}
int n, m;

char c[MAXN][MAXN];
int color[MAXN], ans[MAXN];
bool used[MAXN];
bool used2[MAXN];

void dfs(int v, int comp)
{
    used[v] = true;
    color[v] = comp;
    for (int u : e[v])
    {
        if (!used[u])
        {
            dfs(u, comp);
        }
    }
}

void build(int v)
{
    used2[v] = true;
    for (auto u : ee[v])
    {
        if (!used2[u])
        {
            build(u);
        }
        update(ans[v], ans[u] + 1);
    }
}

void init()
{
    for (int i = 0; i <= n + m; i++)
    {
        ans[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    init();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            c[i][j] = s[j];
            if (c[i][j] == '=')
            {
                e[i].emplace_back(n + j);
                e[n + j].emplace_back(i);
            }
        }
    }

    int t = n + m;
    int col = 1;
    for (int i = 0; i < t; i++)
    {
        if (!used[i])
        {
            dfs(i, col++);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j] == '=')
            {
                continue;
            }
            if (c[i][j] == '>')
            {
                ee[color[i]].emplace_back(color[n + j]);
            } else
            {
                ee[color[n + j]].emplace_back(color[i]);
            }
        }
    }

    for (int i = 1; i <= t; i++)
    {
        if (!used2[i])
        {
            build(i);
        }
    }

//    for (int i = 1; i <= n + m; i++)
//        cerr << ans[i] << " ";


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((c[i][j] == '<' && ans[color[i]] >= ans[color[n + j]]) ||
                (c[i][j] == '>' && ans[color[n + j]] >= ans[color[i]]))
            {
                    cout << "No"; exit(0);
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[color[i]] << " \n"[i == n - 1];
    }
    for (int i = 0; i < m; i++) {
        cout << ans[color[n + i]] <<  " \n"[i == m - 1];
    }
//    for (int i = 0; i < n; i++) {
//        cerr << color[i] << " \n"[i == n - 1];
//    }
//    for (int i = 0; i < m; i++) {
//        cerr << color[n + i] <<  " \n"[i == m - 1];
//    }

    return 0;
}


/***
 * Unsigned
 */

inline unsigned long long readULong()
{
    int c = getc(stdin);
    unsigned long long x = 0;
    while (c <= 32)
        c = getc(stdin);
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getc(stdin);
    return x;
}

inline unsigned int readUInt()
{
    int c = getc(stdin);
    unsigned int x = 0;
    while (c <= 32)
        c = getc(stdin);
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getc(stdin);
    return x;
}

inline void writeULong( unsigned long long x )
{
    char s[30];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        putc(s[n], stdout);
}

inline void writeUInt( unsigned int x )
{
    char s[15];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        putc(s[n], stdout);
}

/***
 * Signed
 */

inline int readInt()
{
    int s = 1, x = 0, c = getc(stdin);
    while (c <= 32)
        c = getc(stdin);
    if (c == '-')
        s = -1, c = getc(stdin);
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getc(stdin);
    return x * s;
}

inline void writeInt( int x )
{
    if (x < 0)
        putc('-', stdout), x = -x;

    char s[20];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        putc(s[n], stdout);
}

/***
 * Word
 */

inline void readWord( char *s )
{
    int c = getc(stdin);
    while (c <= 32)
        c = getc(stdin);
    while (c > 32)
        *s++ = c, c = getc(stdin);
    *s = 0;
}

inline void writeWord( char *s )
{
    while (*s)
        putchar(*s++);
}