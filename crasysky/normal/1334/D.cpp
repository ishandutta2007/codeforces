#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[N],c[202][N]; vector<int> p[202];
ll S(int l,int r){ return (ll)(l+r)*(r-l+1); }
int solve(ll x){
	int l=1,r=n-1;
	while (l<=r){
		int m=l+r>>1;
		if (S(n-m,n-1)>=x) r=m-1;
		else l=m+1;
	}
	return r;
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		ll l,r;
		scanf("%d%lld%lld",&n,&l,&r);
		int x=solve(l),y=l-S(n-x,n-1); ++x;
		rep(i,1,r-l+1){
			if (x==n){ printf("%d ",1); continue; }
			if (y&1) printf("%d ",x);
			else printf("%d ",x+y/2);
			if (y==2*(n-x)) ++x,y=1;
			else ++y;
		}
		putchar('\n');
	}
	return 0;
}