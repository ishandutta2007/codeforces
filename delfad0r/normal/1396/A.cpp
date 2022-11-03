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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<LL> A(N);
    for(auto& a : A) {
        cin >> a;
    }
    cout << "1 1\n";
    cout << (-A[0]) << "\n";
    A[0] = 0;
    if(N == 1) {
        cout << "1 1\n 0\n1 1\n0\n";
        return 0;
    }
    vector<LL> X(N, 0), Y(N, 0);
    for(int n = 1; n < N; ++n) {
        Y[n] = -(A[n] % N);
        X[n] = (A[n] + Y[n]) / N - Y[n];
    }
    cout << "1 " << N << "\n";
    for(int n = 0; n < N; ++n) {
        cout << -(X[n] * N) << " ";
        A[n] -= X[n] * N;
    }
    cout << "\n 2 " << N << "\n";
    for(int n = 1; n < N; ++n) {
        cout << -(Y[n] * (N - 1)) << " ";
        assert(A[n] - Y[n] * (N - 1) == 0);
    }    
    
    return 0;
}