#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int fac = 1;
    for(int i = 1; i<=n; i++) fac = (1ll*i*fac)%MOD;
    int pow2 = 1;
    for(int i = 1; i<=n-1; i++) pow2 = (1ll*2*pow2)%MOD;
    int ans = fac-pow2;
    if(ans < 0) ans += MOD;
    cout << ans << endl;
}