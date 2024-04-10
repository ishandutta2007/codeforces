#include <bits/stdc++.h>
using namespace std;
#define maxn 300000
#define int long long

int n, gi[maxn], mod;
void init(){
	gi[0] = gi[1] = 1;
    
	for (int i = 2; i < maxn; ++ i)  gi[i] = gi[i - 1] * i % mod;
}
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n >> mod;
    init();
    int ans = 0, cnt = n, cho = n;
    for (int i = 1; i <= n; ++ i) {
        
        ans += cnt * cho % mod * gi[n - i] % mod * gi[i] % mod;
        ans %= mod;
        cnt --;
        cho --;
    }

    cout << ans << endl;
    return 0;
}