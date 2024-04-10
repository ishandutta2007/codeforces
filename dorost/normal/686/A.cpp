#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, m, x, ans = 0;
    cin >> n >> m;
    char c;
    for (int i = 0; i < n; i++){
        cin >> c >> x;
        if (c == '-'){
            if (x > m) {
                ans ++;
            }else {
                m -= x;
            }
        }else {
            m += x;
        }
    }
    cout << m << ' ' << ans;
}