#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1) grow(res, a);
        grow(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int fact[N], ifact[N];

int comb(int a, int b){
    return mul(fact[a], mul(ifact[b], ifact[a-b]));
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int del = 0, cnt = 0;
    for(int i = 0; i<n; i++){
        int cur = i;
        while(i<n && s[i]=='1') i++;
        del += (i-cur)%2;
        cnt += (i-cur)/2;
    }
    cout << comb(n-del-cnt, cnt) << "\n";
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = 1;
    for(int i = 1; i<N; i++)
        fact[i] = mul(fact[i-1], i);
    for(int i = 0; i<N; i++)
        ifact[i] = inv(fact[i]);
    int t; cin >> t;
    while(t--) solve();
}