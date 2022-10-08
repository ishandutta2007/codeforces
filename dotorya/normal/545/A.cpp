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
typedef set <int>::iterator siit;
typedef set <ll>::iterator slit;

typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

int D[105][105];
vector <int> ANS;
int main() {
    int N, i, j;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) scanf("%d", &D[i][j]);
        for (j = 1; j <= N; j++) if (D[i][j] == 1 || D[i][j] == 3) break;
        if (j == N + 1) ANS.push_back(i);
    }
    printf("%d\n", ANS.size());
    for (i = 0; i < ANS.size(); i++) printf("%d ", ANS[i]);
    return 0;
}
//*/