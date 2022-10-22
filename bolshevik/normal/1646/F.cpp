#include<cstdio>
using namespace std;
const int o=110;
int n,c[o][o],d[o],ans[o*o][o],cnt,z[o][o];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) for(int j=1,k;j<=n;++j) scanf("%d",&k),++c[i][k];
	for(bool flg=1;flg;){
		flg=0;
		for(int i=1,j;i<=n;++i) for(d[i]=0,j=1;j<=n;++j) if(c[i][j]>1) d[i]=j;
		for(int i=1;i<=n;++i) if(d[i]){
			flg=1;ans[++cnt][i]=d[i];
			for(int j=i%n+1,lst=d[i];j^i;j=j%n+1)
				if(d[j]) lst=ans[cnt][j]=d[j];else ans[cnt][j]=lst;
			for(int j=1;j<=n;++j) --c[j][ans[cnt][j]],++c[j%n+1][ans[cnt][j]];
			break;
		}
	}
	for(int i=1;i<=n;++i) z[0][i]=i;
	for(int i=1,j;i<n;++i) for(z[i][n]=z[i-1][1],j=1;j<n;++j) z[i][j]=z[i-1][j+1];
	for(int i=1;i<n;++i) for(int j=i,k;j;--j) for(++cnt,k=1;k<=n;++k) ans[cnt][k]=z[j][k];
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i,putchar('\n')) for(int j=1;j<=n;++j) printf("%d ",ans[i][j]);
	return 0;
}