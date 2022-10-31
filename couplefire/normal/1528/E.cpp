#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int MOD = 998244353;
const int INV2 = (MOD+1)/2;
const int INV6 = (MOD+1)/6;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, f[N], sf[N], f2[N], ans;

int comb2(int x){return mul(mul(x, sub(x, 1)), INV2);}
int comb3(int x){return mul(mul(x, sub(x, 1)), mul(sub(x, 2), INV6));}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    f[0] = sf[0] = 1;
    for(int i = 1; i<=n; i++){
        f[i] = f[i-1];
        if(i > 1) inc(f[i], mul(f[i-1], sf[i-2]));
        inc(f[i], comb2(add(f[i-1], 1)));
        sf[i] = add(sf[i-1], f[i]);
    }
    for(int i = 1; i<=n; i++) f2[i] = sub(f[i], f[i-1]);
    inc(ans, f[n]);
    if(n >= 2) inc(ans, mul(f[n-1], comb2(add(sf[n-2], 1))));
    if(n >= 2) inc(ans, mul(sf[n-2], comb2(add(f[n-1], 1))));
    inc(ans, comb3(add(f[n-1], 2)));
    grow(ans, 2); dec(ans, 1);
    for(int i = 0; i<n; i++)
        inc(ans, mul(sub(f[i], 1), f2[n-1-i]));
    cout << ans << endl;
}