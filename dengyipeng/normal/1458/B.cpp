#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 105
using namespace std;

int n,i,j,k,a[maxn],b[maxn],sum,f[2][maxn][maxn*maxn],s[maxn];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),sum+=b[i],s[i]=s[i-1]+a[i];
	memset(f,128,sizeof(f)),f[0][0][0]=0;
	for(i=1;i<=n;i++){
		int p=i&1,q=p^1;
		memset(f[p],128,sizeof(f[p]));
		for(j=0;j<i;j++) for(k=0;k<=s[i-1];k++)
			if (f[q][j][k]>=0){
				f[p][j][k]=max(f[p][j][k],f[q][j][k]);
				f[p][j+1][k+a[i]]=max(f[p][j+1][k+a[i]],f[q][j][k]+b[i]);
			}
	}
	for(i=1;i<=n;i++){
		int ans=0;
		for(j=0;j<=s[n];j++)
			ans=max(ans,min(j*2,f[n&1][i][j]+sum));
		printf("%.7lf\n",ans*0.5);
	}
}