#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1005
using namespace std;

int T,n,m,i,j,k,a[maxn][maxn],b[maxn][maxn],p[3],d[3],c[3];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) for(j=0;j<n;j++) 
			scanf("%d",&a[i][j]),a[i][j]--;
		char ch=getchar();
		while (ch<'A'||ch>'Z') ch=getchar();
		p[0]=0,p[1]=1,p[2]=2,d[0]=d[1]=d[2]=0;
		for(i=1;i<=m;i++) {
			if (ch=='R') d[p[1]]++; else 
			if (ch=='L') d[p[1]]--; else 
			if (ch=='D') d[p[0]]++; else
			if (ch=='U') d[p[0]]--; else 
			if (ch=='I') swap(p[1],p[2]); else 
			if (ch=='C') swap(p[0],p[2]);
			ch=getchar();
		}
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			c[0]=((i+d[0])%n+n)%n,c[1]=((j+d[1])%n+n)%n,c[2]=((a[i][j]+d[2])%n+n)%n;
			b[c[p[0]]][c[p[1]]]=c[p[2]];
		}
		for(i=0;i<n;i++,printf("\n")) for(j=0;j<n;j++) printf("%d ",b[i][j]+1);
		printf("\n");
	}
}