#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 2005;

int n, m;
int arr[MAX_N];
int f[MAX_N];
bool used[MAX_N];
int last = -1;
int cnt = 0;

#define get get228

void get() {
    ++cnt;
    if (cnt > 2 * n) {
        return;
    }
    scanf("%d", &last);
    --last;
    used[last] = true;
}

void go(int x) {
    ++cnt;
    used[x] = true;
    printf("%d\n", x + 1);
    fflush(stdout);
    get();
}

void play() {
    if (last != -1 && f[last] != -1 && !used[f[last]]) {
        go(f[last]);
        return;
    }

    int go = -1;
    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i] && f[i] != -1) {
            if (go == -1 || arr[go] < arr[i]) {
                go = i;
            }
        }
    }

    if (go != -1) {
        ::go(go);
        return;
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i]) {
            if (go == -1 || arr[go] < arr[i]) {
                go = i;
            }
        }
    }

    ::go(go);
}

int main() {
#ifdef CH_EGOR
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%d", &arr[i]);
        f[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        int v, u;
        scanf("%d%d", &v, &u);
        --v; --u;
        f[v] = u;
        f[u] = v;
    }

    int t;
    scanf("%d", &t);

    if (t == 2) {
        get();
    }

    for (int i = 0; i < n; ++i) {
        play();
    }

    return 0;
}