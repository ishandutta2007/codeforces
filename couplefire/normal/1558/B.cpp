#include <bits/stdc++.h>
using namespace std;

const int N = 4000005;
int MOD, n, psum[N], dp[N];

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> MOD;
    dp[n] = 1;
    for(int i = 1; i<=n; ++i)
        psum[i] = 1;
    for(int i = n-1; i>=1; --i){
        dp[i] = psum[i+1];
        for(int j = 2; j*i<=n; ++j)
            inc(dp[i], sub(psum[j*i], psum[min(n+1, j*(i+1))]));
        psum[i] = add(psum[i+1], dp[i]);
    }
    cout << dp[1] << '\n';
}