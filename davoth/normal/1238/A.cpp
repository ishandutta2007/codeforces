#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_N = 1e5 + 1, MOD = 1e8;
using namespace std;
int main() {
    ll n;
    cin >> n;
    while(n--){
        ll x,y;
        cin >> x >> y;
        if(x>y+1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}