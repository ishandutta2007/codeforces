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

void solve(){
    LL n , l, r, x, y, z, b1, b2;
    cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
    vector<unsigned long long> b(n+1);
    vector<LL> a(n+1);
    b[1] = b1;
    b[2] = b2;
    for(int i=3; i<=n; i++) b[i] = (b[i-2] * x % (1LL<<32) + b[i-1] * y % (1LL<<32) + z) % (1LL<<32);
    for(int i=1; i<=n; i++) a[i] = (b[i] % (r - l + 1)) + l;
    
    //~ for(int i=1; i<=n; i++) cout << a[i] << ' ';
    //~ cout << '\n';
    
    LL great = l - 1;
    LL ans = max(r, -l) * max(r, -l) + 1;
    for(int i=n; i>=1; i--){
        if(a[i] < great) ans = min(ans, a[i] * great);
        great = max(great, a[i]);
    }
    
    great = -r - 1;
    vector<LL> c(n+1);
    for(int i=1; i<=n; i++) c[i] = -a[n+1-i];
    for(int i=n; i>=1; i--){
        if(c[i] < great) ans = min(ans, c[i] * great);
        great = max(great, c[i]);
    }
    
    if(ans == max(r, -l) * max(r, -l) + 1) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
}

int main() {
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    for(int tt=1; tt<=t; tt++){
        solve();
    }
    
    return 0;
}