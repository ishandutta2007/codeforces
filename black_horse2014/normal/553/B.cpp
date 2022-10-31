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

#define N 55

int p[N];
LL val[N];

void calc(int n, LL m, int s) {
    if (n == 0 || m < 0) return;
    int i, j;
    for (i = n - 1; i >= n - 2; i--) {
        m -= val[i];
        if (m <= 0) {
            m += val[i];
            break;
        }
    }
    for (j = s; j < n - i + s; j++) p[j] = n - i + 2 * s - 1 - j;
    calc(i, m, n - i + s);
}

int main() {

    int n;
    LL m;

    val[0] = val[1] = 1;
    for (int i = 2; i <= 50; i++) val[i] = val[i - 1] + val[i - 2];

    cin >> n >> m;
    calc(n, m, 1);
    for (int i = 1; i <= n; i++) printf("%d%c", p[i], (i == n) ? '\n' : ' ');
    return 0;
}