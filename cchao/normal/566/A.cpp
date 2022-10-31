#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)
#define PB push_back
#define MP make_pair

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 1000010;
const double eps = 1e-8;

int ch[maxn][26] = {{}};
int sz[maxn] = {}, tot = 0;
char s[maxn];
vector<int> v[maxn];
void insert(int rt, char *s, int ii) {
    int cur = rt;
    v[cur].PB(ii);
    for(int i = 0; s[i]; ++i) {
        int idx = s[i] - 'a';
        if(!ch[cur][idx]) {
            ch[cur][idx] = ++tot;
        }
        cur = ch[cur][idx];
        sz[cur]++;
        v[cur].PB(ii);
    }
}
int build(int n) {
    int rt = ++tot;
    rep(i, n) {
        rs(s);
        insert(rt, s, i + 1);
    }
    return rt;
}
int ans[maxn] = {}, mat[maxn] = {};
int merge(int a, int b) {
    int rt = min(sz[a], sz[b]);
    rep(i, 26) {
        if(ch[a][i] && ch[b][i]) {
            rt += merge(ch[a][i], ch[b][i]);
        }
    }
    unsigned i = 0, j = 0;
    for(i = 0; i < v[a].size(); ++i) if(!ans[v[a][i]]) {
        while(j < v[b].size() && mat[v[b][j]]) ++j;
        if(j < v[b].size()) {
            ans[v[a][i]] = v[b][j];
            mat[v[b][j]] = v[a][i];
        }
    }
    return rt;
}
int main() {
    int n; ri(n);
    int a = build(n);
    int b = build(n);
    pi(merge(a, b));
    for(int i = 1; i <= n; ++i) printf("%d %d\n", i, ans[i]);
    return 0;
}