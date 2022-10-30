#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define MOD 1000000007

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

const int INV = 205555557;

int phi[MAXN];
int pre[MAXN];
int f[MAXN];
int onepre[MAXN];
int twopre[MAXN];

void phiCalc() {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= MAXN-1; i++)
        phi[i] = i;

    for (int i = 2; i <= MAXN-1; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= MAXN-1; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int func(int n, int m){
    int res = sub(0, INV);
    grow(res, n); grow(res, n+1); grow(res, n+2);
    int tres = 15;
    inc(tres, mul(4, mul(n, mul(n, n))));
    dec(tres, mul(12, mul(n, n)));
    dec(tres, mul(7, n));
    int ttres = mul(n, n);
    dec(ttres, mul(3, n));
    dec(ttres, 3);
    grow(ttres, sub(0, 6));
    grow(ttres, m);
    return mul(res, add(tres, ttres));
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    phiCalc();
    for(int i = 1; i<MAXN; i++){
        for(int j = i; j<MAXN; j+=i) inc(f[j], mul(i, phi[j/i]));
    }
    // cout << f[4] << endl;
    pre[0] = f[0];
    onepre[0] = twopre[0] = 0;
    for(int i = 1; i<MAXN; i++){
        pre[i] = add(pre[i-1], f[i]);
        onepre[i] = add(onepre[i-1], mul(i, f[i]));
        twopre[i] = add(twopre[i-1], mul(mul(i, i), f[i]));
    }
    // cout << pre[2] << endl;
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        if(n > m) swap(n, m);
        int ans = 0;
        inc(ans, pre[n]);
        inc(ans, twopre[n]);
        dec(ans, mul(2, onepre[n]));
        inc(ans, mul(m, mul(n, pre[n])));
        dec(ans, mul(m, onepre[n]));
        inc(ans, mul(m, pre[n]));
        dec(ans, mul(n, onepre[n]));
        inc(ans, mul(n, pre[n]));
        grow(ans, 2);
        // cout << ans << endl;
        inc(ans, func(n, m));
        cout << ans << endl;
    }
}