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
const int INF=1e9+7;
int n;
int p[N],f[N][N][N][2];

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&p[i]);
	rep(i,n){
		if(!p[i])p[i]--;
		else p[i]&=1;
	}
	rep0(i,n+1)rep0(j,n+1)rep0(k,n+1)f[i][j][k][0]=f[i][j][k][1]=INF;
	if(p[1]>=0){
		if(p[1])f[1][0][1][p[1]]=0;
		else f[1][1][0][p[1]]=0;
	}
	else{
		f[1][1][0][0]=0;
		f[1][0][1][1]=0;
	}
	rep(i,n-1){
		rep0(j,n+1){
			rep0(k,n+1){
				rep0(o1,2){
					if(p[i]>=0&&p[i]!=o1)continue;
					rep0(o2,2){
						if(p[i+1]>=0&&p[i+1]!=o2)continue;
						f[i+1][j+(o2==0)][k+(o2==1)][o2]=min(f[i+1][j+(o2==0)][k+(o2==1)][o2],f[i][j][k][o1]+(o1^o2));
					}
				}
			}
		}
	}
	printf("%d\n",min(f[n][n/2][(n+1)/2][0],f[n][n/2][(n+1)/2][1]));
	return 0;
}