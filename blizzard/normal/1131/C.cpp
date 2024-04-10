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
int v[MAXN], ans[MAXN];
bool used[MAXN];
bool used2[MAXN];

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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort (v, v + n);
    for (int i = 0; i < n; i += 2)
    {
        cout << v[i] << " ";
    }
    n -= (n % 2);
    for (int i = n - 1; i >= 0; i -= 2)
    {
        cout << v[i] << " ";
    }

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