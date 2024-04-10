#include <cstdlib>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <memory.h>
#include <numeric>
#include <utility>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>

#define MX 110000
using namespace std;

vector<int> con[MX], w[MX];
int dp[MX], pr[MX][20], rmq[MX][20];
int id[MX], tid[MX], bid[MX], qid[MX];
int dfn1[MX], dfn2[MX];
int deg[MX], C, N, M;

void dfs(int u, int p, int d) {
    
    dp[u] = d;
    dfn1[u] = ++C;
    int i, v, sz = con[u].size();
    
    for (i = 0; i < sz; i ++) {
        v = con[u][i];
        pr[v][0] = u;
        rmq[v][0] = w[u][i];
        dfs(v, u, d + 1);
    }
    dfn2[u] = C;
}

void init() {
    
    int i, k, u;
    for (k = 1; k <= 17; k ++) {
        for (i = 1; i <= N; i ++) {
            if (pr[i][k - 1] == 0) {
                pr[i][k] = pr[i][k - 1];
                rmq[i][k] = rmq[i][k - 1];
                continue;   
            }
            u = pr[i][k - 1];
            pr[i][k] = pr[u][k - 1];
            rmq[i][k] = max(rmq[i][k - 1], rmq[u][k - 1]);
        }   
    }   
}

int get_val(int u, int d) {
    
    int ans = -1, k;
    while (d) {
        for (k = 0; ; k ++) {
            if ((1 << k) > d) break;    
        }
        k --;
        ans = max(ans, rmq[u][k]);
        d -= (1 << k);
        u = pr[u][k];
    }
    return ans;
}

int main() {
    
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int i, t, u, v, k, mx;
    scanf("%d%d", &N, &M);
    
    int n = 0, cnt = 0;
    for (i = 1; i <= M; i ++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &u, &v);
            con[v].push_back(u);
            w[v].push_back(i);
            deg[u] ++;
        } else if (t == 2) {
            scanf("%d", &u);
            qid[n] = i; id[n ++] = u;
        } else {
            scanf("%d%d", bid + cnt, &u);
            tid[cnt ++] = u - 1;
        }
    }
    
    for (i = 1; i <= N; i ++) {
        if (deg[i]) continue;
        con[0].push_back(i);
        w[0].push_back(M + 1);  
    }
    pr[0][0] = -1, rmq[0][0] = M + 1;
    C = 0;
    dfs(0, -1, 0);
    init();
    for (i = 0; i < cnt; i ++) {
        k = tid[i];
        u = bid[i]; v = id[k]; mx = qid[k];
        if (dfn1[v] < dfn1[u] || dfn1[v] > dfn2[u]) {
            printf("NO\n");
            continue;   
        }   

        int c = get_val(v, dp[v] - dp[u]);
        if (c <= mx) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}