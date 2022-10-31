#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int MOD;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n;
int dp1[N][N*N/2], psum[N*N/2], val[N], comb[N][N], ans, fact[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> MOD;
    dp1[0][0] = 1;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=i; j++)
            for(int k = 0; k<=(i-1)*(i-2)/2; k++)
                inc(dp1[i][k+i-j], dp1[i-1][k]);
    for(int i = 1; i<=n; i++){
        memset(psum, 0, sizeof psum);
        for(int j = 1; j<=i; j++){
            for(int k = 0; k<=(i-1)*(i-2)/2; k++)
                inc(val[i], mul(sub(psum[N*N/2-1], psum[k+j-1]), dp1[i-1][k]));
            int tmp = 0;
            for(int k = 0; k<=(i-1)*(i-2)/2; k++){
                inc(tmp, dp1[i-1][k]);
                inc(psum[k+j-1], tmp);
            }
            for(int k = (i-1)*(i-2)/2+1+j-1; k<N*N/2; k++)
                inc(psum[k], tmp);
        }
    }
    comb[0][0] = 1;
    for(int i = 1; i<N; i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j<i; j++)
            inc(comb[i][j], add(comb[i-1][j-1], comb[i-1][j]));
    }
    fact[0] = 1;
    for(int i = 1; i<N; i++)
        fact[i] = mul(fact[i-1], i);
    for(int i = 1; i<=n; i++){
        inc(ans, mul(mul(fact[n-i], comb[n][n-i]), val[i]));
    }
    cout << ans << endl;
}