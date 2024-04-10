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

const int IT_MAX = 524288;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

int main() {
    int ans = 0, x1, x2, y1, y2, N, i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ans += (x2 - x1 + 1) *(y2 - y1 + 1);
    }
    printf("%d", ans);
    return 0;
}
//*/