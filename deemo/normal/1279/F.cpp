#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

const int MAXN = 1e6 + 10;

int n, k, ln;
string s;
pair<ll, int> d[MAXN];

bool is_lower(char c){return 'a' <= c && c <= 'z';}

pair<ll, int> get(int mid) {
    for (int i = 1; i <= n; i++) {
        d[i] = {d[i-1].F + int(is_lower(s[i-1])), d[i-1].S};
        d[i] = min(d[i], {d[max(0, i-ln)].F + mid, 1 + d[max(0, i-ln)].S});
    }
    return d[n];
}

int solve() {
    int lo = -1, hi = n + 2;
    while (hi-lo>1){
        int mid = hi+lo>>1;
        if (get(mid).S > k)
            lo = mid;
        else
            hi = mid;
    }
    auto x = get(hi);
    return x.F - 1ll*k*hi;
}

int main() {
    cin >> n >> k >> ln;
    cin >> s;
    int ans = solve();
    for (int i = 0; i < n; i++)
        if (is_lower(s[i]))
            s[i] -= 'a' - 'A';
        else
            s[i] += 'a' - 'A';
    ans = min(ans, solve());
    cout << ans << "\n";
    return 0;
}