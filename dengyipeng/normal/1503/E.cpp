#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 4050
#define ll long long 
#define mo 998244353
using namespace std;

int n,m,i,j,k;
ll C[maxn][maxn],f[maxn],g[maxn],ans,F[maxn][4];
ll S(int n,int m){return C[n+m][m];}

int main(){
	scanf("%d%d",&n,&m);
	for(C[0][0]=1,i=1;i<maxn;i++) for(C[i][0]=1,j=1;j<=i;j++)
		C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	for(i=1;i<n;i++){
		F[0][0]=1;
		for(j=1;j<=m;j++){
			for(k=0;k<4;k++) F[j][k]=F[j-1][k];
			(F[j][0]+=S(i-1,j))%=mo;
			(F[j][1]+=F[j-1][0]*S(i-1,m-j))%=mo;
			(F[j][2]+=F[j][1]*S(n-i-1,j))%=mo;
			(F[j][3]+=F[j-1][2]*S(n-i-1,m-j))%=mo;
		}
		(ans+=F[m][3])%=mo;
	}
	swap(n,m);
	for(i=1;i<n;i++){
		F[0][0]=1;
		for(j=1;j<=m;j++){
			for(k=0;k<4;k++) F[j][k]=F[j-1][k];
			(F[j][0]+=S(i-1,j))%=mo;
			(F[j][1]+=F[j-1][0]*S(i-1,m-j))%=mo;
			(F[j][2]+=F[j][1]*S(n-i-1,j))%=mo;
			(F[j][3]+=F[j-1][2]*S(n-i-1,m-j))%=mo;
		}
		(ans+=F[m][3])%=mo;
	}
	swap(n,m);
	for(i=1;i<n;i++){
		F[0][0]=1;
		for(j=1;j<=m;j++){
			for(k=0;k<4;k++) F[j][k]=F[j-1][k];
			(F[j][0]+=S(i-1,j))%=mo;
			(F[j][1]=F[j-1][0]*S(i-1,m-j))%=mo;
			(F[j][2]+=F[j][1]*S(n-i-1,j))%=mo;
			(F[j][3]+=F[j-1][2]*S(n-i-1,m-j))%=mo;
		}
		(ans-=F[m][3])%=mo;
	}
	ans=ans*2%mo;
	printf("%lld\n",(ans+mo)%mo);
}