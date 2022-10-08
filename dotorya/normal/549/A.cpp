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

char in[55][55];
int main() {
    int N, M, i, j, i1, j1, ans = 0;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++) scanf("%s", in[i]);

    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < M - 1; j++) {
            int chk1 = 0, chk2 = 0, chk3 = 0, chk4 = 0;
            for (i1 = 0; i1 < 2; i1++) {
                for (j1 = 0; j1 < 2; j1++) {
                    if (in[i + i1][j + j1] == 'f') chk1++;
                    if (in[i + i1][j + j1] == 'a') chk2++;
                    if (in[i + i1][j + j1] == 'c') chk3++;
                    if (in[i + i1][j + j1] == 'e') chk4++;
                }
            }
            if (chk1 == 1 && chk2 == 1 && chk3 == 1 && chk4 == 1) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
//*/