#include<bits/stdc++.h>
using namespace std;
char s[55][55];
int sum[55][55];
int f[55][55][55][55];
inline void dmin(int& x,int y){ x=min(x,y); }
int query(int i,int j,int x,int y){
	return sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1];
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		for(int j=1;j<=n;++j)
			sum[i][j]=(s[i][j]=='#');
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
	for(int len1=1;len1<=n;++len1)
		for(int i=1;i+len1-1<=n;++i)
			for(int len2=1;len2<=n;++len2)
				for(int j=1;j+len2-1<=n;++j){
					int x=i+len1-1,y=j+len2-1;
					f[i][j][x][y]=max(x-i+1,y-j+1);
					if(query(i,j,x,y)==0){
						f[i][j][x][y]=0;
						continue;
					}
					for(int k=i;k<=x;++k)	
						dmin(f[i][j][x][y],f[i][j][k][y]+f[k+1][j][x][y]);
					for(int k=j;k<=y;++k)
						dmin(f[i][j][x][y],f[i][j][x][k]+f[i][k+1][x][y]);
				}
	printf("%d\n",f[1][1][n][n]);
	return 0;
}