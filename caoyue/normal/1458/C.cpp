#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int M=1055;
const int N=1e5+7;
const int INF=1e9+7;
int T,n,m;
char s[N];
int w[3],a[3],g[3],p[M][M],q[M][M];

int main(){
	scanf("%d",&T);
	rep(o,T){
		scanf("%d%d",&n,&m);
		rep(i,n)rep(j,n)scanf("%d",&p[i][j]);
		rep0(i,3){
			w[i]=i;
			a[i]=0;
		}
		scanf("%s",s+1);
		rep(i,m){
			if(s[i]=='L')a[w[1]]--;
			if(s[i]=='R')a[w[1]]++;
			if(s[i]=='U')a[w[0]]--;
			if(s[i]=='D')a[w[0]]++;
			if(s[i]=='I')swap(w[1],w[2]);
			if(s[i]=='C')swap(w[0],w[2]);
		}
		rep(i,n){
			rep(j,n){
				g[0]=(i-1+a[0]%n+n)%n+1;
				g[1]=(j-1+a[1]%n+n)%n+1;
				g[2]=(p[i][j]-1+a[2]%n+n)%n+1;
				q[g[w[0]]][g[w[1]]]=g[w[2]];
			}
		}
		rep(i,n){
			rep(j,n)printf("%d ",q[i][j]);
			puts("");
		}
		if(o!=T)puts("");
	}
	return 0;
}