#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=110,LIM=100,mod=1000000007;
int n,m,K,c[MAXN][MAXN],f[2][MAXN][MAXN][MAXN]; //good 
int ans;
int main(){
	cin>>n>>m>>K;n++;
	c[0][0]=1;
	rep(i,1,LIM){
		c[i][0]=1;
		rep(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod; 
	}
	f[0][0][1][1]=1; 
	rep(i,0,m-1){
		int ret=0;
		memset(f[(i+1)&1],0,sizeof f[(i+1)&1]);
		rep(j,0,n){
			rep(k,1,n){
				rep(cnt,1,K){
					if(!f[i&1][j][k][cnt])continue; //
					rep(x,k,n-j){
						if((ll)cnt*c[x-1][k-1] <= (ll)K){
							f[(i+1)&1][j+x][x-k][cnt*c[x-1][k-1]]=
							(f[(i+1)&1][j+x][x-k][cnt*c[x-1][k-1]]+f[i&1][j][k][cnt])%mod;
						}
					} 
				}
			}
		}
		rep(j,2,n){
			rep(cnt,1,K){
				ret=(ret+f[(i+1)&1][j][0][cnt])%mod;
			}
		}
		ans=((ll)ans+(ll)ret*(m-i))%mod;
	}
	printf("%d\n",ans);
	return 0;
}