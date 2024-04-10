#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define fi first
#define se second
#define ll long long 
using namespace std;
const int N=1e6+6; pr a[N]; int b[N][2];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int m,n; scanf("%d%d",&m,&n);
		rep(i,1,n) scanf("%d%d",&a[i].se,&a[i].fi),--a[i].se;
		sort(a+1,a+1+n);
		int k=0;
		rep(i,1,n){
			if (a[i].fi>a[i-1].fi) k=k+1+(a[i].fi-a[i-1].fi-1)%2; 
			b[k][a[i].se]=true;
		}
		if (m>a[n].fi) k=k+1+(m-a[n].fi-1)%2;
		bool f=false;
		rep(i,1,k){
			if (b[i][0]==b[i][1]) continue;
			if (!b[i][0]){
				if (i==k||b[i+1][0]){ f=true; break; }
				b[i+1][0]=true;
			}
			else{
				if (i==k||b[i+1][1]){ f=true; break; }
				b[i+1][1]=true;
			}
		}
		puts(!f?"YES":"NO");
		rep(i,1,k) b[i][0]=b[i][1]=false;
	}
	return 0;
}