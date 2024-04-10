#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 500005, inf = 1e9;
ll ans, c[N*2];
int n, a[N], b[N*2];
struct item{
	int x, y;
	item(){ x=y=inf;}
	item(int a, int b){ x=a, y=b;}
	item operator!()const{ return (item){x+1, y+1};}
	item operator+(const int a)const{
		if(a<y) return (item){y, a};
		if(a<x) return (item){a, y};
		return *this;
	}
	item operator+(const item &r)const{ return *this+r.x+r.y;}
	item work(int a){ return (item){x>=a?inf:x, y>=a?inf:y};}
} d[N*2];
vector<item> f[N*2];
int calc(int x, int y, int p){
	int l=x/y+1, a[4]={}, cnt=0;
	if(d[l*y-1].y<inf && l*y-1-d[l*y-1].y>=x) a[cnt++]=(x-y+d[l*y-1].y+1+y-1)/y;
	if(d[l*y-1].x<inf && l*y-1-d[l*y-1].x>=x) a[cnt++]=(x-y+d[l*y-1].x+1+y-1)/y;
	if(l<(int)f[y].size() && f[y][l].y<inf)
		a[cnt++]=(x-y+f[y][l].y+1+y-1)/y;
	// if(x==2) printf(">> %d %d %d %d\n", y, cnt, a[0], d[l*y-1].y);
	if(l<(int)f[y].size() && f[y][l].x<inf)
		a[cnt++]=(x-y+f[y][l].x+1+y-1)/y;
	// if(x==2) printf(">> %d %d %d %d\n", y, cnt, a[1], f[y][l].y);
	if(cnt<p) return 1e9;
	sort(a, a+cnt);
	return p==1?a[0]:a[0]+a[1];
}
bool check(int x, int y){
	ll cnt=c[y];
	// if(x==2) printf("check: %d\n", y);
	int mn=min(calc(x*2, y, 1), calc(x, y, 2));
	if(mn>=1e9) return 0; else return cnt-mn>=x;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), ++b[a[i]];
	for(int i=1; i<=1000000; ++i){
		d[i]=!d[i-1];
		if(b[i]) d[i]=d[i]+0;
		if(b[i]>1) d[i]=d[i]+0;
	}
	for(int i=1000000; i; --i) b[i]+=b[i+1];
	for(int i=1; i<=500000; ++i){
		for(int j=i; j<=500000+i; j+=i) c[i]+=b[j], f[i].push_back(d[j-1].work(i));
		for(int j=f[i].size()-2; j>=0; --j) f[i][j]=f[i][j]+f[i][j+1];
		// if(i==2) printf("shit: %d\n", (int)f[i].size());
	}
	for(int i=2; i<=500000; ++i){
		int l=2, r=500000;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i, mid)) ans=max(ans, (ll)i*mid), l=mid+1; else r=mid-1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}