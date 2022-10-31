#include <bits/stdc++.h>
using namespace std;

const int N = 14;
const int MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    for(; b; grow(a, a), b>>=1)
        if(b&1) grow(res, a);
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int n, arr[N], dp1[N][1<<N], dp2[1<<N], prob[N][N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j){
            if(i==j) continue;
            prob[i][j] = mul(arr[i], inv(arr[i]+arr[j]));
        }
    for(int i = 0; i<n; ++i){
        dp1[i][0] = 1;
        for(int mask = 1; mask<(1<<n); ++mask){
            if(mask&(1<<i)) continue;
            int lbit = 0;
            for(int j = 0; j<n; ++j)
                if(mask&(1<<j)) lbit = j;
            dp1[i][mask] = mul(dp1[i][mask^(1<<lbit)], prob[lbit][i]);
        }
    }
    for(int mask = 0; mask<(1<<n); ++mask){
        dp2[mask] = 1;
        for(int s=mask; s; s=(s-1)&mask){
            if(s==mask) continue;
            int cur = dp2[s];
            for(int i = 0; i<n; ++i)
                if(s&(1<<i)) grow(cur, dp1[i][mask^s]);
            dec(dp2[mask], cur);
        }
    }
    int ans = 0;
    for(int i = 0; i<n; ++i){
        for(int mask = 0; mask<(1<<n); ++mask){
            if(!(mask&(1<<i))) continue;
            int tmp = dp2[mask];
            for(int j = 0; j<n; ++j){
                if(!(mask&(1<<j))) continue;
                for(int k = 0; k<n; ++k){
                    if(mask&(1<<k)) continue;
                    grow(tmp, prob[j][k]);
                }
            }
            inc(ans, tmp);
        }
    }
    cout << ans << '\n';
}