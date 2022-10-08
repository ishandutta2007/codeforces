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

int N;
char in[105][105];
int in2[105];
int cur[105];
bool chk[105];
int main() {
    int N, i, j, k;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%s", &in[i][1]);
    for (i = 1; i <= N; i++) scanf("%d", &in2[i]);

    for (i = 0; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (cur[j] == in2[j]) break;
        }
        if (j == N + 1) break;
        for (k = 1; k <= N; k++) if (in[j][k] == '1') cur[k]++;
        chk[j] = true;
    }

    int cnt = 0;
    for (i = 1; i <= N; i++) if (chk[i]) cnt++;
    printf("%d\n", cnt);
    for (i = 1; i <= N; i++) if (chk[i]) printf("%d ", i);
    return 0;
}
//*/