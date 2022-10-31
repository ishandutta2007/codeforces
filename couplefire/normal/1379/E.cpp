#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
 
 
bool check(int n) {
    return __builtin_popcount(n + 1) == 1;
}
 
vector<int> res;
 
bool solve(int n, int k, int par) {
    if (n == 11 && k == 3) {
        res[10] = par;
        res[9] = 10;
        res[8] = 9;
        res[7] = 9;
        return solve(7, 2, 10);
    }
 
    if (k <= 1) {
        if ((!check(n) && k == 0) || (check(n) && k == 1)) return false;
        res[0] = par;
        for(int i = 1;i < n;i++) res[i] = (i - 1) / 2;
 
        return true;
    }
 
    if (k == 2 && check(n - 2)) {
        res[n - 1] = par;
        res[n - 2] = n - 1;
        res[n - 3] = n - 2;
        res[n - 4] = n - 2;
        return solve(n - 4, k - 1, n - 1);
    }
 
    res[n - 1] = par;
    res[n - 2] = n - 1;
    return solve(n - 2, k - 1, n - 1);
}
 
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 0) {
        cout << "YES" << endl << 0;
        return 0;
    }
 
    if (n % 2 == 0 || (n - 3) / 2 < k || (k == 0 && !check(n)) || (k == 1 && check(n)) || (k == 2 && n == 9)) {
        cout << "NO";
        return 0;
    }
 
    res.resize(n);
 
 
    bool temp = solve(n, k, -1);
 
    if (!temp) cout << "Bad" << endl;
 
    cout << "YES" << endl;
    for(int i : res) cout << i + 1 << " ";
}