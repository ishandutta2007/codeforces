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

int main() {
    int N, i, j;
    scanf("%d", &N);
    if (N == 1) {
        printf("YES\n2 1\n1 2");
        return 0;
    }
    else if (N % 2 == 0) {
        printf("NO");
        return 0;
    }
    else {
        printf("YES\n%d %d\n", 2 * N + 4, (N + 1)*(N + 1)-1);
        for (i = 1; i <= N - 1; i++) {
            for (j = i + 1; j <= N + 2; j++) {
                if (i % 2 != 1 || j != i+1) printf("%d %d\n", i, j);
            }
        }
        printf("%d %d\n", N, N + 1);

        for (i = N + 3; i <= 2 * N + 1; i++) {
            for (j = i + 1; j <= 2 * N + 4; j++) {
                if (i % 2 != 0 || j != i + 1) printf("%d %d\n", i, j);
            }
        }
        printf("%d %d\n", 2 * N+2, 2 * N + 3);
        printf("%d %d\n", N + 2, 2 * N + 4);
    }
    return 0;
}
//*/