#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
    int a, b, w;
    bool operator<(const Edge &r) const {
        return w < r.w;
    }
} e[1010*1010];

int sz = 0;
char s[1010][12][12];
int p[1010];
int n, m, k, w;
int diff(int a, int b) {
    int r = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(s[a][i][j] != s[b][i][j])
                r++;
    return r;
}

int f(int x) {
    return x == p[x] ? p[x] : (p[x] = f(p[x]));
}

bool res[1010][1010] = {{}};
bool v[1010] = {};

void print(int x) {
    if(v[x]) return;
    v[x] = true;
    for(int i = 0; i <= k; ++i) {
        if(res[x][i]) {
            res[x][i] = res[i][x] = false;
            printf("%d %d\n", i, x);
            print(i);
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &w);
    for(int i = 1; i <= k; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%s", s[i][j]);

    int r = n*m;
    for(int i = 1; i <= k; ++i)
        e[sz++] = (Edge){0, i, r};

    for(int i = 1; i <= k; ++i)
        for(int j = 1; j < i; ++j) {
            e[sz++] = (Edge){i, j, diff(i, j)*w};
        }

    sort(e, e+sz);
    int cnt = 0, ans = 0;
    for(int i = 0; i <= k; ++i) p[i] = i;
    for(int i = 0; i < sz && cnt < k; ++i) {
        Edge x = e[i];
        if(f(x.a) != f(x.b)) {
            //printf("connect %d %d\n", x.a, x.b);
            res[x.b][x.a] = res[x.a][x.b] = true;
            cnt++;
            ans += x.w;
            p[f(x.a)] = f(x.b);
        }
    }
    printf("%d\n", ans);
    print(0);
    return 0;
}