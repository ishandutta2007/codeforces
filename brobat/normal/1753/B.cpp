#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, x;
    cin >> n >> x;
    int N = 500100;
    vector <int> occ(N, 0);
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        if(t < x) occ[t]++;
    }
    // int M = 11;
    // vector <int> f(M);
    // f[0] = 1;
    // for(int i = 1; i < M; i++) {
    //     f[i] = f[i - 1] * i;
    // }
    for(int i = 0; i < N;) {
        if(occ[i] < i + 1) {
            i++;
            continue;
        }
        int cnt = 0;
        int prod = 1;
        for(int j = i + 1; j < i + 15; j++) {
            if(prod * j > occ[i]) break;
            cnt++;
            prod *= j;
        }
        occ[i + cnt]++;
        occ[i] -= prod;
    }
    bool pos = true;
    for(int i = 0; i < x; i++) {
        if(occ[i] > 0) pos = false;
    }
    cout << (pos ? "Yes" : "No") << '\n';
    
    return 0;
}