#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int q;
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        int ans = 0;
        while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0){
            if (n % 2 == 0){
                n /= 2;
            }else if (n % 3 == 0){
                n = n * 2 / 3;
            }else {
                n = n * 4 / 5;
            }
            ans ++;
        }
        if (n == 1){
            cout << ans << endl;
        }else {
            cout << -1 << endl;
        }
    }
}