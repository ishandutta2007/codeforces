#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>

using namespace std;
#define ll long long

const int N = 505;
int n;
ll ans, f[N][N];
struct c{
	int a, b, k;
	inline bool operator <(const c &rhs)const{ return b>rhs.b;}
}a[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].k);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i) for(int j=0; j<=n; ++j){
		f[i][j]=f[i-1][j]+max(0ll, a[i].a-(ll)a[i].b*a[i].k);
		if(j) f[i][j]=max(f[i][j], f[i-1][j-1]+a[i].a-(ll)a[i].b*(j-1));
		ans=max(ans, f[i][j]);
	}
	return printf("%lld", ans), 0;
}