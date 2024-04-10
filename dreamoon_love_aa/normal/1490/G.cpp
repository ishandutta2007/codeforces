#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 200000;
const long long INF = 1e12;
int a[SIZE];
long long prefix_sum[SIZE];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long ma = -INF;
    vector<pair<long long, int>> stk;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(!i) { prefix_sum[i] = a[i]; }
        else { prefix_sum[i] = prefix_sum[i - 1] + a[i]; }
        if(prefix_sum[i] > ma) {
            stk.PB(MP(prefix_sum[i], i));
            ma = prefix_sum[i];
        }
    }
    long long d = prefix_sum[n - 1];
    while(m--) {
        long long x;
        scanf("%lld", &x);
        int it = lower_bound(stk.begin(), stk.end(), MP(x, 0)) - stk.begin();
        if(it < SZ(stk)) {
            printf("%d\n", stk[it].second);
            continue;
        }
        if(d <= 0) {
            puts("-1");
            continue;
        }
        long long round_num = (x - ma - 1) / d + 1;
        it = lower_bound(stk.begin(), stk.end(), MP(x - d * round_num, 0)) - stk.begin();
        printf("%lld\n", stk[it].second + round_num * n);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}