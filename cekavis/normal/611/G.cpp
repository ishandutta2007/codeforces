#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 500005, M = N*2, P = 1000000007;
int n, f1[M], f2[M], f3[M], f4[M], g1[M], g2[M], g3[M], g4[M];
ll sum, ans;
struct item{
	int x, y;
	bool operator<(const item &r)const{ return x==r.x?y>r.y:x<r.x;}
	item operator-(const item &r)const{ return (item){x-r.x, y-r.y};}
	ll operator*(const item &r)const{ return (ll)x*r.x+(ll)y*r.y;}
	ll operator^(const item &r)const{ return (ll)x*r.y-(ll)y*r.x;}
} a[M];
int calcf(int x, int y){
	return (f3[x]-f4[x]-(ll)a[y].x*(f2[x]-f2[x+1])-(ll)a[y].y*(f1[x+1]-f1[x]))%P;
}
int calcg(int x, int y){
	return (g3[x]-g4[x]-a[y].x*((ll)g2[x]-g2[x+1]+f2[x+1])-a[y].y*((ll)g1[x+1]-g1[x]-f1[x+1]))%P;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", &a[i].x, &a[i].y), a[i+n]=a[i];
	for(int i=1; i<=n*2; ++i)
		f1[i]=(f1[i-1]+a[i].x)%P,
		f2[i]=(f2[i-1]+a[i].y)%P,
		f3[i]=(f3[i-1]+(ll)a[i+1].x*a[i].y)%P,
		f4[i]=(f4[i-1]+(ll)a[i].x*a[i+1].y)%P,
		g1[i]=(g1[i-1]+(ll)a[i].x*i)%P,
		g2[i]=(g2[i-1]+(ll)a[i].y*i)%P,
		g3[i]=(g3[i-1]+(ll)a[i+1].x*a[i].y%P*i)%P,
		g4[i]=(g4[i-1]+(ll)a[i].x*a[i+1].y%P*i)%P;
	for(int i=2; i<n; ++i) sum+=(a[i+1]-a[1])^(a[i]-a[1]);
	ll now=0;
	for(int i=1, j=2; i<=n; ++i){
		while(now+((a[j+1]-a[i])^(a[j]-a[i]))<=sum/2)
			now+=(a[j+1]-a[i])^(a[j]-a[i]), ++j;
		ans=(ans+(ll)(calcf(j-1, i)-calcf(i, i))*j-(calcg(j-1, i)-calcg(i, i)))%P;
		ans=(ans-(ll)(calcf(n+i-2, i)-calcf(j, i))*j+(calcg(n+i-2, i)-calcg(j, i)))%P;
		now-=(a[i+1]-a[j])^(a[i]-a[j]);
	}
	printf("%lld\n", ((sum%P*(n*(n-3ll)/2%P)-ans)%P+P)%P);
	return 0;
}