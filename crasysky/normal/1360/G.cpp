#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e3+3; int ans[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m,a,b; scanf("%d%d%d%d",&n,&m,&a,&b);
		if ((ll)n*a!=(ll)m*b){ puts("NO"); continue; }
		puts("YES");
		for (int i=1,y=1;i<=n;++i){
			rep(j,1,m) ans[j]=0;
			rep(j,1,a) ans[y]=1,y=y%m+1;
			rep(j,1,m) printf("%d",ans[j]);
			putchar('\n');
		}
	}
	return 0;
}