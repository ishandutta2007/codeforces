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

const int IT_MAX = 1048576;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

set <pair<pii, pii>> S;
int main() {
    int N, Q, i, t1, t2;
    char c[2];
    scanf("%d %d", &N, &Q);
    S.insert(make_pair(pii(1, N), pii(0, 0)));

    for (i = 1; i <= Q; i++) {
        scanf("%d %d %s", &t2, &t1, c);
        set <pair<pii, pii>>::iterator it = S.lower_bound(make_pair(pii(t1+1, 0), pii(0, 0)));
        if (it == S.begin()) {
            printf("0\n");
            continue;
        }
        it--;
        if (it->first.second < t1) {
            printf("0\n");
            continue;
        }

        int l = it->first.first, r = it->first.second, lv = it->second.first, uv = it->second.second;
        S.erase(it);
        if (c[0] == 'U') {
            printf("%d\n", t1 - uv);
            if (t1 + 1 <= r) S.insert(make_pair(pii(t1 + 1, r), pii(lv, uv)));
            if (t1 - 1 >= l) S.insert(make_pair(pii(l, t1 - 1), pii(t2, uv)));
        }
        else {
            printf("%d\n", t2 - lv);
            if (t1 + 1 <= r) S.insert(make_pair(pii(t1 + 1, r), pii(lv, t1)));
            if (t1 - 1 >= l) S.insert(make_pair(pii(l, t1 - 1), pii(lv, uv)));
        }
    }
    return 0;
}
//*/