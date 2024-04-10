#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 150031;
const int MOD = (int) 1e9+7;
int a[MAXN];
const int INF = 1e9;

int readInt();
void readWord( char *s );

int dp[MAXN][5][3];

inline void update(int& a, int b)
{
    a = max(a, b);
}
int n;
int parent[MAXN], rankE[MAXN];
int nextCat[MAXN], last[MAXN];
int first[MAXN]
;
void make_set (int v) {
    parent[v] = v;
    rankE[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void unite (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rankE[a] < rankE[b])
            swap (a, b);
        parent[b] = a;
        if (rankE[a] == rankE[b])
            ++rankE[a];
        nextCat[last[b]] = first[a];
        first[a] = first[b];
    }
}

void init()
{
    for (int i = 0; i < n; ++i) {
        rankE[i] = 0;
        nextCat[i] = -1;
        parent[i] = i;
        last[i] = i;
        first[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    init();
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        unite(u, v);
    }
    int all = find_set(0);
    int now = first[all];
    for (int i = 1; i < n; ++i) {
        cout << now + 1 << " ";
        now = nextCat[now];
    }
    cout << now + 1;
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