#include <bits/stdc++.h>

using namespace std;

using LL = long long;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

LL dpl[1000100][2]; //kill the boss in room (n-1), w/ or w/o jumping to next room
LL dpr[1000100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    LL r1, r2, r3, d;
    cin >> N >> r1 >> r2 >> r3 >> d;
    vector<LL> A(N);
    for(auto& a : A) {
        cin >> a;
    }
    dpl[0][0] = -d;
    dpl[0][1] = 1LL << 60; // inf
    for(int n = 0; n < N; ++n) {
        dpl[n + 1][0] = min(dpl[n][0] + d + A[n] * r1 + r3, dpl[n][1] + d + min({(A[n] + 2) * r1, A[n] * r1 + r3, r2 + r1}));
        dpl[n + 1][1] = min(dpl[n][0], dpl[n][1]) + d + min({(A[n] + 2) * r1, A[n] * r1 + r3, r2 + r1}) + d + d;
    }
    dpr[N - 1] = min({A[N - 1] * r1 + r3, 2 * d + min({(A[N - 1] + 2) * r1, A[N - 1] * r1 + r3, r2 + r1})});
    for(int n = N - 2; n >= 0; --n) {
        dpr[n] = dpr[n + 1] + 2 * d + min({(A[n] + 2) * r1, A[n] * r1 + r3, r2 + r1});
    }
    /*for(int n = 0; n <= N; ++n) {
        cout << dpl[n][0] << " ";
    }
    cout << "\n";
    for(int n = 0; n <= N; ++n) {
        cout << dpl[n][1] << " ";
    }
    cout << "\n";
    for(int n = 0; n <= N; ++n) {
        cout << dpr[n] << " ";
    }
    cout << "\n";*/
    LL ans = min(dpl[N][0], dpr[0]);
    for(int n = 0; n < N; ++n) {
        ans = min(ans, dpl[n][0] + d + dpr[n]);
    }
    cout << ans << "\n";
    
    return 0;
}