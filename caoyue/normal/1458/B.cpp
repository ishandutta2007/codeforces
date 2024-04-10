#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=107;
const int M=10007;
const int INF=1e9+7;
int f[N][M],a[N],b[N];
int n,T=0;

int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d%d",&a[i],&b[i]);
		a[i]-=b[i];
		T+=b[i];
	}
	rep0(i,n+1)rep0(j,n*100+1)f[i][j]=-INF;
	f[0][0]=0;
	rep(i,n)for(int j=n-1;~j;j--)rep0(k,n*100+1)f[j+1][k+b[i]]=max(f[j+1][k+b[i]],f[j][k]+a[i]);
	rep(i,n){
		int Ans=0;
		rep0(j,n*100+1)Ans=max(Ans,min(f[i][j]*2,(T-j))+j*2);
		printf("%.10lf\n",((db)(Ans))/2);
	}
	return 0;
}