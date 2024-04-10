#include<bits/stdc++.h>
using namespace std;
const int SIZE = 200001;
long long bit[SIZE], bit2[SIZE];
long long ins(int x, long long v) {
    for(; x < SIZE; x += x & -x) {
        bit[x] += v;
        bit2[x] ++;
    }
}
pair<long long, int> qq(int x) {
    long long res = 0;
    int cnt = 0;
    for(; x; x -= x & -x) {
        res += bit[x];
        cnt += bit2[x];
    }
    return make_pair(res, cnt);
}
pair<int, int>a[SIZE];
int d[SIZE];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i].first);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i].second);
        d[i] = a[i].second;
    }
    sort(a, a + n);
    sort(d, d + n);
    int m = unique(d, d + n) - d;
    long long an = 0;
    for(int i = 0; i < n; i++) {
        int me = lower_bound(d, d + m, a[i].second) - d + 1;
        auto ret = qq(me);
        an += (long long)a[i].first * ret.second - ret.first;
        ins(me, a[i].first);
    }   
    printf("%lld\n", an);
}
int main() {
    solve();
    return 0;
}