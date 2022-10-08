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

char t[105][105];
int in[105][105];
int main() {
    int N, M, i, j, i1, j1;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        scanf("%s", &t[i][1]);
        for (j = 1; j <= M; j++) in[i][j] = ((t[i][j] == 'B') ? 1 : (-1));
    }

    int ans = 0;
    for (i = N; i >= 1; i--) {
        for (j = M; j >= 1; j--) {
            if (in[i][j] == 0) continue;
            ans++;
            for (i1 = 1; i1 <= i; i1++) {
                for (j1 = 1; j1 <= j; j1++) {
                    in[i1][j1] -= in[i][j];
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}

//*/