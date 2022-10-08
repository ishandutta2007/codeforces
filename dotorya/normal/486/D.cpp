//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

vector <int> conn[2050];
vector <int> son[2050];
int in[2050];
bool dfs_chk[2050];
void DFS(int node) {
    dfs_chk[node] = true;
    for (int i = 0; i < conn[node].size(); i++) {
        int t = conn[node][i];
        if (dfs_chk[t]) continue;
        son[node].push_back(t);
        DFS(t);
    }
    return;
}
void make_tree() {
    DFS(1);
}

ll cnt[2050];
void DFS2(int node, int d, int u) {
    for (int i = 0; i < son[node].size(); i++) DFS2(son[node][i], d, u);
    if (in[node] < d || in[node] > u) {
        cnt[node] = 0;
        return;
    }
    cnt[node] = 1;
    for (int i = 0; i < son[node].size(); i++) cnt[node] = (cnt[node] * (cnt[son[node][i]] + 1)) % MOD;
    return;
}
ll get_cnt(int d, int u, int N) {
    DFS2(1, d, u);
    ll rv = 0;
    for (int i = 1; i <= N; i++) rv += cnt[i];
    return rv%MOD;
}
int main() {
    int D, N, i, t1, t2;
    scanf("%d %d", &D, &N);
    for (i = 1; i <= N; i++) scanf("%d", &in[i]);
    for (i = 1; i < N; i++) {
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }
    make_tree();

    ll ANS = 0;
    for (i = 1; i <= 2000; i++) {
        ANS += get_cnt(i, i+D, N) - get_cnt(i+1, i+D, N) + MOD;
        ANS %= MOD;
    }
    printf("%I64d", ANS);
    return 0;
}
//*/