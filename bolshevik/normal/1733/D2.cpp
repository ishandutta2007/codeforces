#include<cstdio>
#include<iostream>
using namespace std;
const int o=5010;const long long inf=1e18;
int T,n,x,y,a[o],tot;long long f[o][o][2],ans;char s[o],t[o];
int main(){
	for(scanf("%d",&T);T--;tot=0){
		scanf("%d%d%d%s%s",&n,&x,&y,s+1,t+1);
		for(int i=1;i<=n;++i) if(s[i]^t[i]) a[++tot]=i;
		if(tot&1){printf("-1\n");continue;}
		for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) f[i][j][0]=f[i][j][1]=inf;
		f[0][0][0]=0;
		for(int i=1;i<=tot;++i){
			for(int j=0;j<tot;++j)
				f[i][j][0]=min(f[i][j][0],min(f[i-1][j+1][0],(a[i]==a[i-1]+1)?inf:f[i-1][j+1][1])+y);
			for(int j=1;j<=tot;++j) f[i][j][1]=min(f[i][j][1],min(f[i-1][j-1][0],f[i-1][j-1][1]));
			if(i>1) for(int j=0;j<=tot;++j)
				f[i][j][0]=min(f[i][j][0],min(f[i-2][j][0],f[i-2][j][1])+(a[i]-a[i-1])*1ll*x);
		}
		if(a[tot/2]+1<a[tot/2+1]||tot>2) ans=tot/2*1ll*y;
		else if(a[2]+1<n||a[1]>2) ans=y*2ll;
		else if(a[1]>1&&a[2]<n) ans=y*3ll;
		else ans=x;
		printf("%lld\n",min(ans,f[tot][0][0]));
	}
	return 0;
}