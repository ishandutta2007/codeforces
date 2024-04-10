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
const int MAXN=23,MAXM=2e4+10,LIM=(1<<MAXN),mod=998244353;
int n,f[1<<MAXN],g[1<<MAXN],F[1<<MAXN];
ll ans;
int pcnt[1<<MAXN],psum[1<<MAXN],tag[1<<MAXN];
char s[MAXN][MAXM];
int cnt[MAXN][26];

int main(){
	rep(i,0,22)tag[1<<i]=i;
	rep(i,1,(1<<23)-1){
		pcnt[i]=pcnt[i-lowbit(i)]+1;
		psum[i]=psum[i-lowbit(i)]+tag[lowbit(i)]+1;
	}
	scanf("%d",&n);
	rep(i,0,n-1){
		scanf("%s",s[i]+1);
		int len=strlen(s[i]+1);
		rep(j,1,len){
			cnt[i][s[i][j]-'a']++;
		}
	}
	rep(i,1,(1<<n)-1)f[i]=1;
	rep(i,0,25){
		g[0]=1e9;
		rep(j,1,(1<<n)-1){
			g[j]=min(g[j^lowbit(j)],cnt[tag[lowbit(j)]][i]);
			f[j]=1LL*f[j]*(g[j]+1)%mod;
		}
	}
	rep(i,1,(1<<n)-1){
		if(odd(pcnt[i]))F[i]=f[i];
		else F[i]=mod-f[i];
	}
	rep(i,0,22){
		rep(j,1,(1<<n)-1){
			if(j>>i&1){
				F[j]=(F[j]+F[j^(1<<i)])%mod;
			}
		}
	}
	rep(j,1,(1<<n)-1){
		ans^=(1LL*F[j]*pcnt[j]*psum[j]);
	}
	printf("%lld",ans);
	return 0;
}