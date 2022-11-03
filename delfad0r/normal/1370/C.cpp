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

const string WIN = "Ashishgup\n";
const string LOSE = "FastestFinger\n" ;

bool is_prime(int n) {
    if(n == 1) {
        return false;
    }
    for(int q = 2; q * q <= n; ++q) {
        if(n % q == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int N;
    cin >> N;
    if(N == 1) {
        cout << LOSE;
        return;
    }
    if(N == 2) {
        cout << WIN;
        return;
    }
    int f2 = 0;
    int m = N;
    while(true) {
        if(m & 1) {
            break;
        } else {
            ++f2;
            m /= 2;
        }
    }
    if(m == 1) {
        cout << LOSE;
        return;
    }
    if(f2 != 1) {
        cout << WIN;
        return;
    }
    if(is_prime(N / 2)) {
        cout << LOSE;
    } else {
        cout << WIN;
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