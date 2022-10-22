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
const int N=57;
const int INF=1e9+7;
int T;
int a[N][N];

int main(){
	scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		a[1][1]=a[n][1]=a[1][m]=a[n][m]=1;
		REP(i,2,m-1){
			if(a[1][i-1]||a[1][i+1])continue;
			a[1][i]=a[n][i]=1;
		}
		REP(i,2,n-1){
			if(a[i-1][1]||a[i+1][1])continue;
			a[i][1]=a[i][m]=1;
		}
		rep(i,n){
			rep(j,m)printf("%d",a[i][j]);
			puts("");
		}
		puts("");
	}
	return 0;
}