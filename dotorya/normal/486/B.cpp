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

bool row[105];
bool col[105];
int in[105][105];
int ans[105][105];
int B[105][105];
int main() {
    int N, M, i, j, k, t;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &in[i][j]);
            if (in[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (row[i] || col[j]) ans[i][j] = 0;
            else {
                ans[i][j] = 1;
                for (k = 0; k < N; k++) B[k][j] = 1;
                for (k = 0; k < M; k++) B[i][k] = 1;
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (in[i][j] != B[i][j]) {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}
//*/