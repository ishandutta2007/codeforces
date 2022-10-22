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
const int N=227;
const int INF=1e9+7;
int a[N],f[N][3];
char s[N];
int n;

int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,n)if(s[i]=='0')a[i]++;
	scanf("%s",s+1);
	rep(i,n)if(s[i]=='0')a[i]++;
	rep(i,n){
		rep0(j,a[i]+1){
			rep0(k,a[i-1]+1){
				int v=a[i]-j;
				if(v&&k&&(v>1||k>1))f[i][j]=max(f[i][j],f[i-1][k]+1);
				else f[i][j]=max(f[i][j],f[i-1][k]);
			}
		}
	}
	printf("%d\n",max(f[n][0],max(f[n][1],f[n][2])));
	return 0;
}