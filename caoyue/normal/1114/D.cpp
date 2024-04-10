#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
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
const int N=5007;
const int INF=1e9+7;
int a[N],s[N],f[2][N][N];
int n,m=0;

int main(){
	cin>>n;
	rep(i,n)scanf("%d",&s[i]);
	rep(i,n)if(s[i]!=s[i-1])a[++m]=s[i];
	memset(f,120,sizeof(f));
	rep(i,m)f[0][i][i]=f[1][i][i]=0;
	for(int L=m;L;L--){
		REP(R,L+1,m){
			f[0][L][R]=min(f[0][L][R],f[0][L+1][R]+(a[L]!=a[L+1]));
			f[0][L][R]=min(f[0][L][R],f[1][L+1][R]+(a[L]!=a[R]));
			f[1][L][R]=min(f[1][L][R],f[0][L][R-1]+(a[R]!=a[L]));
			f[1][L][R]=min(f[1][L][R],f[1][L][R-1]+(a[R]!=a[R-1]));
		}
	}
	printf("%d\n",min(f[0][1][m],f[1][1][m]));
	return 0;
}