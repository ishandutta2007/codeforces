#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()

namespace Solution {

#define maxn 60100
#define eps (1e-9)
int n;
int a[maxn], v[maxn];

double caltime(double pos) {
    double ans = 0;
    for (int i = -1; ++i < n; ) {
        double dis = pos - a[i]; if (dis < -eps) dis = -dis;
        ans = max(ans, dis / v[i]);
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = -1; ++i < n; ) cin >> a[i];
    for (int i = -1; ++i < n; ) cin >> v[i];

    double l = 0, r = 1e9;
    int st = 1000;
    while ((r - l) > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double t1 = caltime(m1), t2 = caltime(m2);
        if (t1 > t2) l = m1;
        else r = m2;
        --st;
        if (st < 0) break;
    }
    cout << fixed << setprecision(10) << caltime(r);

    return 0;
}}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    return Solution::main();
}