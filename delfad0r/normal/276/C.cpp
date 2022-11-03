#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    sort(A.begin(), A.end());
    vector<LL> F(N + 1, 0);
    while(Q--) {
        int l, r;
        cin >> l >> r;
        F[l - 1]++;
        F[r]--;
    }
    for(int n = 1; n <= N; ++n) {
        F[n] += F[n - 1];
    }
    F.pop_back();
    sort(F.begin(), F.end());
    LL ans = 0;
    for(int n = 0; n < N; ++n) {
        ans += A[n] * F[n];
    }
    cout << ans << '\n';
}