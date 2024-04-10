#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mod 1000000007LL

LL a , b , ans = 0;
int main(){
    cin >> a >> b;
    for(LL i = 1 ; i < b ; i ++){
        LL fr = (b * i) % mod , ba = ((a + 1) * a / 2) % mod;
        ans = (ans + i * a) % mod;
        ans = (ans + fr * ba) % mod;
    }
    cout << ans << endl;
    return 0;
}