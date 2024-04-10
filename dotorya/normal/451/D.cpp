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

const int IT_MAX = 131072;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

char in[100050];

int main() {
    int L, i;
    ll oo = 0, oe = 0, eo = 0, ee = 0;
    scanf("%s", &in[1]);
    int G = 0;
    for (L = 1; in[L] != 0; L++) {
        if (in[L] != in[L - 1]) G++;
        if (G % 2 == 0 && L % 2 == 0) ee++;
        if (G % 2 == 0 && L % 2 == 1) oe++;
        if (G % 2 == 1 && L % 2 == 0) eo++;
        if (G % 2 == 1 && L % 2 == 1) oo++;
    }
    L--;

    printf("%I64d %I64d", ee*oe + oo*eo, L + oo*(oo - 1) / 2 + oe*(oe - 1) / 2 + eo*(eo - 1) / 2 + ee*(ee - 1) / 2);
    return 0;
}
//*/