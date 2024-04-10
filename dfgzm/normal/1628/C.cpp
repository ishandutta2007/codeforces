#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1005;
int T,n,ans;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],f[maxn][maxn][2];
string s;
inline int get0(int ax,int ay,int bx,int by){
	if(ax>bx)
		swap(ax,bx),swap(ay,by);
	return b[bx][by]^b[ax-1][ay-1];
}
inline int get1(int ax,int ay,int bx,int by){
	if(ax>bx)
		swap(ax,bx),swap(ay,by);
	return c[bx][by]^c[ax-1][ay+1];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]),b[i][j]=b[i-1][j-1]^a[i][j],c[i][j]=c[i-1][j+1]^a[i][j];
		for(int t=1;t<=n-t+1;t++){
			int L=t,R=n-t+1;
			for(int i=L+1;i<=R;i++){
				f[L][i-1][0]=f[L-1][i][0]^get0(L,i,L+R-i,R);
				f[i-1][L][0]=f[i][L-1][0]^get0(i,L,R,L+R-i);
			}
			for(int i=L;i<=R-1;i++){
				f[L][i+1][1]=f[L-1][i][1]^get1(L,i,i,L);
				f[R][i-1][1]=f[R+1][i][1]^get1(R,i,i,R);
			}
			ans^=f[L][L][0],ans^=f[L][R][1];
			for(int i=L+1;i<=R-1;i++)
				ans^=f[L][i][0],ans^=f[i][L][0];
		}
		printf("%d\n",ans);
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				b[i][j]=c[i][j]=f[i][j][0]=f[i][j][1]=0;
	}
	return 0;
}