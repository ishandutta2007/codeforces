#include <bits/stdc++.h>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
const int N=2007;
const int mod=998244353;
int f[N][N][2][2];
int n,k;
void add(int &x,int y){x=(x+y<mod)?x+y:x+y-mod;}
int main()
{
	scanf("%d%d",&n,&k);
	f[1][1][0][0]=f[1][1][1][1]=1;
	f[1][2][1][0]=f[1][2][0][1]=1;
	rep(i,n-1){
		rep(j,k){
			add(f[i+1][j][0][0],f[i][j][0][0]);
			add(f[i+1][j][0][0],f[i][j][0][1]);
			add(f[i+1][j][0][0],f[i][j][1][0]);
			add(f[i+1][j+1][0][0],f[i][j][1][1]);
			add(f[i+1][j][1][1],f[i][j][1][1]);
			add(f[i+1][j][1][1],f[i][j][1][0]);
			add(f[i+1][j][1][1],f[i][j][0][1]);
			add(f[i+1][j+1][1][1],f[i][j][0][0]);
			add(f[i+1][j+1][0][1],f[i][j][0][0]);
			add(f[i+1][j+1][0][1],f[i][j][1][1]);
			add(f[i+1][j][0][1],f[i][j][0][1]);
			add(f[i+1][j+2][0][1],f[i][j][1][0]);
			add(f[i+1][j+1][1][0],f[i][j][0][0]);
			add(f[i+1][j+1][1][0],f[i][j][1][1]);
			add(f[i+1][j][1][0],f[i][j][1][0]);
			add(f[i+1][j+2][1][0],f[i][j][0][1]);
		}
	}
	int ans=0;
	rep0(i,2)rep0(j,2)add(ans,f[n][k][i][j]);
	printf("%d\n",ans);
	return 0 ;
}