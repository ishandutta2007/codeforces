#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long gcd(long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long inverse(long long a){
    long long x, y;
    long long g = gcd(a, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    return x;
}

int main(){
    //freopen("a.in", "r", stdin);
    long long n, m, g; cin >> n >> m >> g;
    if(n == 0){
        if(m == 1){
            if(g == 1){
                cout << 1 << endl;
                exit(0);
            }
            else{
                cout << 0 << endl;
                exit(0);
            }
        }
        if(g == 0){
            cout << 1 << endl;
            exit(0);
        }
        else{
            cout << 0 << endl;
            exit(0);
        }
    }
    else if(m == 0){
        if(n % 2 == 1){
            if(g == 0){
                cout << 1 << endl;
                exit(0);
            }
            else{
                cout << 0 << endl;
                exit(0);
            }
        }
        else{
            if(g == 0){
                cout << 0 << endl;
                exit(0);
            }
            else{
                cout << 1 << endl;
                exit(0);
            }
        }
    }

    long long i;
    if(g == 0){
        i = n+m-1;
    }
    else{
        i = n+m-2;
    }
    long long fac[n+m];
    fac[0] = 1;
    for(long long i = 1; i<n+m; i++){
        fac[i] = (fac[i-1]*i)%MOD;
    }
    long long inv[n+m];
    for(long long i = 0; i<n+m; i++){
        inv[i] = inverse(fac[i]);
    }
    long long ans = 0;
    for(; i>=m-1; i-=2){
        long long temp = fac[i];
        temp *= inv[m-1];
        temp %= MOD;
        temp *= inv[i-m+1];
        temp %= MOD;
        ans += temp;
        ans %= MOD;
    }
    if(m == 1 && n%2 == g){
        ans--;
        ans += MOD;
        ans %= MOD;
    }
    else if(m == 1){
        ans++;
        ans += MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}