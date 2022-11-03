#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
ll A[100100];
ll L[100100], R[100100], Ls[100100], Rs[100100];

int main() {
    cin >> N;
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    for(ll n = 0, k = 0; n < N; ++n) {
        if(k > A[n]) {
            L[n] = k - A[n];
        } else {
            k = A[n];
        }
        ++k;
        if(n > 0) {
            Ls[n] = L[n] + Ls[n - 1];
        }
    }
    for(ll n = N - 1, k = 0; n >= 0; -- n) {
        if(k > A[n]) {
            R[n] = k - A[n];
        } else {
            k = A[n];
        }
        ++k;
        if(n < N - 1) {
            Rs[n] = R[n] + Rs[n + 1];
        }
    }
    ll ans = 1LL << 60;
    for(int n = 0; n < N; ++n) {
        ans = min(ans, max(L[n], R[n]) + Ls[max(0, n - 1)] + Rs[min(N - 1, n + 1)]);
    }
    cout << ans << '\n';
}