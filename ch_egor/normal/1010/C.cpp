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

const int MAX_N = 100 * 1000 + 228;

int n, k;
int arr[MAX_N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    int gc = k;
    for (int i = 0; i < n; ++i) gc = gcd(arr[i], gc);

    printf("%d\n", k / gc);
    for (int i = 0; i < k; i += gc) printf("%d ", i);

    return 0;
}