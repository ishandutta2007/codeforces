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

multiset <ll> S;
int main() {
    int N, i, ANS = 0;;
    ll t, sum = 0;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%lld", &t);
        S.insert(t);
    }

    multiset <ll>::iterator it;
    while (!S.empty()) {
        it = S.lower_bound(sum);
        if (it == S.end()) break;
        ANS++;
        sum += *it;
        S.erase(it);
    }
    printf("%d", ANS);
    return 0;
}
//*/