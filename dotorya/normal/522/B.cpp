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

int w[200050];
int h[200050];
int main() {
    int sum = 0;
    int mx1 = 0, mx2 = 0;
    int N, i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d %d", &w[i], &h[i]);
        sum += w[i];
        if (h[mx2] < h[i]) mx2 = i;
        if (h[mx1] < h[mx2]) swap(mx1, mx2);
    }

    for (i = 1; i <= N; i++) {
        if (i == mx1) printf("%d ", (sum - w[i])*h[mx2]);
        else printf("%d ", (sum - w[i])*h[mx1]);
    }
    return 0;
}
//*/