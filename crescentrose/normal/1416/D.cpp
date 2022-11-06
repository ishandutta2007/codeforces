#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 5e5 + 10;
const int S = 19;
int n, m, q, tot;
int r[N], a[N], e[N][2], b[N], h[N], cnt, a2id[N];
int fa[N][S + 1], son[N][2], dfnl[N], dfnr[N], fv[N], dfn2id[N], f[N * 4];
struct node{
    int x, y;
}Q[N];
int geth(int x) {return h[x] == x? x: h[x] = geth(h[x]);}
void dfs(int x) {
    for (int i = 0; fa[fa[x][i]][i]; i ++)
    {
        fa[x][i + 1] = fa[fa[x][i]][i];
    }
    if (x <= n) {
        dfnl[x] = dfnr[x] = ++cnt;
        dfn2id[cnt] = x;
        return;
    }
    dfs(son[x][0]);
    dfs(son[x][1]);
    dfnl[x] = dfnl[son[x][0]];
    dfnr[x] = cnt;
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s] = a[dfn2id[l]];
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s +s + 1);
    f[s] = max(f[s+s], f[s+s+1]);
}
int get(int l, int r, int s, int ll, int rr) {
    if (r < ll || rr < l) return 0;
    if (ll <= l && r <= rr) return f[s];
    return max(get(l, (l + r)/  2, s +s, ll, rr), get((l + r) / 2 + 1, r, s + s + 1, ll , rr));
}
void change(int l, int r, int s, int ll) {
    if (l == r) {
        f[s] = 0;
        return;
    }
    if ((l + r) / 2 >= ll) change(l,(l + r) / 2, s + s, ll);
    else
        change((l + r) / 2 + 1,r, s+s +1, ll);
    f[s]=max(f[s+s],f[s+s+1]);
}

namespace IO {
    const int BUF_SIZE = 1 << 15;
    char in_buf[BUF_SIZE], out_buf[BUF_SIZE];
    char *p_in_buf = in_buf + BUF_SIZE;
    char *p_out_buf = out_buf;
    inline char get_char() {
        if (p_in_buf == in_buf + BUF_SIZE) {
            fread(in_buf, 1, BUF_SIZE, stdin), p_in_buf = in_buf;
        }
        return *(p_in_buf++);
    }
    inline void put_char(char x) {
        if (p_out_buf == out_buf + BUF_SIZE) {
            fwrite(out_buf, 1, BUF_SIZE, stdout), p_out_buf = out_buf;
        }
        *(p_out_buf++) = x;
    }
    inline void flush() {
        if (p_out_buf != out_buf) {
            fwrite(out_buf, 1, p_out_buf - out_buf, stdout);p_out_buf = out_buf;
        }
    }
}
#define getchar() IO::get_char()
bool isdigit(char c) {
    return c >= '0' && c <= '9';
}
inline int getint() {
    int x = 0;
    char c;
    c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}
int main() {
    n = getint();
    m = getint();
    q = getint();
    for (int i = 1; i <= n; i ++) {
        a[i] = getint();
        a2id[a[i]] = i;
        h[i] = i;
        h[i +n] = i + n;
        fv[i] = q + 1;
    }
    for (int i = 1; i <= m;i ++) {
        r[i] = q + 1;
        e[i][0] = getint();
        e[i][1] = getint();
        b[i] = i;
    }
    for (int i = 1; i <= q; i ++) {
        Q[i].x = getint();
        Q[i].y = getint();
        if (Q[i].x == 2) {
            r[Q[i].y] = i;
        }
    }
    sort(b + 1, b + m + 1, [](int x ,int y) {return r[x] > r[y];});
    tot = n;
    for (int i = 1; i <= m; i ++)
    {
        int x = b[i];
        if (geth(e[x][0]) != geth(e[x][1])) {
            int y = geth(e[x][0]);
            int z = geth(e[x][1]);
            h[y] = h[z] = ++tot;
            fa[y][0] = fa[z][0] = tot;
            fv[tot] = r[x];
            son[tot][0] = y;
            son[tot][1] = z;
        }
    }
    for (int i = 1; i <= tot; i ++)
        if (geth(i) == i)
            dfs(i);
    build(1, n, 1);
    for (int i = 1; i <= q ;i ++) {
        if (Q[i].x == 1) {
            int x = Q[i].y;
            for (int j = S; j >= 0; j --)
                if (fv[fa[x][j]] > i) x = fa[x][j];
            int y = get(1, n, 1, dfnl[x], dfnr[x]);
            printf("%d\n", y);
            if (y)
                change(1, n, 1, dfnl[a2id[y]]);
        }
    }
    return 0;
}