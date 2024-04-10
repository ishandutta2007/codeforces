#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) grow(res, a);
        grow(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int n; string s;
int fact[2*N], ifact[2*N], ans;

int comb(int a, int b){
    if(a < 0 || b < 0 || b > a) return 0;
    return mul(fact[a], mul(ifact[b], ifact[a-b]));
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s; n = s.length();
    fact[0] = 1; for(int i = 1; i<2*N; i++) fact[i] = mul(fact[i-1], i);
    for(int i = 0; i<2*N; i++) ifact[i] = inv(fact[i]);
    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 0; i<n; i++)
        if(s[i] == ')') d++;
        else if(s[i] == '?') b++;
    for(int i = 0; i<=n; i++){
        if(i) 
            a += s[i-1]=='?', c += s[i-1]=='(',
            b -= s[i-1]=='?', d -= s[i-1]==')';
        inc(ans, add(mul(c, comb(a+b, b-c+d)), mul(a, comb(a+b-1, b-c+d-1))));
    }
    cout << ans << endl;
}