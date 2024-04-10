#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const T& x : v) {
        out << v << ", ";
    }
    out << "]";
    return out;
}

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

int main() {
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    LL t, n, a, b, k;
    cin >> t >> n >> a >> b >> k;
    
    LL l = 0;
    LL r = t;
    while(l < r){
        LL m = (l + r + 1) / 2;
        
        LL am = min(a, m);
        LL bm = min(b, m);
        LL sm = am * (n - n/2) + bm * (n/2);
        if(sm >= k * m) l = m; else r = m - 1;
    }
    cout << l << '\n';
    return 0;
}