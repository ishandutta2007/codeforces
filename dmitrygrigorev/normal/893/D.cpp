#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int l = 0, r = 0;
    int ans = 0;
    for (int i=0; i < n; i++){
        if (v[i] != 0){
            l += v[i];
            r += v[i];
            r = min(r, d);
            if (l > d){
                cout << -1 << endl;
                return 0;
            }
        }
        else{
            if (r < 0){
                ans++;
                l = 0;
                r = d;
            }
            else{
                l = max((int) 0, l);
            }
        }
    }
    cout << ans << endl;
    return 0;
}