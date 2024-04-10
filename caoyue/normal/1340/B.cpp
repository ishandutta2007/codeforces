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
const int N=2007;
const int INF=1e9+7;
int v[10]={6,2,5,5,4,5,6,3,7,6};
bool g[10][7]={
{1,1,1,0,1,1,1},
{0,0,1,0,0,1,0},
{1,0,1,1,1,0,1},
{1,0,1,1,0,1,1},
{0,1,1,1,0,1,0},
{1,1,0,1,0,1,1},
{1,1,0,1,1,1,1},
{1,0,1,0,0,1,0}, 
{1,1,1,1,1,1,1},
{1,1,1,1,0,1,1}
};
int f[N][N],mo[N][8],tr[N][N];
char s[7];
bool p[N][7],q[N];
int n,K;
 
int main(){
	scanf("%d%d",&n,&K);
	for(int i=n;i;i--){
		scanf("%s",s);
		rep0(j,7)p[i][j]=s[j]-'0';
		rep0(j,8)mo[i][j]=-1;
		int sp=0;
		rep0(j,7)sp+=p[i][j];
		rep0(j,10){
			bool fl=1;
			rep0(k,7)if(p[i][k]>g[j][k]){fl=0; break;}
			if(fl)mo[i][v[j]-sp]=max(mo[i][v[j]-sp],j);
		}
	}
	rep0(i,n+1)rep0(j,K+1)f[i][j]=-INF;
	f[0][0]=0;
	rep(i,n){
		rep0(j,K+1){
			rep0(k,8){
				if(~mo[i][k]&&j>=k){
					if(f[i-1][j-k]+1>f[i][j]){
						f[i][j]=f[i-1][j-k]+1;
						tr[i][j]=k;
					}
					else if(f[i-1][j-k]+1==f[i][j]&&mo[i][k]>mo[i][tr[i][j]])tr[i][j]=k;
				}
			}
		}
	}
	if(f[n][K]<=0)puts("-1");
	else{
		for(int i=n,nw=K;i;i--){
			if(tr[i][nw]>=0){
				putchar('0'+mo[i][tr[i][nw]]);
				nw-=tr[i][nw];
			}
		}
		puts("");
	}
	return 0;
}