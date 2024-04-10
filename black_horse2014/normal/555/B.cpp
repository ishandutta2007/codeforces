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

LL a[N], aa[N], L[N], R[N];
int b[N];
int st[N], en[N], id[N];

set<PII> S;
set<PII> :: iterator it;

VI V[N];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int main() {

    int i, j, k, n, m, r;
    LL maxl, minl;

    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++) scanf("%I64d%I64d", &L[i], &R[i]);
    for (i = 0; i < m; i++) scanf("%I64d", &a[i]), aa[i] = a[i];

    if (m < n - 1) {
        puts("No");
        return 0;
    }

    for (i = 0; i < m; i++) id[i] = i;
    sort(id, id + m, cmp);
    sort(aa, aa + m);

    for (i = 0; i < n - 1; i++) {
        maxl = R[i + 1] - L[i];
        minl = L[i + 1] - R[i];
        st[i] = lower_bound(aa, aa + m, minl) - aa;
        en[i] = upper_bound(aa, aa + m, maxl) - aa - 1;
        if (st[i] > en[i]) break;
    }

    if (i < n - 1) {
        puts("No");
        return 0;
    }

    for (i = 0; i < n - 1; i++) V[st[i]].pb(i);
    for (i = 0; i < m; i++) {
        for (j = 0; j < V[i].size(); j++) {
            k = V[i][j];
            S.insert(PII(en[k], k));
        }
        if (!S.empty()) {
            it = S.begin();
            r = it->Y;
            if (en[r] < i) break;
            S.erase(it);
            b[r] = id[i];
        }
    }

    if (i < m) puts("No");
    else {
        puts("Yes");
        for (i = 0; i < n - 1; i++) printf("%d%c", b[i] + 1, (i == n - 2) ? '\n' : ' ');
    }

    return 0;
}