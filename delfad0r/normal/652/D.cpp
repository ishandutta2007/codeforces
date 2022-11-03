#include <bits/stdc++.h>

using namespace std;

class fenwick_t {
    int N;
    vector<int> ft;
public:
    fenwick_t(int N) : N(N), ft(N + 1, 0) { }
    int query(int w) {
        int ans = 0;
        for(; w; w -= w & (-w)) {
            ans += ft[w];
        }
        return ans;
    }
    void update(int w, int v) {
        for(; w <= N; w += w & (-w)) {
            ft[w] += v;
        }
    }
};

typedef pair<int, int> II;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<II> S(N);
    fenwick_t F(2 * N);
    vector<int> coords;
    for(int n = 0; n < N; ++n) {
        cin >> S[n].first >> S[n].second;
        coords.push_back(S[n].first);
        coords.push_back(S[n].second);
    }
    sort(coords.begin(), coords.end());
    for(II& s : S) {
        s.first = lower_bound(coords.begin(), coords.end(), s.first) - coords.begin() + 1;
        s.second = lower_bound(coords.begin(), coords.end(), s.second) - coords.begin() + 1;
    }
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return S[i].first > S[j].first; });
    vector<int> ans(N);
    for(int i : idx) {
        ans[i] = F.query(S[i].second);
        F.update(S[i].second, 1);
    }
    for(int a : ans) {
        cout << a << '\n';
    }
}