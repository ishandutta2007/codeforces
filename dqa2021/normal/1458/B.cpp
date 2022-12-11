#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n;
int a[110],b[110];
double dp[2][110][40010]; int U=20000;
bool C;
inline void checkmax(double &x,double y){
	if (y>x) x=y;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read()<<1,b[i]=read()<<1;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=40000;j++)
			dp[C][i][j]=-1e18;
	dp[C][0][20000]=0;
	for (int i=1;i<=n;i++){
		C^=1;
		for (int j=0;j<=n;j++)
			for (int k=0;k<=40000;k++)
				dp[C][j][k]=-1e18;
		for (int j=0;j<i;j++){
			for (int k=0;k<=40000;k++){
				if (dp[C^1][j][k]==-1e18) continue;
//				printf("get dp %d %d %lf\n",i-1,j,(k-20000)*0.5);
				if (k+a[i]-b[i]<=40000) checkmax(dp[C][j+1][k+a[i]-b[i]],dp[C^1][j][k]+b[i]);
				if (k-(b[i]/2)>=0) checkmax(dp[C][j][k-(b[i]/2)],dp[C^1][j][k]+(b[i]/2));
			}
		}
	}
	for (int i=1;i<=n;i++){
		double ans=-1e18;
		for (int j=0;j<=40000;j++){
			ans=max(ans,dp[C][i][j]-max(0,20000-j));
		}
		printf("%.5lf ",ans/2);
	}
	puts("");
}