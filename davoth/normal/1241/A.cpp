#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_N = 1e5 + 1, MOD = 1e8;
using namespace std;
int main() {
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        if(n<4){
            cout << 4-n << '\n';
            continue;
        }
        cout << n%2 << '\n';
    }
    return 0;
}