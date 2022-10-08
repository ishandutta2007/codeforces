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

int in[100050];

int main() {
    int N, i, j;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%d", &in[i]);

    if (N == 1) {
        if (in[1] == 0) printf("YES\n0");
        else printf("NO\n");
        return 0;
    }

    if (N == 2) {
        if (in[1] == 1 && in[2] == 0) printf("YES\n1->0");
        else printf("NO");
        return 0;
    }

    if (N == 3) {
        if (in[3] == 1) printf("NO");
        else if (in[1] == 1 && in[2] == 0) printf("NO");
        else printf("YES\n(%d->%d)->%d", in[1], in[2], in[3]);
        return 0;
    }

    if (in[N] == 1) {
        printf("NO");
        return 0;
    }

    if (in[N - 1] == 1) {
        printf("YES\n");
        for (i = 1; i <= N - 1; i++) printf("(");
        for (i = 1; i <= N - 1; i++) printf("%d)->", in[i]);
        printf("0");
        return 0;
    }
    
    for (i = 1; i <= N-2; i++) if (in[i] == 0) break;
    if (i == N - 1) {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    printf("(");
    for (j = 1; j < i; j++) printf("(");
    for (j = 1; j < i; j++) printf("%d)->", in[j]);
    for (j = i; j <= N - 1; j++) {
        printf("(%d", in[j]);
        if (j != N - 1) printf("->");
    }
    for (j = i; j <= N - 1; j++) printf(")");
    printf(")");
    printf("->0");
    return 0;
}
//*/