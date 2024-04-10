//  228

/*
    Username : moondancer
    Name : Moon Dancer
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int c[k+1] = {};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x]++;
    }
    int ans = 0;
    while(1) {
        bool f = 1;
        for (int i = k-1; i >= 1; --i) {
            if(c[i]) {
                c[i]--;
                c[i+1]++;
                f = 0;
            }
        }
        if(f) break;
        ans++;
    }
    cout << ans;
    return 0;
}