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
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto& a : A) {
        cin >> a;
    }
    int lo = 0, hi = 1e9;
    while(lo + 1 < hi) {
        int m = (lo + hi) / 2;
        auto f = [&](vector<int>& v, int i0) {
            for(int i = i0; i < N; ++i) {
                if(A[i] <= m) {
                    v.push_back(i);
                    ++i;
                    if(i < N) {
                        v.push_back(i);
                    }
                }
            }
            return int(v.size()) >= K;
        };
        vector<int> v;
        if(f(v, 0)) {
            hi = m;
        } else {
            v = {0};
            if(f(v, 1)) {
                hi = m;
            } else {
                lo = m;
            }
        }
    }
    cout << hi << "\n";
    
    return 0;
}