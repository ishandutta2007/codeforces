//*
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <functional>
#define MOD 1000000007
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef set<int>::iterator siit;

int in[505][505];

int x[505];
int main() {
    int N, M, Q, i, j, k, t1, t2;
    scanf("%d %d %d", &N, &M, &Q);
    for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) scanf("%d", &in[i][j]);

    // Initialize
    for (i = 1; i <= N; i++) {
        int st = 1;
        for (j = 1; j <= M; j++) {
            if (in[i][st] == 0) {
                st++;
                continue;
            }
            if (in[i][j+1] == 0) {
                if (x[i] < j + 1 - st) x[i] = j + 1 - st;
                st = j + 1;
            }
        }
    }

    // Get ANS
    for (i = 1; i <= Q; i++) {
        scanf("%d %d", &t1, &t2);
        in[t1][t2] = 1 - in[t1][t2];
        int st = 1;
        x[t1] = 0;
        for (j = 1; j <= M; j++) {
            if (in[t1][st] == 0) {
                st++;
                continue;
            }
            if (in[t1][j + 1] == 0) {
                if (x[t1] < j + 1 - st) x[t1] = j + 1 - st;
                st = j + 1;
            }
        }

        int mx = 0;
        for (j = 1; j <= N; j++) mx = max(mx, x[j]);
        printf("%d\n", mx);
    }
    return 0;
}
//*/