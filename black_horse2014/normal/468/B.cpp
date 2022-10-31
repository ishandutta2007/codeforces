#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <climits>
#include <ctime>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <bitset>

#define MX 100005
#define X first
#define Y second
#define pb push_back
#define bit(x) (1 << (x))
#define bnum(x) (__builtin_popcount(x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))

using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> pii;
typedef vector<int> vi;

template <class T> inline void chkmin(T &a, T b) {
    if (b < a) a = b;
}
template <class T> inline void chkmax(T &a, T b) {
    if (a < b) a = b;
}


map<int, int> H;
int x[MX], n, a, b;
vector<int> con[MX];
int vis[MX], p[MX], pn;
int ans[MX];

void dfs(int u) {
    vis[u] = 1;
    p[pn++] = u;
    int sz = con[u].size();
    for (int i = 0; i < sz; i++) {
        int v = con[u][i];
        if (vis[v]) continue;
        dfs(v);
    }   
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int i, k;
    scanf("%d%d%d", &n, &a, &b);
    for (i = 0; i < n; i++) {
        scanf("%d", x + i);
        H[x[i]] = i;    
    }
    if (a == b) {
        
        for (i = 0; i < n; i++) {
            if (!H.count(a - x[i])) break;
        }   
        if (i < n) {
            printf("NO\n"); 
        } else {
            printf("YES\n");
            for (i = 0; i < n; i++) printf("0 ");
            printf("\n");
        }
        return 0;
    }
    int u, v;
    for (i = 0; i < n; i++) {
        v = a - x[i];
        if (H.count(v)) {
            u = H[v];
            con[i].push_back(u);
        }
        v = b - x[i];
        if (H.count(v)) {
            u = H[v];
            con[i].push_back(u);    
        }
    }
    
    for (i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (con[i].size() != 1) continue;
        pn = 0;
        dfs(i);
        
        int u = p[pn - 1];
        if (pn % 2 == 0) {
            for (k = 0; k < pn; k ++) ans[p[k]] = (x[p[0]] + x[p[1]] == b);
            continue;
        }
        if (x[p[0]] == a / 2 || x[p[0]] == b / 2) {
            for (k = 1; k < pn; k ++) ans[p[k]] = (x[p[1]] + x[p[2]] == b);
            ans[p[0]] = (2 * x[p[0]] == b);
            continue;
        }
        if (x[p[pn - 1]] == a / 2 || x[p[pn - 1]] == b / 2) {
            for (k = 0; k < pn - 1; k ++) ans[p[k]] = (x[p[0]] + x[p[1]] == b);         
            ans[p[pn - 1]] = (2 * x[p[pn - 1]] == b);
            continue;
        }
        break;
    }
    if (i < n) {
        printf("NO\n");
        return 0;   
    }
    for (i = 0; i < n; i++) if (!vis[i]) break;
    if (i < n) {
        printf("NO\n");
        return 0;   
    }
    printf("YES\n");
    for (i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;   
}