#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 200005
#define ll long long
using namespace std;

int T,n,i,j,k;
ll a[maxn],g;
ll gcd(ll x,ll y){return (x%y==0)?y:gcd(y,x%y);}


int main(){
	scanf("%d",&T);
	while (T--){
		ll x; scanf("%d%lld",&n,&x);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+1+n),g=0;
		for(i=2;i<=n;i++) if (a[i]>a[i-1])
			g=(g==0)?(a[i]-a[i-1]):gcd(g,a[i]-a[i-1]);
		int ans;
		if (g==0) ans=(x==a[1]); else 
			ans=(abs(x-a[1])%g==0);
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
}