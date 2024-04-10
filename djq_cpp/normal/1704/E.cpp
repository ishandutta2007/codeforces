#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
vector<int> G[1005];
int que[1005], fr, rr;
int deg[1005], a[1005];
void solve()
{
    scanf("%d%d", &n, &m);
    rep1(i, n) scanf("%d", &a[i]);
    rep1(i, n) deg[i] = 0;
    rep1(i, n) G[i].clear();
    rep(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v); deg[v] ++;
    }
    fr = rr = 0;
    rep1(i, n) if(deg[i] == 0) que[rr ++] = i;
    while(fr < rr) {
        int v = que[fr ++];
        rep(i, G[v].size()) {
            int u = G[v][i];
            deg[u] --;
            if(deg[u] == 0) que[rr ++] = u;
        }
    }

    rep(i, n) {
        bool ok = false;
        rep1(j, n) ok |= a[j] != 0;
        if(!ok) {
            printf("%d\n", i); return;
        }
        for(int j = n - 1; j >= 0; j --) {
            int v = que[j];
            if(a[v] > 0) {
                a[v] --;
                for(auto u : G[v]) a[u] ++;
            }
        }
    }

    rep(i, n) {
        int v = que[i];
        for(auto u : G[v]) a[u] = (a[u] + a[v]) % MOD;
    }
    printf("%d\n", (a[que[n - 1]] + n) % MOD);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}