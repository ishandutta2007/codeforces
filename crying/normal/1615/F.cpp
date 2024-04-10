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
const int MAXN=2010,ADD=2002,mod=1e9+7;
int T,n;
char s[MAXN],t[MAXN];
int f[MAXN][2*MAXN],g[MAXN][2*MAXN];
int check(int flag,int i,int j){
	if(flag==0){
		if(s[i]=='?' || s[i]=='0'+j)return 1;
		else return 0;
	}else{
		if(t[i]=='?' || t[i]=='0'+j)return 1;
		else return 0;
	}
}
void solve(){
	scanf("%d%s%s",&n,s+1,t+1);
	rep(i,1,n){if(odd(i))continue;
		if(s[i]=='0')s[i]='1';
		else if(s[i]=='1')s[i]='0';
		if(t[i]=='0')t[i]='1';
		else if(t[i]=='1')t[i]='0';
	} 
	rep(i,0,n+1)rep(j,-n,n)f[i][j+ADD]=g[i][j+ADD]=0;
	f[0][ADD]=g[n+1][ADD]=1;
	rep(i,0,n-1){
		rep(j,-n,n){
			rep(x,0,1)rep(y,0,1){
				if(!check(0,i+1,x) || !check(1,i+1,y))continue;
				f[i+1][j+x-y+ADD]=(f[i+1][j+x-y+ADD]+f[i][j+ADD])%mod;
			}
		}
	}
	per(i,n+1,2){
		rep(j,-n,n){
			rep(x,0,1)rep(y,0,1){
				if(!check(0,i-1,x) || !check(1,i-1,y))continue;
				g[i-1][j+x-y+ADD]=(g[i-1][j+x-y+ADD]+g[i][j+ADD])%mod;	
			}
		}
	}
	ll ans=0;
	rep(i,1,n){
		rep(j,-i,i){
			ll ret=abs(j);
			ret=ret*f[i][j+ADD]%mod*g[i+1][-j+ADD]%mod;
			ans=(ans+ret)%mod;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}