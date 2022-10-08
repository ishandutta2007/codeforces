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

bool aa(int a, int b) {
    if (a == 2 || b == 1) return true;
    if ((b + 1) % a == 0 && aa(a, (b + 1) / a)) return true;
    if ((b - 1) % a == 0 && aa(a, (b - 1) / a)) return true;
    if (b%a == 0 && aa(a, b / a)) return true;
    return false;
}
int main() {
    int W, M;
    scanf("%d %d", &W, &M);
    if (aa(W, M)) printf("YES");
    else printf("NO");
    return 0;
}
//*/