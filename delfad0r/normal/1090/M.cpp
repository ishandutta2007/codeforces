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
    
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    a[0] = -1;
    for(int i=1; i<=n; i++) cin >> a[i];
    
    int curr = 0;
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(a[i] == a[i-1]) curr = 1; else curr++;
        ans = max(ans, curr);
    }
    cout << ans << '\n';
    return 0;
}