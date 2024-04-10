#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int n,m,a[200005],p[200005];
long long dp[200005];
struct intv{
	int l,r;
}b[200005],c[200005];
bool cmp(intv x,intv y){
	if(x.l==y.l) return x.r>y.r;
	return x.l<y.l;
}
void solve(){
	int i,j;
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,m){
		scanf("%d%d",&b[i].l,&b[i].r);
		if(upper_bound(a+1,a+n+1,b[i].r)-lower_bound(a+1,a+n+1,b[i].l)>=1){
			i--;m--;
		}
	}
	sort(b+1,b+m+1,cmp);
	int nm=0;
	rep(i,m){
		while(nm&&c[nm].r>=b[i].r)nm--;
		c[++nm]=b[i];
	}
	m=nm;
	rep(i,m)b[i]=c[i];
	if(!m){
		puts("0");
		return;
	}
	j=1;
	rep(i,n){
		while(j<=m&&b[j].l<a[i]) j++;
		p[i]=j-1;
	}
	p[n+1]=m;
	dp[0]=0;
	rep(i,m)dp[i]=0x3f3f3f3f3f3f3f3fll;
	rep(i,n){
		long long c1=0x3f3f3f3f3f3f3f3fll,c2=0x3f3f3f3f3f3f3f3fll;
		for(j=p[i-1];j<=p[i];j++){
			c1=min(c1,dp[j]+(j==p[i]?0:a[i]-b[j+1].r));
			c2=min(c2,dp[j]+2ll*(j==p[i]?0:a[i]-b[j+1].r));
		}
		for(j=p[i];j<=p[i+1];j++){
			dp[j]=min(c1+2ll*(j==p[i]?0:b[j].l-a[i]),c2+(j==p[i]?0:b[j].l-a[i]));
		}
	}
	cout<<dp[m]<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}