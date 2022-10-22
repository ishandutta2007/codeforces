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
const int N=1007;
const int INF=1e9+7;
int n;
int p[N][N],q[N][N];
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&p[1][i]);
	rep(i,n){
		rep(j,n-i+1)q[i+j-1][j]=p[i][j]+i-1;
		int id=-1;
		rep(j,n){
			if(p[i][j]==1){
				id=j;
				break;
			}
		}
		int cnt=0;
		rep(j,n){
			if(p[i][j]==1)continue;
			p[i+1][++cnt]=p[i][j]-1;
		}
	}
	rep(i,n){
		rep(j,i)printf("%d ",q[i][j]);
		puts("");
	}
	return 0;
}