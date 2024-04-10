//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
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
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

bool in[105][105];
int A[105];
int B[105];
int conn[205][205];
int ans[105][105];
int dfs_chk[205];
bool DFS(int node, int chk, int snk) {
    if (node == snk) return true;
    dfs_chk[node] = chk;
    for (int i = 0; i <= snk; i++) {
        if (conn[node][i] == 0) continue;
        if (dfs_chk[i] == chk) continue;
        if (DFS(i, chk, snk)) {
            conn[node][i]--;
            conn[i][node]++;
            if (node == 0 || i == 0 || i == snk) return true;
            if (node <= (snk - 1) / 2) ans[node][i - (snk - 1) / 2]++;
            else ans[i][node - (snk - 1) / 2]--;
            return true;
        }
    }
    return false;
}
int main() {
    int N, M, i, j, t1, t2, sum = 0, sum2 = 0;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    for (i = 1; i <= N; i++) {
        scanf("%d", &B[i]);
        sum2 += B[i];
    }
    if (sum != sum2) {
        printf("NO");
        return 0;
    }
    for (i = 1; i <= N; i++) in[i][i] = true;
    for (i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        in[t1][t2] = in[t2][t1] = true;
    }

    int src = 0, snk = 2 * N + 1;
    for (i = 1; i <= N; i++) conn[src][i] = A[i];
    for (i = 1; i <= N; i++) conn[i+N][snk] = B[i];
    for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) if (in[i][j]) conn[i][j + N] = INF;

    int flow = 0;
    while (DFS(src, flow+1, snk)) flow++;
    if (sum != flow) {
        printf("NO");
        return 0;
    }

    printf("YES\n");
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}
//*/