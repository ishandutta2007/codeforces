#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=2e3+3; int a[N][N],f[N][N]; char s[N];
signed main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%s",s);
		rep(j,1,m) a[i][j]=s[j-1]-'a'+1;
	}
	ll ans=m; rep(j,1,m) f[n][j]=1;
	per(i,n-1,1){
		f[i][1]=f[i][m]=1,ans+=2;
		rep(j,2,m-1){
			if (a[i][j]!=a[i+1][j-1]||a[i][j]!=a[i+1][j]||a[i][j]!=a[i+1][j+1])
				f[i][j]=1; 
			else{
				f[i][j]=min(min(f[i+1][j-1],f[i+1][j+1]),f[i+1][j]);
				if (a[i][j]==a[i+2*f[i][j]][j]) ++f[i][j];
			}
			ans+=f[i][j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}