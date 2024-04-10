#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;


template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const T& x : v) {
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
    vector<int> A(N), B(N);
    string S;
    cin >> S;
    for(int n = 0; n < N; ++n) {
        cin >> A[n] >> B[n];
    }
    
    int ans = 0;
    for(int n = 0; n < N; ++n) {
        if(S[n] == '1') {
            ++ans;
        }
    }
    for(int t = 1; t <= 100000; ++t) {
        int curr = 0;
        for(int n = 0; n < N; ++n) {
            if(t >= B[n] and (t - B[n]) % A[n] == 0) {
                S[n] = (S[n] == '0') ? ('1') : ('0');
            }
            if(S[n] == '1') {
                ++curr;
            }
        }
        ans = max(ans, curr);
    }
    cout << ans << "\n";
    return 0;
}