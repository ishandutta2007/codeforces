#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005, M = 2000005;
const char ans[2][2]={{'L', 'D'}, {'U', 'R'}};
int n, l;
bool f[M], g[M];
struct wish{
	ll t, x, y, r;
	bool operator<(const wish &x)const{ return r<x.r;}
} a[N];
void No(){ puts("NO"), exit(0);}
ll calc1(ll x, ll y){// floor
	return x<0?(x+1)/y-1:x/y;
}
ll calc2(ll x, ll y){// cell
	return x<=0?x/y:(x-1)/y+1;
}
void solve(bool *f){
	ll L=-l, R=l;
	for(int i=1; i<=n; ++i){
		if(a[i].t==a[i-1].t){
			if(abs(a[i].x-a[i-1].x)>a[i].r-a[i-1].r) No();
		}
		else if(a[i-1].t>a[i].t){
			R=min(R, calc1(a[i].r-a[i-1].r-a[i].x+a[i-1].x, a[i-1].t-a[i].t));
			L=max(L, calc2(a[i-1].r-a[i].r-a[i].x+a[i-1].x, a[i-1].t-a[i].t));
		}
		else{
			L=max(L, calc2(a[i-1].r-a[i].r+a[i].x-a[i-1].x, a[i].t-a[i-1].t));
			R=min(R, calc1(a[i].r-a[i-1].r+a[i].x-a[i-1].x, a[i].t-a[i-1].t));
		}
	}
	// printf(">> %lld %lld\n", L, R);
	L+=(L^l)&1;
	if(L>R) No();
	for(int i=1, now=0, j=0; i<=n; ++i){
		while(now<a[i].x-L*a[i].t) f[++j]=1, ++now;
		while(now>a[i].x-L*a[i].t) f[++j]=0, --now;
		while(j<a[i].r) f[++j]=1, f[++j]=0;
		assert(j==a[i].r);
	}
}
int main() {
	scanf("%d%d", &n, &l);
	for(int i=1; i<=n; ++i){
		scanf("%lld%lld%lld", &a[i].t, &a[i].x, &a[i].y);
		if((a[i].t^a[i].x^a[i].y)&1) No();
		ll tmp=a[i].x;
		a[i].x+=a[i].y, a[i].y=tmp-a[i].y;
		a[i].r=a[i].t%l, a[i].t/=l;
	}
	sort(a+1, a+n+1);
	a[++n]=(wish){-1, 0, 0, l};
	solve(f);
	for(int i=1; i<=n; ++i) a[i].x=a[i].y;
	solve(g);
	for(int i=1; i<=l; ++i) putchar(ans[f[i]][g[i]]);
	return 0;
}