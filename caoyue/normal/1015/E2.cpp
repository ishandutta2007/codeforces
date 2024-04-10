#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
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
int u[N][N],d[N][N],l[N][N],r[N][N],qr[N][N],qc[N][N];
bool a[N][N];
char s[N];
int n,m,k=0;

int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		scanf("%s",s+1);
		rep(j,m)if(s[j]=='*')a[i][j]=1;
	}
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	memset(u,-1,sizeof(u));
	memset(d,-1,sizeof(d));
	rep(i,n){
		rep(j,m)if(!a[i][j])l[i][j]=-1;else l[i][j]=l[i][j-1]+1;
		for(int j=m;j;j--)if(!a[i][j])r[i][j]=-1;else r[i][j]=r[i][j+1]+1;
	}
	rep(i,m){
		rep(j,n)if(!a[j][i])u[j][i]=-1;else u[j][i]=u[j-1][i]+1;
		for(int j=n;j;j--)if(!a[j][i])d[j][i]=-1;else d[j][i]=d[j+1][i]+1;
	}
	rep(i,n){
		rep(j,m){
			if(!a[i][j])continue;
			int L=min(u[i][j],min(d[i][j],min(r[i][j],l[i][j])));
			if(!L)continue;
			k++;
			qr[i][j-L]++;
			qr[i][j+L+1]--;
			qc[i-L][j]++;
			qc[i+L+1][j]--;
		}
	}
	rep(i,n)rep(j,m)qr[i][j]+=qr[i][j-1];
	rep(i,m)rep(j,n)qc[j][i]+=qc[j-1][i];
	rep(i,n){
		rep(j,m){
			if(a[i][j]&&!qr[i][j]&&!qc[i][j]){
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",k);
	rep(i,n){
		rep(j,m){
			if(!a[i][j])continue;
			int L=min(u[i][j],min(d[i][j],min(r[i][j],l[i][j])));
			if(L)printf("%d %d %d\n",i,j,L);
		}
	}
	return 0;
}