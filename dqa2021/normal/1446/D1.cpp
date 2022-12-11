#include<cstdio>
#include<algorithm>
#include<cctype>
//#include<vector>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
int U=100;  //!!!

int n,a[200010];
bool f[200010][110];  //if can be fre
int g[200010][110];  //tab for pre
int h[200010][110],htop[110];  //first time to get that
int ans;
void work(int x){
//	printf("work %d\n",x);
	for (int i=1;i<=U;i++) htop[i]=0;
	for (int i=1;i<=n;i++){
		if (a[i]==x){
			for (int j=1;j<=U;j++){
				if (j==x) continue;
				if (htop[j]<g[i][x]-g[i][j]) h[++htop[j]][j]=i/*,printf("a %d b %d val %d: %d\n",j,x,g[i][x]-g[i][j],i)*/;
				/*else{
					printf("checkans a %d b %d : %d  h %d\n",j,x,g[i][x]-g[i][j],h[max(0,g[i][x]-g[i][j])][j]);
					ans=max(ans,i-h[max(0,g[i][x]-g[i][j])][j]);
				}*/
			}
		}
		if (i<n&&a[i+1]!=x) continue;
		if (!f[i][x]) continue;
		for (int j=1;j<=U;j++){
			if (j==x) continue;
			if (htop[j]<g[i][x]-g[i][j]);/* h[++htop[j]][j]=i,printf("a %d b %d val %d: %d\n",j,x,g[i][x]-g[i][j],i);*/
			else{
//				printf("checkans a %d b %d : %d  h %d\n",j,x,g[i][x]-g[i][j],h[max(0,g[i][x]-g[i][j])][j]);
				ans=max(ans,i-h[max(0,g[i][x]-g[i][j])][j]);
			}
		}
	}
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++){
		int *F=g[i-1],*G=g[i]; bool *H=f[i];
		for (int j=1;j<=U;j++) G[j]=F[j];
		G[a[i]]++;
		int t=0;
		for (int j=1;j<=U;j++) t=max(t,G[j]);
		for (int j=1;j<=U;j++) H[j]=G[j]==t;
	}
	for (int i=1;i<=U;i++) work(i);
	printf("%d\n",ans);
	return 0;
}