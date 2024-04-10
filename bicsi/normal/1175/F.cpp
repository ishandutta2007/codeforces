#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

long long Divide(int n, vector<int>& v, int b, int e, vector<int>& dp, vector<int>& cnt) {
    if (b == e) return 0;
    int m = (b + e) / 2;
    long long ret = Divide(n, v, b, m, dp, cnt) + Divide(n, v, m + 1, e, dp, cnt);
    
    dp[m + 1] = v[m + 1];
    for (int i = m + 2; i <= e; ++i)
        dp[i] = max(dp[i - 1], v[i]);
    dp[m] = v[m];
    for (int i = m - 1; i >= b; --i)
        dp[i] = max(dp[i + 1], v[i]);


    // if (l > m) return ret;
    /*
    cerr << "AT: ";
    for (int i = b; i <= e; ++i) {
        cerr << v[i] << " ";
        if (i == m) cerr << "| ";
    }
    cerr << endl;
    */
    cnt[0] = 1;
    int l = m + 1;
    for (int r = m + 1; r <= e; ++r) {
        while (l > b && dp[l - 1] < dp[r] && cnt[v[l - 1]] == 0) {
            cnt[v[l - 1]] += 1;
            --l;
        }
        cnt[v[r]] += 1;
        while (cnt[v[r]] >= 2) {
            if (l == m) { r = e + 1; break; }
            cnt[v[l]] -= 1;
            ++l;
        } 
        if (r > e) break;

        // cerr << r - m << ": " << l - b + 1 << endl;
        int coresp = r - dp[r] + 1;
        if (coresp <= m && coresp >= l) {
            ret += 1;
            /*
            cerr << "FOUND: ";
            for (int i = coresp; i <= r; ++i) {
                cerr << v[i] << " ";
            }
            cerr << endl;
            */
        }
    }
    for (int i = b; i <= e; ++i)
        cnt[v[i]] = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;

    long long ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] == 1)
            ans += 1;
    }
    int newn = 1;
    while (newn < n) newn *= 2;
    v.resize(newn);
    vector<int> dp(newn);
    vector<int> cnt(n + 1, 0);
    ans += Divide(n, v, 0, newn - 1, dp, cnt);
    //cerr << "REVERSING" << endl;
    reverse(v.begin(), v.end());
    ans += Divide(n, v, 0, newn - 1, dp, cnt);
    cout << ans << endl;

    return 0;
}