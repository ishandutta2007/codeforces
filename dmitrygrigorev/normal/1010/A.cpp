#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < n; i++) cin >> b[i];
    double L = 0, R = 1e10;
    for (int j=0; j < 200; j++){
        double M = (L+R)/2;
        double MM = M;
        bool ab = true;
        for (int i=0; i < n; i++){
            double nd = (M+ (double) m) / (double) a[i];
            if (nd > M){
                ab = false;
                break;
            }
            M -= nd;
            nd = (M + (double) m) / (double) b[(i+1)%n];
            if (nd > M){
                ab = false;
                break;
            }
            M -= nd;
        }
        if (ab) R = MM;
        else L = MM;
    }
    if (R > 2e9) cout << -1;
    else{
        cout.precision(20);
        cout << R;
    }
    return 0;
}