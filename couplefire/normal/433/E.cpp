#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
 
typedef long long ll;
 
#define SIZE 210
#define LEN 210
#define W 510
struct node {
    int val, s[20], fail;
} tree[SIZE];
int n, m, K, Llen, Rlen, root, cnt = 0, q[SIZE];
int L[LEN], R[LEN], num[LEN];
 
int read(int *s) {
    int len;
    cin >> len;
    for (int i = 0; i < len; ++i)
        cin >> s[i];
    return len;
}
 
void insert(int *s, int len, int w) {
    int p = root;
    for (int i = 0; i < len; ++i) {
        if (!tree[p].s[s[i]]) tree[p].s[s[i]] = ++cnt;
        p = tree[p].s[s[i]];
    }
    tree[p].val += w;
}
 
void build() {
    int h = 0, t = 0;
    q[t++] = root;
    while (h < t) {
        int cur = q[h++];
        for (int i = 0; i < m; ++i) {
            int p = tree[cur].fail;
            while (p && !tree[p].s[i]) p = tree[p].fail;
            if (!p) p = root;
            else p = tree[p].s[i];
            if (tree[cur].s[i]) {
                int son = tree[cur].s[i];
                tree[son].fail = p;
                tree[son].val += tree[tree[son].fail].val;
                q[t++] = son;
            } else {
                tree[cur].s[i] = p;
            }
        }
    }
}
 
const int mod = (int)1e9 + 7;
 
int f[LEN][W][SIZE][2][2];
// length | value | node | leading zero | upper bound
 
void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
 
int calc(int *a, int len) {
    memset(f, 0, sizeof f);
    f[0][0][root][true][true] = 1;
    for (int i = 0; i < len; ++i)
        for (int k = 0; k <= K; ++k)
            for (int j = 1; j <= cnt; ++j)
                for (int l = 0; l < 2; ++l)
                    for (int u = 0; u < 2; ++u) {
                        if (!f[i][k][j][l][u]) continue;
                        for (int x = 0; x < m; ++x) {
                            if (x > a[i] && u) break;
                            int nl = false, nu = false, node = tree[j].s[x];
                            if (x == 0 && l) nl = true;
                            if (x == a[i] && u) nu = true;
                            if (nl) add(f[i + 1][k][j][nl][nu], f[i][k][j][l][u]);
                            else if (k + tree[node].val <= K)
                                add(f[i + 1][k + tree[node].val][node][nl][nu], f[i][k][j][l][u]);
                        }
                    }
    int ret = 0;
    for (int k = 0; k <= K; ++k)
        for (int j = 1; j <= cnt; ++j)
            for (int l = 0; l < 2; ++l)
                for (int u = 0; u < 2; ++u)
                    add(ret, f[len][k][j][l][u]);
    return ret;
}
 
int main(int argc, char *argv[]) {
#ifdef KANARI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    cin >> n >> m >> K;
    Llen = read(L), Rlen = read(R);
    root = ++cnt;
    for (int i = 1; i <= n; ++i) {
        int len = read(num), w;
        cin >> w;
        insert(num, len, w);
    }
    build();
    
    int ans = calc(R, Rlen);
    --L[Llen - 1];
    for (int i = Llen - 1; i > 0; --i)
        if (L[i] < 0) --L[i - 1], L[i] += m;
    if (L[0] == 0) {
        for (int i = 0; i < Llen - 1; ++i) L[i] = L[i + 1];
        --Llen;
    }
    
    ans = (ans - calc(L, Llen) + mod) % mod;
    cout << ans << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}