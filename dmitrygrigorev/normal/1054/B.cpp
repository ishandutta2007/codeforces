#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int mx = -1;
    for (int i=0; i < n; i++){
        if (v[i] > mx+1){
            cout << i+1;
            return 0;
        }
        mx = max(mx, v[i]);
    }
    cout << -1;

}