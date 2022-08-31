#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n;
    cin >> n;
    vector<int> v(2*n);
    for (int i=0; i < 2*n; i++) cin >> v[i];
    int ans = 0;
    for (int i=0; i < 2*n; i += 2){
        for (int j=i+1; j < 2*n; j++){
            if (v[j] == v[i]){
                ans += j - i - 1;
                vector<int> x;
                for (int p=0; p < 2*n; p++){
                    if (p == i+1) x.push_back(v[j]);
                    if (p != j) x.push_back(v[p]);
                }
                v = x;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}