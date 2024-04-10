#include<cstdio>
#define ll long long
const int N = 205;
int n, d, P;
unsigned ans, g[N], f[N][N], C[N][N];
int main() {
	scanf("%d%d%d", &n, &d, &P);
	C[0][0]=1;
	for(int i=1; i<=n; C[i][0]=1, ++i) for(int j=1; j<=i; ++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	g[1]=f[1][0]=1;
	for(int i=2; i<=n; ++i) for(int j=1; j<=d; ++j){
		for(int k=1; k<i; ++k) f[i][j]=(f[i][j]+(ll)f[i-k][j-1]*g[k]%P*C[i-2][k-1])%P;
		if(j<d) (g[i]+=f[i][j])%=P;
	}
	for(int i=0; i<=d; ++i) for(int j=0; i+j<=d; ++j) if(j!=1) for(int k=0; k<n; ++k)
		ans=(ans+(ll)f[k+1][i]*f[n-k][j])%P;
	return printf("%lld", 2ll*n*(n-1)%P*ans%P), 0;
}