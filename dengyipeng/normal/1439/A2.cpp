#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 105
using namespace std;

int T,n,m,i,j,k,s[maxn][maxn],c[2],d[2][5][2];
int tot,ans[maxn*maxn][6];

void add(int a,int b,int c,int d,int e,int f){
	if (a<1||a>n||c<1||c>n||e<1||e>n)
		printf("!!");
	if (b<1||b>m||d<1||d>m||f<1||f>m)
		printf("!!");
	s[a][b]^=1,s[c][d]^=1,s[e][f]^=1;
	tot++;
	ans[tot][0]=a,ans[tot][1]=b;
	ans[tot][2]=c,ans[tot][3]=d;
	ans[tot][4]=e,ans[tot][5]=f;
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		char ch=getchar();
		for(i=1;i<=n;i++) for(j=1;j<=m;j++){
			while (ch<'0'||ch>'1') ch=getchar();
			s[i][j]=ch-'0',ch=getchar();
		}
		tot=0;
		for(i=1;i<=n-2;i++) {
			for(j=1;j<m;j++) if (s[i][j])
				add(i,j,i+1,j,i,j+1);
			if (s[i][m])
				add(i,m,i+1,m-1,i+1,m);
		}
		for(i=1;i<=m-2;i++) if (s[n-1][i]||s[n][i]){
			if (s[n-1][i]&&s[n][i]) add(n-1,i,n,i,n,i+1); else 
			if (s[n-1][i]) add(n-1,i,n-1,i+1,n,i+1); else 
			if (s[n][i]) add(n,i,n-1,i+1,n,i+1);
		}
		c[0]=c[1]=0;
		for(i=0;i<2;i++) for(j=0;j<2;j++){
			k=s[n-i][m-j],c[k]++;
			d[k][c[k]][0]=n-i;
			d[k][c[k]][1]=m-j;
		}
		if (c[1]==1){
			add(d[1][1][0],d[1][1][1],d[0][1][0],d[0][1][1],d[0][2][0],d[0][2][1]);
			add(d[1][1][0],d[1][1][1],d[0][1][0],d[0][1][1],d[0][3][0],d[0][3][1]);
			add(d[1][1][0],d[1][1][1],d[0][2][0],d[0][2][1],d[0][3][0],d[0][3][1]);
		} else 
		if (c[1]==2){
			add(d[1][1][0],d[1][1][1],d[0][1][0],d[0][1][1],d[0][2][0],d[0][2][1]);
			add(d[1][2][0],d[1][2][1],d[0][1][0],d[0][1][1],d[0][2][0],d[0][2][1]);
		} else 
		if (c[1]==3){
			add(d[1][1][0],d[1][1][1],d[1][2][0],d[1][2][1],d[1][3][0],d[1][3][1]);
		} else 
		if (c[1]==4){
			add(d[1][1][0],d[1][1][1],d[1][2][0],d[1][2][1],d[1][3][0],d[1][3][1]);
			add(d[1][1][0],d[1][1][1],d[1][3][0],d[1][3][1],d[1][4][0],d[1][4][1]);
			add(d[1][1][0],d[1][1][1],d[1][2][0],d[1][2][1],d[1][4][0],d[1][4][1]);
			add(d[1][2][0],d[1][2][1],d[1][3][0],d[1][3][1],d[1][4][0],d[1][4][1]);
		}
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) if (s[i][j])
			printf("!!");
		if (tot>n*m)
			printf("!!");
		printf("%d\n",tot);
		for(i=1;i<=tot;i++)
			printf("%d %d %d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3],ans[i][4],ans[i][5]);
	}
}