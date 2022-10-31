#include <bits/stdc++.h>
using namespace std;

int a[1000010], n, b[1000010];

int v1[1000010]={}, v2[1000010]={};
int d1[1000010]={}, d2[1000010]={}, d[1000010]={};

void add(int x, int v) {
    for(; x <= n; x += (x&-x)) d[x] += v;
}

int query(int x) {
    int r = 0;
    for(; x >= 1; x -= (x&-x)) r += d[x];
    return r;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) { scanf("%d", &a[i]); b[i] = a[i]; }
    sort(b, b + n);
    int m = unique(b, b + n) - b;
    for(int i = 0; i < n; ++i) a[i] = lower_bound(b, b + m, a[i]) - b;

    //for(int i = 0; i < n; ++i) printf("%d ", a[i]); puts("");
    for(int i = 0; i < n; ++i) {
        d1[i] = (++v1[a[i]]);
    }

    for(int i = n - 1; i >= 0; --i) {
        d2[i] = (++v2[a[i]]);
        add(d2[i], 1);
    }

    //sort(d1, d1 + n);
    //sort(d2, d2 + n);

    //for(int i = 0; i < n; ++i) printf("%d ", d1[i]); puts("");
    //for(int i = 0; i < n; ++i) printf("%d ", d2[i]); puts("");

    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        add(d2[i], -1);
        ans += query(d1[i] - 1);
    }
    cout << ans << endl;

    return 0;
}