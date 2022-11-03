#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    --K;
    vector<int> A(N);
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    sort(A.begin(), A.end());
    int a = A[K / N];
    long long u = 0, v = 0;
    for(int n = 0; n < N; ++n) {
        if(A[n] == a) {
            ++u;
        } else if(A[n] < a) {
            ++v;
        }
    }
    cout << a << ' ' << A[(K - v * N) / u] << '\n';
}