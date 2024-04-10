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

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto& a : A) {
        cin >> a;
    }
    int p = -1;
    for(int q = 0; ; ++q) {
        int j = -1;
        for(int i = 0; i < N; ++i) {
            if(i == p) {
                continue;
            }
            if(j == -1 or A[i] > A[j]) {
                j = i;
            }
        }
        if(j == -1 or A[j] == 0) {
            cout << ((q & 1) ? ("T\n") : ("HL\n"));
            return;
        }
        --A[j];
        p = j;
    }
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