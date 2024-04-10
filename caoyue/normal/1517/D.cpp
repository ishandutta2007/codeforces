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
const int N=507;
const int M=25;
const int INF=1e9+7;
int n,m,k;
int f[N][N][M],to[N][N][4];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,n){
		rep(j,m-1){
			int x; scanf("%d",&x);
			to[i][j][2]=to[i][j+1][3]=x;
		}
	}
	rep(i,n-1){
		rep(j,m){
			int x; scanf("%d",&x);
			to[i][j][0]=to[i+1][j][1]=x;
		}
	}
	if(k&1){
		rep(i,n){
			rep(j,m)printf("-1 ");
			puts("");
		}
		return 0;
	}
	k/=2;
	rep(i,n)rep(j,m)f[i][j][0]=0;
	rep(o,k){
		rep(i,n){
			rep(j,m){
				f[i][j][o]=INF;
				if(i>1)f[i][j][o]=min(f[i][j][o],f[i-1][j][o-1]+to[i][j][1]);
				if(i<n)f[i][j][o]=min(f[i][j][o],f[i+1][j][o-1]+to[i][j][0]);
				if(j>1)f[i][j][o]=min(f[i][j][o],f[i][j-1][o-1]+to[i][j][3]);
				if(j<m)f[i][j][o]=min(f[i][j][o],f[i][j+1][o-1]+to[i][j][2]);
			}
		}
	}
	rep(i,n){
		rep(j,m)printf("%d ",2*f[i][j][k]);
		puts("");
	}
	return 0;
}