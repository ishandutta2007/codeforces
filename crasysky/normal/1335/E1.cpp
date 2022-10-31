#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;
const int N=2e5+5;
int a[N],c[202][N]; vector<int> p[202];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(j,1,200) p[j].clear();
		rep(i,1,n){
			scanf("%d",&a[i]);
			rep(j,1,200) c[j][i]=c[j][i-1]+(a[i]==j);
			p[a[i]].push_back(i);
		}
		int ans=0;
		rep(j,1,200) ans=max(ans,c[j][n]);
		rep(l,1,n){
			int x=a[l],r=p[x][c[x][n]-c[x][l]];
			if (l>=r) continue;
			rep(j,1,200)
				ans=max(ans,2*c[x][l]+(c[j][r-1]-c[j][l]));
		}
		printf("%d\n",ans);
	}
	return 0;
}