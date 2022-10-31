#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
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

typedef pair<int, int> pii;
typedef long long LL;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define N 200005

#define X first
#define Y second
int n;
int a[N], b[N], c[N], id[N], bit[N];
bool cmp(int i, int j) {
    return c[i] < c[j];
}

int main() {

    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
        c[i] = a[i] - (n - i - 1);
    }
    for (i = 0; i < n; i++) id[i] = i;
    sort(id, id + n, cmp);
    for (i = 0; i < n - 1; i++) {
        int d = id[i], _d = id[i + 1];
        if (c[d] == c[_d]) {
            puts(":(");
            return 0;
        }
    }
    for (i = n - 1; i >= 0; i--) {
        int j = id[i];
        bit[i] = a[j] - (i - j);
    }
    for (i = 0; i < n - 1; i++) if (bit[i] > bit[i + 1]) break;
    if (i < n - 1) {
        puts(":(");
        return 0;
    }
    for (i = 0; i < n; i++) printf("%d%c", bit[i], i < n - 1 ? ' ' : '\n');
    return 0;
}