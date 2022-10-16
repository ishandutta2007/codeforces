#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=510;
int T,n,m;
char s[MAXN][MAXN]; 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n+1)rep(j,1,m+1)s[i][j]='.';
		rep(i,1,n){
			rep(j,1,m){
				scanf(" %c",&s[i][j]);
			}
		}
		for(int i=1;i<=n;i+=3){
			rep(j,1,m)s[i][j]='X';
			if(i!=1){
				if(s[i-1][2]!='X' && s[i-2][2]!='X')s[i-1][1]=s[i-2][1]='X';
				else s[i-1][2]=s[i-2][2]='X';
			}
		}
		if(n%3==0){
			rep(j,1,m){
				if(s[n][j]=='X')s[n-1][j]='X';
			}
		}
		rep(i,1,n){
			rep(j,1,m){
				printf("%c",s[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}