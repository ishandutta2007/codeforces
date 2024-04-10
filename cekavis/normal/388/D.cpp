#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long

const int N = 33, P = 1000000007;
int n, k, ans, a[N], f[N][N][2];
template<class T>
inline void update(int &x, T y){ x=(x+y)%P;}
int main() {
	scanf("%d", &k);
	while(k) a[n++]=k&1, k>>=1;
	f[n][0][0]=1;
	for(int i=n; i; --i) for(int j=0; j<=n-i; ++j){
		update(f[i-1][j][1], (ll)f[i][j][1]<<j);
		update(f[i-1][j+1][1], f[i][j][1]);
		if(!j){
			if(!a[i-1]) update(f[i-1][j][0], f[i][j][0]);
			else update(f[i-1][j+1][0], f[i][j][0]), update(f[i-1][j][1], f[i][j][0]);
		}
		else{
			if(!a[i-1]) update(f[i-1][j][0], (ll)f[i][j][0]<<j-1);
			else update(f[i-1][j+1][0], (ll)f[i][j][0]), update(f[i-1][j][0], (ll)f[i][j][0]<<j-1), update(f[i-1][j][1], (ll)f[i][j][0]<<j-1);
		}
	}
	for(int i=0; i<=n; ++i) update(ans, (f[0][i][0]+f[0][i][1])%P);
	return printf("%d", ans), 0;
}