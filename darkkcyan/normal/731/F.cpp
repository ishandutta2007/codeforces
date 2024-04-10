#include <bits/stdc++.h>

using namespace std;

#define ve vector
int n;
ve<int> a;
void read() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
}

ve<int> cnt;
void preprocess() {
    sort(a.begin(), a.end());
    cnt.resize(2 * a.back() + 1);
    for (int i = 0; i < n; ++i) cnt[a[i]] ++;
    for (int i = a.back(); i >= 0; --i) cnt[i] += cnt[i + 1];
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
}

long long process() {
    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
        long long x = a[i];
        long long tans = 0;
        for (long long f = x; f + x < (long long) cnt.size(); f += x) {
            tans += f * (long long)(cnt[f] - cnt[f + x]);
        }
        ans = max(ans, tans);
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("file.inp", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    read();
    preprocess();
    cout << process();
    return 0;
}