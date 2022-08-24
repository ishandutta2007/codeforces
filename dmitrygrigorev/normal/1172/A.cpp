#include <bits/stdc++.h>

#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < n; i++) cin >> b[i];
    int pos[n];
    for (int i=0; i < n; i++){
        if (a[i] > 0) pos[a[i]-1]=-1;
        if (b[i] > 0) pos[b[i]-1] = i;
    }
    if (pos[0] != -1){
        bool can = true;
        for (int i=1; pos[0]+i < n; i++){
            if (pos[i] == pos[0]+i) continue;
            can = false;
        }
        for (int i=n-pos[0]; i < n; i++){
            if (pos[i] == -1) continue;
            if (pos[i] < i-(n-pos[0])) continue;
            can = false;
        }
        if (can){
            cout << pos[0];
            return 0;
        }
    }
    int u = 0;
    for (int i=0; i < n; i++){
        if (b[i] == 0) continue;
        u = max(u, i-b[i]+2);
    }
    cout << n+u;
}