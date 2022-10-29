#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 305
using namespace std;

int T,n,m,i,j,k,a[maxn*maxn],p[maxn*maxn],c[maxn*maxn][2],bz[maxn][maxn];
int cmp(int i,int j){return a[i]<a[j]||a[i]==a[j]&&i<j;}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n*m;i++) scanf("%d",&a[i]),p[i]=i;
		sort(p+1,p+1+n*m,cmp);
		for(i=1;i<=n;i++) for(j=1;j<=m;j=k) {
			for(k=j+1;k<=m&&a[p[(i-1)*m+k]]==a[p[(i-1)*m+k-1]];k++);
			for(int l=1;l<=(k-j)/2;l++) 
				swap(p[(i-1)*m+j+l-1],p[(i-1)*m+k-l]);
		}
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) 
			k=(i-1)*m+j,c[p[k]][0]=i,c[p[k]][1]=j,bz[i][j]=0;
		int ans=0;
		for(i=1;i<=n*m;i++){
			for(j=1;j<=c[i][1];j++)	
				ans+=bz[c[i][0]][j];
			bz[c[i][0]][c[i][1]]=1;
		}
		printf("%d\n",ans);
	}
}