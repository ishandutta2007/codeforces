#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 100111, inf = 1011111111;

int n, s, A[max_n], B[max_n], C[max_n];
pair<int, pair<int, int> > b[max_n], p[max_n];
long long ans;

long long solve() {
    sort(b, b + n);
    reverse(b, b + n);
    long long tot = 0;
    for (int i = 0; i < n; ++i) {
        tot += b[i].second.second;
        //cout << b[i].second.second << " " << b[i].second.first << " " << b[i].first << endl;
    }
    int o = (s - tot % s) % s;
    //cout << "#" << tot << " " << s << endl;
    tot = (tot + s - 1) / s;
    long long mx = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += 1LL * b[i].second.first * b[i].second.second;
        mx += 1LL * (b[i].second.first + b[i].first) * b[i].second.second;
    }
    int pos = 0;
    while (tot) {
        //cout << tot << " " << sum << endl;
        mx = max(mx, sum);
        int x = s;
        --tot;
        while (pos < n) {
            int mnx = 0;
            if (b[pos].first < 0) {
                mnx = o;
            }
            if (x <= mnx) {
                break;
            }
            int mn = min(x - mnx, b[pos].second.second);
            b[pos].second.second -= mn;
            x -= mn;
            sum += 1LL * mn * b[pos].first;
            //cout << pos << " += " << mn << "*" << b[pos].first << endl;
            if (b[pos].second.second == 0) {
                ++pos;
            }
        }
        if (x) {
            mx = max(mx, sum);
            break;
        }
    }
    return mx;
}

long long triv() {
    long long tot = 0, all = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        p[i] = {B[i], {C[i], A[i]}};
        swap(p[i].first, p[i].second.first);
        p[i].first -= p[i].second.first;
        all += p[i].second.second;
    }
    sort(p, p + n);
    reverse(p, p + n);
    tot = (all + s - 1) / s;
    for (int a = 0; a <= tot; ++a) {
        long long ca = 1LL * a * s, cb = 1LL * (tot - a) * s;
        for (int i = max(0LL, all - ca); i <= cb; ++i) {
            long long res = 0;
            int cnt = i;
            for (int j = 0; j < n; ++j) {
                int t2 = min(cnt, p[j].second.second);
                cnt -= t2;
                res += 1LL * p[j].first * t2 + 1LL * p[j].second.first * p[j].second.second;
            }
            //cout << a << " " << i << ": " << res << endl;
            ans = max(ans, res);
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &s) == 2) {
        ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &A[i], &B[i], &C[i]);
            b[i] = {B[i], {C[i], A[i]}};
            int k = b[i].second.second / s;
            --k;
            k = max(k, 0);
            b[i].second.second -= 1LL * k * s;
            long long pl = 1LL * k * s;
            pl *= max(b[i].first, b[i].second.first);
            ans += pl;
            swap(b[i].first, b[i].second.first);
            b[i].first -= b[i].second.first;
        }
        ans += solve();
        printf("%I64d\n", ans);
    }
    return 0;
}