#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 2005
#define mo 1000000007
#define ll long long 
using namespace std;

int n,m,i,j,k,map[maxn][maxn];
int nex0[maxn][maxn],nex1[maxn][maxn];
ll f[maxn][maxn][2],s0[maxn][maxn],s1[maxn][maxn];
char ch;

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) {
		for(ch=getchar();ch!='.'&&ch!='R';ch=getchar());
		map[i][j]=ch=='R';
	}
	for(i=n;i;i--) 
		for(j=m;j;j--) {
			nex0[i][j]=nex0[i][j+1]+map[i][j];
			nex1[i][j]=nex1[i+1][j]+map[i][j];
		}
	if (n==m&&n==1)  {
		printf("1");
		return 0;
	}
	f[1][1][0]=f[1][1][1]=1,f[1][2][0]=-1,f[2][1][1]=-1;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) {
		(f[i][j][0]+=f[i][j-1][0])%=mo;
		(f[i][j][1]+=f[i-1][j][1])%=mo;
		(f[i][j+1][0]+=f[i][j][1])%=mo;
		(f[i][m-nex0[i][j+1]+1][0]-=f[i][j][1])%=mo;
		(f[i+1][j][1]+=f[i][j][0])%=mo;
		(f[n-nex1[i+1][j]+1][j][1]-=f[i][j][0])%=mo;
	}
	printf("%I64d",((f[n][m][0]+f[n][m][1])%mo+mo)%mo);
}