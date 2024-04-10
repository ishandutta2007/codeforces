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
const int N=4007;
const int INF=1e9+7;
int T,n;
bool f[N][N];
int p[N],w[N],h[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n); 
		rep(i,2*n)scanf("%d",&p[i]);
		int nw=0,cnt=0;
		rep(i,n*2){
			if(p[i]>nw){
				nw=p[i];
				w[++cnt]=i;
			}
		}
		w[cnt+1]=n*2+1;
		rep(i,cnt)h[i]=w[i+1]-w[i];
		rep0(i,cnt+1)rep0(j,n+1)f[i][j]=0;
		f[0][0]=1;
		rep0(i,cnt){
			rep0(j,n+1){
				f[i+1][j]|=f[i][j];
				f[i+1][j+h[i]]|=f[i][j];
			}
		}
		if(f[cnt][n])puts("YES");
		else puts("NO");
	}
	return 0;
}