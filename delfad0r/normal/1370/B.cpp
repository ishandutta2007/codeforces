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
    vector<int> O, E;
    for(int n = 0; n < 2 * N; ++n) {
        int a;
        cin >> a;
        if(a & 1) {
            O.push_back(n + 1);
        } else {
            E.push_back(n + 1);
        }
    }
    for(int n = 0; n < N - 1; ++n) {
        if(O.size() >= 2) {
            cout << O.back();
            O.pop_back();
            cout << " " << O.back() << "\n";
            O.pop_back();
        } else {
            cout << E.back();
            E.pop_back();
            cout << " " << E.back() << "\n";
            E.pop_back();
        }
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