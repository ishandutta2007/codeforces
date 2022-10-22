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
const int N=5007;
const int INF=1e9+7;
char a[N],b[N];
int n,m,Ans=0;
int f[N][N];

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	f[0][0]=0;
	rep0(i,n+1){
		rep0(j,m+1){
			if(i!=n)f[i+1][j]=max(f[i+1][j],f[i][j]-1);
			if(j!=m)f[i][j+1]=max(f[i][j+1],f[i][j]-1);
			if(i!=n&&j!=m&&a[i+1]==b[j+1])f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+2);
			Ans=max(Ans,f[i][j]);
		}
	}
	printf("%d\n",Ans);
	return 0;
}