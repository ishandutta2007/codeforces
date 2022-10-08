//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

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
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

char in[100050];
int dis(char x, char y) {
    int t = abs(x - y);
    if (t > 13) t = 26 - t;
    return t;
}

int D[50050];
int main() {
    int N, P, i;
    scanf("%d %d", &N, &P);
    if (P > N / 2) P = N + 1 - P;
    scanf("%s", &in[1]);
    int mn = -1, mx = -1, sum = 0;
    for (i = 1; i <= N / 2; i++) {
        D[i] = dis(in[i], in[N + 1 - i]);
        if (D[i] == 0) continue;
        mx = i;
        if (mn == -1) mn = i;
        sum += D[i];
    }
    
    if (mn == -1) {
        printf("0");
        return 0;
    }

    if (P <= mn) sum += mx - P;
    else if (P >= mx) sum += P - mn;
    else sum += mx - mn + min(mx - P, P - mn);
    printf("%d", sum);
    return 0;
}
//*/