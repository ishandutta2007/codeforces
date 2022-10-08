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

int in[100050];
int out[100050];
int main() {
    int N, i, st = -1, en = -1;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%d", &in[i]);
    for (i = 1; i < N; i++) {
        if (in[i] > in[i + 1]) {
            st = i;
            break;
        }
    }
    if (st == -1) {
        printf("yes\n1 1");
        return 0;
    }

    for (i = N; i > 1; i--) {
        if (in[i] < in[i - 1]) {
            en = i;
            break;
        }
    }
    
    for (i = 1; i < st; i++) out[i] = in[i];
    for (i = st; i <= en; i++) out[st + en - i] = in[i];
    for (i = en + 1; i <= N; i++) out[i] = in[i];

    for (i = 1; i < N; i++) if (out[i] > out[i + 1]) break;
    if (i < N) printf("no");
    else printf("yes\n%d %d", st, en);
    return 0;
}
//*/