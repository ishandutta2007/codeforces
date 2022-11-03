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


LL F(LL a, LL b, LL n) {
    if(n == 0) {
        return a;
    } else if(n == 1) {
        return b;
    } else if(n == 2) {
        return a ^ b;
    } else {
        return F(a, b, n % 3);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        LL a, b, n;
        cin >> a >> b >> n;
        cout << F(a, b, n) << "\n";
    }
    
    return 0;
}