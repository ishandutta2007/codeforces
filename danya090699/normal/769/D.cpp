#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cnt[a]++;
    }
    vector<pair<int, int>> vcnt;
    for (pair<int, int> pa : cnt) {
        vcnt.push_back(pa);
    }
    long long ans = 0;
    for (int i = 0; i < vcnt.size(); i++) {
        for (int j = i; j < vcnt.size(); j++) {
            int a = vcnt[i].first;
            int b = vcnt[j].first;
            if (__builtin_popcount(a ^ b) == k) {
                if (i == j) {
                    ans += vcnt[i].second * 1ll * (vcnt[j].second - 1) / 2;
                } else {
                    ans += vcnt[i].second * 1ll * vcnt[j].second;
                }
            }
        }
    }
    cout << ans;
}