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
    
    LL N;
    cin >> N;
    LL g = N;
    for(LL d = 2; d * d <= N; ++d) {
        if(N % d == 0) {
            g = gcd(gcd(d, N / d), g);
        }
    }
    
    cout << g << "\n";
    
    
    return 0;
}