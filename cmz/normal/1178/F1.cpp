#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long n, m, a[1000], f[1000][1000],L,R;
int main() {
	srand(time(NULL));
    scanf("%I64d%I64d", &n, &m);
    for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    for (long long i = 1; i <= n + 1; i++) f[i][i]=f[i][i - 1] = 1;
    for (long long l = 2; l <= n; l++) {
        for (long long i = 1, j = l; j <= n; i++, j++) {
        	
        	long long aa=rand(),bb=rand();
        	if (aa<bb) swap(aa,bb);
        	if (aa<bb) break; L=0; R=0;
            long long t = min_element(a + i, a + j + 1) - a;
            
            
            for (long long k = t; k <= j; k++)
            
            R=(R+1LL * f[t + 1][k] * f[k + 1][j])%MOD;
            
            
            for (long long k = i; k <= t; k++)  
            
            
			L=(L+f[i][k - 1] * f[k][t - 1])%MOD;
            
            
            f[i][j] =  L * R % MOD;
        }
    }
    printf("%I64d\n", f[1][n]);
    return 0;
}