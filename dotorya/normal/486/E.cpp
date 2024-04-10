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
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

int in[100050];
struct data {
    data() { data(0, -1); }
    data(int a, int b) {
        x = a, y = b;
    }
    int x, y;
    bool operator < (const data & l) const {
        if (x != l.x) return x < l.x;
        return y > l.y;
    }
} in2[100050];
int it[IT_MAX * 2 + 50];
int lis[100050];
void update(int pos, int x) {
    it[pos] = x;
    while (pos > 1) {
        pos /= 2;
        it[pos] = max(it[pos * 2], it[pos * 2 + 1]);
    }
    return;
}
int getmx(int p1, int p2) {
    if (p1 > p2) return 0;
    int t = 0;
    if (p1 == p2) return it[p1];
    if (p1 % 2 == 1) {
        t = max(it[p1], t);
        p1++;
    }
    if (p1 == p2) return max(t, it[p1]);
    if (p2 % 2 == 0) {
        t = max(it[p2], t);
        p2--;
    }
    return max(t, getmx(p1 / 2, p2 / 2));
}

bool lis_chk[100050];
data in3[100050];
int it2[IT_MAX * 2 + 50];
void update2(int pos, int x) {
    it2[pos] = x;
    while (pos > 1) {
        pos /= 2;
        it2[pos] = min(it2[pos * 2], it2[pos * 2 + 1]);
    }
    return;
}
int getmn(int p1, int p2) {
    if (p1 > p2) return IT_MAX;
    int t = IT_MAX;
    if (p1 == p2) return it2[p1];
    if (p1 % 2 == 1) {
        t = min(it2[p1], t);
        p1++;
    }
    if (p1 == p2) return min(t, it2[p1]);
    if (p2 % 2 == 0) {
        t = min(it2[p2], t);
        p2--;
    }
    return min(t, getmn(p1 / 2, p2 / 2));
}

vector <int> LISV[100050];
int out[100050];
int main() {
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &in[i]);
        in2[i] = data(in[i], i);
    }
    sort(in2, in2 + N);
    int mxlis = 0;
    for (i = 0; i < N; i++) {
        int t = in2[i].y;
        lis[t] = getmx(IT_MAX, IT_MAX + t - 1) + 1;
        update(IT_MAX + t, lis[t]);
        in3[t] = data(in[t], t);
        mxlis = max(mxlis, lis[t]);
    }
    sort(in3, in3 + N);
    for (i = 0; i < 2 * IT_MAX; i++) it2[i] = IT_MAX;
    for (i = N - 1; i >= 0; i--) {
        int t2 = in3[i].y;
        int t1 = lis[t2];
        if (t1 == mxlis || t1 + 1 == getmn(IT_MAX + t2 + 1, IT_MAX + N - 1)) {
            lis_chk[t2] = true;
            LISV[t1].push_back(t2);
            update2(IT_MAX + t2, t1);
        }
    }

    for (i = 0; i < N; i++) {
        if (lis_chk[i]) out[i] = 2;
        else out[i] = 1;
    }
    for (i = 1; i <= N; i++) {
        if (LISV[i].size() == 1) out[LISV[i][0]] = 3;
    }
    for (i = 0; i < N; i++) printf("%d", out[i]);
    return 0;
}
//*/