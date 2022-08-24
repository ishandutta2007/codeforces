#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    //freopen("input.txt", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> f(n), s(n);
    for (int i=0; i < n; i++) cin >> f[i];
    for (int i=0; i < n; i++) cin >> s[i];
    vector<int> d;
    for (int i=0; i < n; i++){
        d.push_back(abs(f[i] - s[i]));
    }
    for (int i=0; i < a+b; i++){
        int mx = -1, wh = 0;
        for (int j=0; j < n; j++){
            if (d[j] > mx){
                mx = d[j];
                wh = j;
            }
        }
        if (mx == 0){
            int ost = a+b - i;
            if (ost%2) cout << 1 << endl;
            else cout << 0 << endl;
            return 0;
        }
        d[wh]--;
    }
    int ans = 0;
    for (int i=0;i<n;i++) ans += d[i]*d[i];
    cout << ans << endl;
    return 0;
}