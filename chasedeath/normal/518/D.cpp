#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
int rd() {
	int s=0;
	char x=getchar();
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')s=s*10+(x^'0'),x=getchar();
	return s;
}
#define reg register
typedef long long ll;

const int N=2000+10,P=1e9+7,base=1e8;


int n,m;
struct Edge{
	int to,nxt,w;
}e[N*2];
int head[N],ecnt;
void AddEdge(int u,int v,int w){
	e[++ecnt].nxt=head[u];
	e[ecnt].to=v;e[ecnt].w=w;
	head[u]=ecnt; 
}


double p,dp[N][N];

int main(){
	n=rd(),scanf("%lf",&p),m=rd();
	dp[0][0]=1;
	for(int i=0;i<m;i++){
		dp[i+1][n]+=dp[i][n];
		for(int j=0;j<n;j++)if(dp[i][j]>1e-10){
			dp[i+1][j+1]+=dp[i][j]*p;
			dp[i+1][j]+=dp[i][j]*(1-p);
		}
	}
	double ans=0;
	for(int i=1;i<=n;i++)ans+=dp[m][i]*i;
	printf("%.6lf\n",ans);
}