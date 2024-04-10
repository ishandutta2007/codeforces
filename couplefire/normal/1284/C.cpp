#include <bits/stdc++.h>
using namespace std;
long long fact[250002];

int main(){
    //freopen("a.in", "r", stdin);
    long long n, m; cin >> n >> m;
    fact[0] = 1;
    for(long long i = 1; i<250002; i++){
        fact[i] = (fact[i-1]*i)%m;
    }
    long long ans = 0;
    for(long long dif = 0; dif < n; dif++){
        long long temp = fact[n-dif-1]*fact[dif+1];
        temp %= m;
        temp *= (n-dif);
        temp %= m;
        temp *= (n-dif);
        temp %= m;
        ans += temp;
        ans %= m;
    }
    cout << ans << endl;
}