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

int in[300050];
int cnt[1000050];
int cnt_chk[1000050];
int C = 0;
ll aa(int st, int en, int K) {
    if (st == en) return 0;
    int mi = (st + en) / 2;
    ll rv = aa(st, mi, K) + aa(mi + 1, en, K);
    
    C++;
    int p1 = mi, p2 = mi + 1;
    int s1 = 0, s2 = 0, mx = in[p2];
    for (p2 = mi + 1; p2 <= en; p2++) {
        mx = max(mx, in[p2]);
        s2 = (s2 + in[p2]) % K;
        while (p1 >= st) {
            if (in[p1] < mx) {
                s1 = (s1 + in[p1]) % K;
                p1--;
                if (cnt_chk[s1] != C) {
                    cnt_chk[s1] = C;
                    cnt[s1] = 1;
                }
                else cnt[s1]++;
            }
            else break;
        }
        if (cnt_chk[(K + mx - s2) % K] == C) rv += cnt[(K + mx - s2) % K];
    }

    C++;
    p1 = mi, p2 = mi + 1;
    s1 = 0, s2 = 0, mx = in[p1];
    for (p1 = mi; p1 >= st; p1--) {
        mx = max(mx, in[p1]);
        s1 = (s1 + in[p1]) % K;
        while (p2 <= en) {
            if (in[p2] <= mx) {
                s2 = (s2 + in[p2]) % K;
                p2++;
                if (cnt_chk[s2] != C) {
                    cnt_chk[s2] = C;
                    cnt[s2] = 1;
                }
                else cnt[s2]++;
            }
            else break;
        }
        if (cnt_chk[(K + mx - s1) % K] == C) rv += cnt[(K + mx - s1) % K];
    }
    return rv;
}
int main() {
    int N, K, i;
    scanf("%d %d", &N, &K);
    for (i = 1; i <= N; i++) scanf("%d", &in[i]);
    printf("%I64d", aa(1, N, K));
    return 0;
}
//*/