#include <bits/stdc++.h>
#define int long double
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) v[i]--;
    for (int i=0; i < n; i++){
        if (v[v[v[i]]] == i){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}