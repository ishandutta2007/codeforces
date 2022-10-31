#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<double,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
mt19937 rnd(time(0));
const int N=1e5+5; 
int a[N],ans[N]; pr b[N]; map<int,int> cnt;
int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
int main(){
	int n,m=0; scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if (cnt[a[i]]<2) b[++m]=mp(a[i],i),++cnt[a[i]];
	}
	int c=5e6/max(30,m);
	while (c--){
		random_shuffle(b+1,b+1+m);
		int g=0,p=m+1;
		rep(i,1,m){
			g=gcd(g,b[i].fi);
			if (g==1){ p=i; break; }
		}
		bool t=false; g=0;
		per(i,m,p+1){
			g=gcd(g,b[i].fi);
			if (g==1){ t=true; break; }
		}
		if (t){
			rep(i,1,p) ans[b[i].se]=1;
			puts("YES");
			rep(i,1,n) printf("%d ",ans[i]+1);
			return 0;
		}
	}
	puts("NO");
	return 0;
}