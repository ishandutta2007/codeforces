#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 5005
using namespace std;

int n,m,i,j,k,a[maxn],b[maxn],f[maxn][maxn];
char ch;

int main(){
	scanf("%d%d",&n,&m),ch=getchar();
	while (ch<'a'||ch>'z') ch=getchar();
	for(i=1;i<=n;i++) a[i]=ch-'a',ch=getchar();
	while (ch<'a'||ch>'z') ch=getchar();
	for(i=1;i<=m;i++) b[i]=ch-'a',ch=getchar();
	memset(f,128,sizeof(f));
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) f[i][j]=4*(a[i]==b[j])-2;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		if (i<n) f[i+1][j]=max(f[i+1][j],f[i][j]-1);
		if (j<m) f[i][j+1]=max(f[i][j+1],f[i][j]-1);
		if (i<n&&j<m) 
			f[i+1][j+1]=max(f[i+1][j+1],f[i][j]-2+(a[i+1]==b[j+1])*4);
	}
	int ans=0;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) ans=max(ans,f[i][j]);
	printf("%d\n",ans);
}