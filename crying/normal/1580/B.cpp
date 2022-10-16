#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=110;
int n,m,k,p;
int f[MAXN][MAXN][MAXN],g[MAXN],C[MAXN][MAXN];
int lim[MAXN];
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&p);
	if(n==1){
		if(m==1 && k==1)printf("%d\n",1%p);
		else printf("0");
		return 0;
	}
	//combine 
	C[0][0]=1;
	rep(i,1,100){
		C[i][0]=1;
		rep(j,1,i){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
		}
	}
	//catalan 
	g[0]=1;
	rep(i,1,n){
		rep(j,0,i-1){
			g[i]=(g[i]+1LL*C[i-1][j]*g[j]%p*g[i-j-1]%p)%p;
		}
	}
	//maxnumber of the nodes level i
	lim[1]=1;
	rep(i,2,n){
		lim[i]=min(101,lim[i-1]*2); 
	}
	//dp
	rep(depth,1,m)f[0][0][depth]=1;
	f[1][1][1]=1;
	rep(depth,2,m)f[1][0][depth]=1;
	rep(i,2,n){
		f[i][1][1]=g[i];
		rep(cnt,0,k){
			if(cnt>i)break;
			rep(depth,2,m){
				if(cnt>lim[depth])continue;
				if(cnt && cnt+depth-1>i)break;
				rep(a,0,i-1)rep(b,0,cnt){
					if(b>lim[depth-1])break;
					if(f[a][b][depth-1]==0)continue;
					if(f[i-1-a][cnt-b][depth-1]==0)continue;
					ll ret=C[i-1][a];
					ret=ret*f[a][b][depth-1]%p;
					ret=ret*f[i-1-a][cnt-b][depth-1]%p;
					f[i][cnt][depth]+=ret;
					if(f[i][cnt][depth]>=p)f[i][cnt][depth]-=p;
				}
			//	printf("f[%d][%d][%d]:%d\n",i,cnt,depth,f[i][cnt][depth]);
			}
		}
	}
	printf("%d",f[n][k][m]);
	
	return 0;
}