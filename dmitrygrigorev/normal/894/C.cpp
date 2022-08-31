#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int j=0; j < n; j++){
        if (v[j] % v[0] != 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << n*2 << endl;
    for (int i=0; i < n; i++){
        cout << v[i] << " ";
        cout << v[0] << " ";
    }
    return 0;
}