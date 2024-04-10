#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n;
    cin >> n;
    int ans = 0;
    int L = -4*45, R = 45;
    map<int, int> vls;
    for (int i=L; i <= R; i++) vls[i] = 1e18;
    for (int i=0; i < 100; i++){
        for (int j=0; j < 100; j++){
            for (int k=0; k < 100; k++){
                int nm = -4*i + 5*j + 45*k;
                if (nm >= L && nm <= R) vls[nm] = min(vls[nm], i+j+k);
            }
        }
    }
    for (int i=L; i <= R; i++){
        if (vls[i] <= n){
            ans++;
        }
    }
    for (int i=L; i < L+4; i++){
        int op = vls[i];
        if (op < n) ans += n - op;
    }
    for (int i=R-44; i <= R; i++){
        int op = vls[i];
        if (op < n) ans += n - op;
    }
    cout << ans;
    return 0;
}