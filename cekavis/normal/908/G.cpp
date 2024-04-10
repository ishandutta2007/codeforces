#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 705, M = 11, P = 1000000007;
int n, ans, cnt[M], p[N], p1[N], f[M][N], g[M][N], C[N][N];
char s[N];
int main() {
	scanf("%s", s+1), n=strlen(s+1);
	p[0]=1;
	for(int i=1; i<=n; ++i) p[i]=p[i-1]*10ll%P, p1[i]=(p1[i-1]*10ll+1)%P;
	for(int i=0; i<=n; ++i) C[i][0]=1;
	for(int i=1; i<=n; ++i) for(int j=1; j<=i; ++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	f[0][0]=1;
	for(int i=1; i<=10; ++i) for(int j=0; j<=n; ++j) for(int k=0; k<=j; ++k)
		f[i][j]=(f[i][j]+(ll)f[i-1][k]*C[j][k])%P;
	for(int i=0; i<10; ++i) for(int j=0; j<=n; ++j) for(int k=0; k<=j; ++k)
		g[i][j]=(g[i][j]+(ll)f[i][k]*f[9-i][j-k]%P*C[j][k]%P*p[j-k])%P;

	for(int i=1; i<=n; ++cnt[s[i++]-'0']){
		for(int j=0; j<s[i]-'0'; ++j){
			++cnt[j];
			for(int x=9, sum=0; ~x; sum+=cnt[x--]) for(int k=0; k<=n-i; ++k)
				ans=(ans+(ll)x*p1[k+cnt[x]]%P*g[x][n-i-k]%P*p[sum]%P*C[n-i][k])%P;
			--cnt[j];
		}
	}
	sort(s+1, s+n+1);
	for(int i=1; i<=n; ++i) ans=(ans+(ll)(s[i]-'0')*p[n-i])%P;
	return printf("%d", ans), 0;
}