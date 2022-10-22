#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
int f[1005][1005][2];
char x[1005],y[1005];
int main(){
	scanf("%s%s",x+1,y+1);
	int n=strlen(x+1),m=strlen(y+1),ans=0;
//	f[2][1][0]=f[2][1][1]=1;
	for(int i=1;i<=n+1;++i)
		for(int j=1;j<=m+1;++j){
			mo(ans+=f[i][j][0]);
			mo(ans+=f[i][j][1]);
//			printf("[%d %d %d %d]",i,j,f[i][j][0],f[i][j][1]);
			//opera i
			if(i<=n){
				if(x[i-1]!=x[i]) mo(f[i+1][j][0]+=f[i][j][0]);
				if(y[j-1]!=x[i]) mo(f[i+1][j][0]+=f[i][j][1]);
				if(i<=n&&j<=m) mo(f[i+1][j][0]+=1);
			}
			//opera j
			if(j<=m){
				if(x[i-1]!=y[j]) mo(f[i][j+1][1]+=f[i][j][0]);
				if(y[j-1]!=y[j]) mo(f[i][j+1][1]+=f[i][j][1]);
				if(i<=n&&j<=m) mo(f[i][j+1][1]+=1);
			}
		}
	for(int i=1;i<=n;++i){
		int cnt=0;
		for(int j=i;j<=n;++j){
			if(j==i||x[j]!=x[j-1]) ++cnt;
			else break;
		}
//		printf("<%d>",cnt);
		mo(ans+=MOD-1ll*cnt*m%MOD);
	}
	for(int i=1;i<=m;++i){
		int cnt=0;
		for(int j=i;j<=m;++j){
			if(j==i||y[j]!=y[j-1]) ++cnt;
			else break;
		}
		mo(ans+=MOD-1ll*cnt*n%MOD);
	}
	printf("%d\n",ans);
	return 0;
}