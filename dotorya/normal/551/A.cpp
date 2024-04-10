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

int in[2050];
int main() {
    int N, i, j;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%d", &in[i]);

    for (i = 1; i <= N; i++) {
        int cnt = 1;
        for (j = 1; j <= N; j++) {
            if (i == j) continue;
            if (in[i] < in[j]) cnt++;
        }
        printf("%d ", cnt);
    }
    return 0;
}
//*/