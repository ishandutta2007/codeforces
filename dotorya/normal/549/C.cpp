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
    int oc = 0, ec = 0, N, K, t, i;
    scanf("%d %d", &N, &K);
    for (i = 1; i <= N; i++) {
        scanf("%d", &t);
        if (t % 2 == 0) ec++;
        else oc++;
    }

    if (N == K) {
        if (oc % 2 == 0) printf("Daenerys");
        else printf("Stannis");
        return 0;
    }

    t = N - K;
    if (t % 2 == 1) {
        if (oc > t / 2 && ec > t / 2) printf("Stannis");
        else if (oc <= t / 2) printf("Daenerys");
        else {
            if ((t - ec) % 2 == oc%2) printf("Daenerys");
            else printf("Stannis");
        }
    }
    else {
        if (oc > t / 2 && ec > t / 2) printf("Daenerys");
        else if (ec <= t / 2) {
            if ((t - ec) % 2 == oc % 2) printf("Daenerys");
            else printf("Stannis");
        }
        else printf("Daenerys");
    }
    return 0;
}

//*/