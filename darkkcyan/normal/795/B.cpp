#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ll pair<long, long>
#define xx first
#define yy second

bool cmp(const ll& u, const ll& v) {
    if (u.xx == v.xx) return u.yy < v.yy;
    return u.xx > v.xx;
}

#define maxn 101010
ll a[maxn], b[maxn];
long ans, tans;
int n, m; long d;
void pushit(int& i, int n, ll* a) {
    for (; i < n and d >= a[i].yy; ++i) {
        d -= a[i].yy;
        tans += a[i].xx;
    }
    ans = max(ans, tans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    for (int i = - 1; ++i < n; ) cin >> a[i].xx >> a[i].yy;
    for (int i = - 1; ++i < m; ) cin >> b[i].xx >> b[i].yy;
    sort(a, a + n, cmp);
    sort(b, b + m, cmp);
    ans = 0;
    ans += a[0].xx + b[0].xx;
    d -= a[0].yy + b[0].yy;
    if (d < 0) {
        cout << 0;
        exit(0);
    }
    tans = ans;
    int i = 1, f = 1;
    pushit(i, n, a);
    pushit(f, m, b);
    for (; --i >= 1; ) {
        d += a[i].yy;
        tans -= a[i].xx;
        pushit(f, m, b);
    }
    cout << ans;
    return 0;
}