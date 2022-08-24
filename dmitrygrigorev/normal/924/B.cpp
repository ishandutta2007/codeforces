#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int bin(vector<int> &v, int num){
    int L = -1, R = v.size();
    while (R-L>1){
        int M = (L+R) / 2;
        if (v[M] <= num) L = M;
        else R = M;
    }
    return L;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    int n, u;
    cin >> n >> u;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    double ans = 0;
    bool able = false;
    for (int i=0; i < n-2; i++){
        int ind = bin(v, v[i] + u);
        if (ind < i+2) continue;
        able = true;
        double A = v[ind] - v[i+1];
        double B = v[ind] - v[i];
        ans = max(ans, A/B);
    }
    if (!able) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}