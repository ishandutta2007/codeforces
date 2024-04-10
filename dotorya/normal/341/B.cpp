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

int it[IT_MAX * 2 + 50];
int pos[100050];
int in[100050];
int lis[100050];
void update(int pos, int n) {
    it[pos] = n;
    while (pos > 1) {
        pos /= 2;
        it[pos] = max(it[pos * 2], it[pos * 2 + 1]);
    }
    return;
}
int get_max(int p1, int p2) {
    int t = 0;
    if (p1 > p2) return 0;
    if (p1 == p2) return max(t, it[p1]);
    if (p1 % 2 == 1) {
        t = max(t,it[p1]);
        p1++;
    }
    if (p1 == p2) return max(t, it[p1]);
    if (p2 % 2 == 0) {
        t = max(t,it[p2]);
        p2--;
    }
    return max(t, get_max(p1 / 2, p2 / 2));
}

int main() {
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }

    int ans = 0;
    for (i = 1; i <= N; i++) {
        ans = max(ans, get_max(IT_MAX, IT_MAX + pos[i] - 1)+1);
        update(IT_MAX + pos[i], get_max(IT_MAX, IT_MAX + pos[i] - 1) + 1);
    }
    printf("%d", ans);
    return 0;
}
//*/