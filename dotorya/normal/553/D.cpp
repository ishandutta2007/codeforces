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

struct Fraction {
    ll x, y;
    Fraction() {
        Fraction(1, 1);
    }
    Fraction(ll a, ll b) {
        x = a, y = b;
    }
    bool operator < (const Fraction& l) const {
        return x*l.y < y*l.x;
    }
    bool operator <= (const Fraction& l) const {
        return x*l.y <= y*l.x;
    }
};
vector <int> conn[100050];
vector <int> fort;
int Q[100050];
int chk[100050];
int cnt[100050];

Fraction left_fraction(Fraction k) {
    if (k.x == 0) return Fraction(0, 1);
    Fraction rv = Fraction(0, 1);
    for (int i = 1; i <= 100000; i++) {
        ll t = (k.x*i-1) / k.y;
        if (rv < Fraction(t, i)) rv = Fraction(t, i);
    }
    return rv;
}
Fraction right_fraction(Fraction k) {
    Fraction rv = Fraction(2, 1);
    for (int i = 1; i <= 100000; i++) {
        ll t = (k.x*i) / k.y + 1;
        if (Fraction(t, i) < rv) rv = Fraction(t, i);
    }
    return rv;
}
bool is_possible(Fraction k, int N) {
    int st = 1, en = 1, i, j;
    for (i = 0; i < fort.size(); i++) Q[en++] = fort[i];
    for (i = 1; i <= N; i++) {
        cnt[i] = conn[i].size();
        if (chk[i] != -1) chk[i] = 0;
    }
    while (st < en) {
        int t = Q[st];
        for (i = 0; i < conn[t].size(); i++) {
            int t2 = conn[t][i];
            cnt[t2]--;
            if (chk[t2] == 0 && Fraction(cnt[t2], conn[t2].size()) < k) {
                Q[en++] = t2;
                chk[t2] = 1;
            }
        }
        st++;
    }
    if (st != N + 1) return true;
    else return false;
}

void print(Fraction k, int N) {
    int st = 1, en = 1, i, j;
    for (i = 0; i < fort.size(); i++) Q[en++] = fort[i];
    for (i = 1; i <= N; i++) {
        cnt[i] = conn[i].size();
        if (chk[i] != -1) chk[i] = 0;
    }
    while (st < en) {
        int t = Q[st];
        for (i = 0; i < conn[t].size(); i++) {
            int t2 = conn[t][i];
            cnt[t2]--;
            if (chk[t2] == 0 && Fraction(cnt[t2], conn[t2].size()) < k) {
                Q[en++] = t2;
                chk[t2] = 1;
            }
        }
        st++;
    }

    int cnt = 0;
    for (i = 1; i <= N; i++) if (chk[i] == 0) cnt++;
    printf("%d\n", cnt);
    for (i = 1; i <= N; i++) if (chk[i] == 0) printf("%d ", i);
    return;
}
int main() {
    int N, M, K, i, j, t, t1, t2;
    scanf("%d %d %d", &N, &M, &K);
    for (i = 1; i <= K; i++) {
        scanf("%d", &t);
        chk[t] = -1;
        fort.push_back(t);
    }
    for (i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }

    Fraction st = Fraction(0, 1), en = Fraction(1, 1), mi, ans = Fraction(0,1);
    while (st <= en) {
        mi = Fraction(st.x*en.y + st.y*en.x, 2*st.y*en.y);
        mi = left_fraction(mi);
        if (mi < st) mi = st;

        if (is_possible(mi, N)) {
            ans = mi;
            st = right_fraction(mi);
        }
        else en = left_fraction(mi);
    }
    print(ans, N);
    return 0;
}
//*/