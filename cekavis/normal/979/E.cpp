#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long

const int N = 52, P = 1000000007;
int n, p, ans, p2[N], c[N], f[N][2][2][2];
inline void update(int &x, ll y){ x=(x+y)%P;}
int main() {
	scanf("%d%d", &n, &p);
	p2[0]=1;
	for(int i=1; i<=n; ++i) scanf("%d", c+i), p2[i]=p2[i-1]*2%P;

	if(c[1]!=1) ++f[1][1][1][0];
	if(c[1]) ++f[1][1][0][1];
	for(int i=1; i<=n; ++i) for(int j=0; j<2; ++j)
		for(int k=0; k<2; ++k) for(int t=0; t<2; ++t){
			if(c[i+1]){
				update(f[i+1][j^1][k][t|1], (ll)f[i][j][k][t]%P*p2[i-k]);
				if(k) update(f[i+1][j][k][t], (ll)f[i][j][k][t]%P*p2[i-1]);
			}
			if(c[i+1]!=1){
				update(f[i+1][j^1][k|1][t], (ll)f[i][j][k][t]%P*p2[i-t]);
				if(t) update(f[i+1][j][k][t], (ll)f[i][j][k][t]%P*p2[i-1]);
			}
		}
	for(int i=0; i<2; ++i) for(int j=0; j<2; ++j) (ans+=f[n][p][i][j])%=P;
	return printf("%d", ans), 0;
}