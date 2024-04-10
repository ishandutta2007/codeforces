#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    unordered_map<int, int> M;
    vector<int> L(N), R(N);
    for(int n = 0; n < N; ++n) {
        L[n] = ++M[A[n]];
    }
    M.clear();
    for(int n = N - 1; n >= 0; --n) {
        R[n] = ++M[A[n]];
    }
    fenwick_t F(N);
    LL ans = 0;
    for(int n = N - 1; n >= 0; --n) {
        ans += F.query(L[n] - 1);
        F.update(R[n], 1);
    }
    cout << ans << endl;
}