#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    LL N;
    cin >> N;
    vector<LL> A(N);
    LL s = 0;
    for(auto& x : A) {
        cin >> x;
        s += x;
    }
    vector<LL> D(N, 0);
    LL u = 0;
    for(int i = 1; i < N; ++i) {
        D[i] = A[i] - A[i - 1];
        u = (u + D[i] * i) % N;
    }
    u = (N * (N - 1) / 2 - u) % N;
    if(u == 0) {
        u = N;
    }
    
    assert((s - N * (N - 1) / 2 + N - u) % N == 0);
    LL b = (s - N * (N - 1) / 2 + N - u) / N;
    for(int i = 0; i < N; ++i) {
        if(i == u) {
            --b;
        }
        cout << (b + i) << " ";
    }
    cout << "\n";
}