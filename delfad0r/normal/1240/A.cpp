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
    vector<LL> P(N);
    for(auto& i : P) {
        cin >> i;
        i /= 100;
    }
    sort(P.begin(), P.end(), greater<LL>());
    LL x, y, a, b;
    cin >> x >> a >> y >> b;
    vector<LL> S(N, 0);
    for(int i = a - 1; i < N; i += a) {
        S[i] += x;
    }
    for(int i = b - 1; i < N; i += b) {
        S[i] += y;
    }
    LL K;
    cin >> K;
    int lo = 0, hi = N + 1;
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        vector<LL> u;
        for(int n = 0; n < mid; ++n) {
            if(S[n] > 0) {
                u.push_back(S[n]);
            }
        }
        sort(u.begin(), u.end(), greater<LL>());
        LL T = 0;
        for(int n = 0; n < int(u.size()); ++n) {
            T += P[n] * u[n];
        }
        if(T >= K) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    if(hi > N) {
        cout << "-1" << "\n";
    } else {
        cout << hi << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int Q;
    cin >> Q;
    while(Q--) {
        solve();
    }
    
    return 0;
}