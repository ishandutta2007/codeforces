#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k; cin >> n >> k;

    vector<int> fst(n, -1), lst(n, -1);
    for (int i = 0; i < k; ++i) {
        int now; cin >> now; --now;
        if (fst[now] == -1) fst[now] = lst[now] = i;
        else lst[now] = i;
    }
    /*    
    for (int i = 0; i < n; ++i) {
        cerr << fst[i] << " " << lst[i] << endl;
    }*/
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (fst[i] == -1) ans += 1;
        if (i + 1 < n && (fst[i] == -1 || fst[i + 1] == -1 || lst[i + 1] < fst[i])) ans += 1;
        if (i > 0 && (fst[i] == -1 || fst[i - 1] == -1 || lst[i - 1] < fst[i])) ans += 1;
        // cerr << i << " -> " << ans << endl;
    }
    cout << ans << endl;


    return 0;
}