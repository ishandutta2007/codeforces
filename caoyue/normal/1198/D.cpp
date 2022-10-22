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
#include<time.h>
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
int f[N][N][N][N],nh[N][N],nl[N][N];
bool a[N][N];
int n;
char s[N];

int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%s",s+1);
		rep(j,n)a[i][j]=(s[j]=='#');
	}
	rep(i,n)rep(j,n)nh[i][j]=nh[i][j-1]+a[i][j];
	rep(i,n)rep(j,n)nl[j][i]=nl[j-1][i]+a[j][i];
	for(int i=n;i;i--){
		for(int j=n;j;j--){
			REP(k,i,n){
				REP(l,j,n){
					if(nh[i][j-1]==nh[i][l]){f[i][j][k][l]=f[i+1][j][k][l]; continue;}
					if(nh[k][j-1]==nh[k][l]){f[i][j][k][l]=f[i][j][k-1][l]; continue;}
					if(nl[i-1][j]==nl[k][j]){f[i][j][k][l]=f[i][j+1][k][l]; continue;}
					if(nl[i-1][l]==nl[k][l]){f[i][j][k][l]=f[i][j][k][l-1]; continue;}
					f[i][j][k][l]=max(k-i,l-j)+1;
					REP(o,i+1,k-1)if(nh[o][j-1]==nh[o][l])f[i][j][k][l]=min(f[i][j][k][l],f[i][j][o-1][l]+f[o+1][j][k][l]);
					REP(o,j+1,l-1)if(nl[i-1][o]==nl[k][o])f[i][j][k][l]=min(f[i][j][k][l],f[i][j][k][o-1]+f[i][o+1][k][l]);
				}
			}
		}
	}
	printf("%d\n",f[1][1][n][n]);
	return 0;
}