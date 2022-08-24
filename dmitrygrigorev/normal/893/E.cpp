#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e6 + 1000;
vector<int> fact(INF), obr(INF);
int MOD = 1000000007;
int st(int a, int b){
    int ans = 1;
    int S = a;
    for (int i=0; i < 40; i++){
        int ba = (1LL << i) & b;
        if (ba == 0){
            S *= S;
            S %= MOD;
            continue;
        }
        ans *= S;
        ans %= MOD;
        S *= S;
        S %= MOD;
    }
    return ans;
}
int del(int x){
    return st(x, MOD-2);
}
int C(int n, int k){
    if (k == 0 || n == k) return 1;
    int R = fact[n];
    R *= obr[n-k];
    R %= MOD;
    R *= obr[k];
    return R % MOD;
}
signed main(){
    int q;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    int SS = 1;
    for (int i=1; i < INF; i++){
        SS *= i;
        SS %= MOD;
        fact[i] = SS;
        obr[i] = del(SS);
    }
    for (int i=0; i < q; i++){
        int x, y;
        cin >> x >> y;
        int ans = st(2, y-1);
        for (int j=2; j < 1000; j++){
            int G=0;
            if (x==1) break;
            while (x % j == 0){
                x /= j;
                G++;
            }
            if (G == 0) continue;
            ans *= C(G+y-1, y-1);
            //cout << ans << endl;
            ans %= MOD;
        }
        if (x != 1) ans *= y;
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}