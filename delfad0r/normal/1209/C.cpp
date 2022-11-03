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


void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> A(N), min_after(N);
    for(int n = N - 1; n >= 0; --n) {
        A[n] = S[n] - '0';
    }
    vector<int> ans(N);
    for(int k = 0; k <= 9; ++k) {
        int last1 = -1;
        for(int n = 0; n < N; ++n) {
            if(A[n] < k) {
                ans[n] = 1;
                last1 = n;
            } else if(A[n] > k) {
                ans[n] = 2;
            }
        }
        for(int n = 0; n < N; ++n) {
            if(A[n] == k) {
                if(n < last1) {
                    ans[n] = 2;
                } else {
                    ans[n] = 1;
                }
            }
        }
        vector<int> test;
        for(int d = 1; d <= 2; ++d) {
            for(int n = 0; n < N; ++n) {
                if(ans[n] == d) {
                    test.push_back(A[n]);
                }
            }
        }
        if(is_sorted(test.begin(), test.end())) {
            for(int n = 0; n < N; ++n) {
                cout << ans[n];
            }
            cout << "\n";
            return;
        }
    }
    cout << "-\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    
    
    return 0;
}