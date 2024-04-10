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
const int M=1e4+7;
const int INF=1e9+7;
int T,n,m,cnt;
struct sq{int x1,y1,x2,y2,x3,y3;}s[M];
int a[N][N];
char ss[N];

int main(){
	scanf("%d",&T);
	while(T--){
		cnt=0;
		scanf("%d%d",&n,&m);
		rep(i,n){
			scanf("%s",ss+1);
			rep(j,m)a[i][j]=ss[j]-'0';
		}
		rep(i,n-2){
			rep(j,m-2){
				if(a[i][j]){
					s[++cnt]=(sq){i,j,i+1,j,i+1,j+1};
					a[i][j]^=1;
					a[i+1][j]^=1;
					a[i+1][j+1]^=1;
				}
			}
		}
		rep(i,m-2){
			if(a[n-1][i]&&a[n][i]){
				s[++cnt]=(sq){n-1,i,n,i,n,i+1};
				a[n][i]^=1;
				a[n-1][i]^=1;
				a[n][i+1]^=1;
			}
			else{
				if(a[n-1][i]||a[n][i]){
					s[++cnt]=(sq){n,i+1,n-1,i+1,(a[n][i])?n:n-1,i};
					a[n-1][i]=a[n][i]=0;
					a[n][i+1]^=1;
					a[n-1][i+1]^=1;
				}
			}
		}
		rep(i,n-2){
			if(a[i][m-1]&&a[i][m]){
				s[++cnt]=(sq){i,m-1,i,m,i+1,m};
				a[i][m]^=1;
				a[i][m-1]^=1;
				a[i+1][m]^=1;
			}
			else{
				if(a[i][m-1]||a[i][m]){
					s[++cnt]=(sq){i+1,m-1,i+1,m,i,(a[i][m])?m:m-1};
					a[i][m-1]=a[i][m]=0;
					a[i+1][m]^=1;
					a[i+1][m-1]^=1;
				}
			}
		}
		if(a[n-1][m-1]){
			s[++cnt]=(sq){n-1,m-1,n,m,n,m-1};
			a[n][m-1]^=1;
			a[n][m]^=1;
		}
		if(a[n][m]){
			if(a[n-1][m]){
				if(a[n][m-1]){
					s[++cnt]=(sq){n,m,n,m-1,n-1,m};
				}
				else{
					s[++cnt]=(sq){n-1,m,n,m-1,n-1,m-1};
					s[++cnt]=(sq){n,m-1,n,m,n-1,m-1};
				}
			}
			else{
				if(a[n][m-1]){
					s[++cnt]=(sq){n,m,n-1,m,n-1,m-1};
					s[++cnt]=(sq){n,m-1,n-1,m,n-1,m-1};
				}
				else{
					s[++cnt]=(sq){n,m,n-1,m,n,m-1};
					s[++cnt]=(sq){n-1,m,n,m,n-1,m-1};
					s[++cnt]=(sq){n,m-1,n,m,n-1,m-1};
				}
			}
		}
		else{
			if(a[n-1][m]){
				if(a[n][m-1]){
					s[++cnt]=(sq){n-1,m,n,m,n-1,m-1};
					s[++cnt]=(sq){n,m-1,n,m,n-1,m-1};
				}
				else{
					s[++cnt]=(sq){n-1,m-1,n-1,m,n,m};
					s[++cnt]=(sq){n,m,n-1,m,n,m-1};
					s[++cnt]=(sq){n-1,m-1,n-1,m,n,m-1};
				}
			}
			else{
				if(a[n][m-1]){
					s[++cnt]=(sq){n,m-1,n-1,m-1,n,m};
					s[++cnt]=(sq){n,m,n-1,m,n,m-1};
					s[++cnt]=(sq){n-1,m-1,n-1,m,n,m-1};
				}
			}
		}
		printf("%d\n",cnt);
		rep(i,cnt)printf("%d %d %d %d %d %d\n",s[i].x1,s[i].y1,s[i].x2,s[i].y2,s[i].x3,s[i].y3);
	} 
	return 0;
}