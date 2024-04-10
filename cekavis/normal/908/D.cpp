#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 1005, P = 1000000007;
int k, a, b, ans, f[N][N];
inline int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	scanf("%d%d%d", &k, &a, &b);
	int x=Pow(a+b);
	a=(ll)a*x%P, b=(ll)b*x%P, x=(ll)Pow((P+1ll-a)*(P+1-a)%P)*a%P*b%P;
	f[1][0]=1;
	for(int i=1; i<=k; ++i) for(int j=0; j<=k; ++j){
		if(i<k) f[i+1][j]=(f[i+1][j]+(ll)f[i][j]*a)%P; else ans=(ans+(ll)f[i][j]*a%P*(k+1+j+x))%P;
		if(j+i<k) f[i][j+i]=(f[i][j+i]+(ll)f[i][j]*b)%P; else ans=(ans+(ll)f[i][j]*b%P*(j+i))%P;
	}
	return printf("%d", ans), 0;
}