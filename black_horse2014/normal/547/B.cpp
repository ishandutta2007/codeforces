#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

#define pb push_back

#define X first
#define Y second

#define N 200005

int a[N], prv[N], nxt[N], val[N];
int main() {


    int n, i, j, l;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) {
        for (j = i - 1; j >= 0 && a[j] >= a[i]; j = prv[j]);
        prv[i] = j;
    }

    for (i = n - 1; i >= 0; i--) {
        for (j = i + 1; j < n && a[j] >= a[i]; j = nxt[j]);
        nxt[i] = j;
    }

    for (i = 0; i < n; i++) {
        l = nxt[i] - prv[i] - 1;
        val[l] = max(val[l], a[i]);
    }

    for (i = n; i > 0; i--) val[i] = max(val[i], val[i + 1]);
    for (i = 1; i <= n; i++) printf("%d%c", val[i], (i == n) ? '\n' : ' ');

    return 0;
}