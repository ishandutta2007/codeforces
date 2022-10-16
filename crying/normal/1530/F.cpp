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
const int MAXN=21,mod=31607;
int power(int a,int n){
	if(!n)return 1;
	int tmp=power(a,n/2);tmp=tmp*tmp%mod;if(n&1)tmp=tmp*a%mod;return tmp;
}
int n,a[MAXN][MAXN],g[MAXN][1<<MAXN],f[1<<MAXN],inv,ret;
int pcnt[1<<MAXN];
int main(){
	cin>>n;
	inv=power(10000,mod-2);
	int lim=(1<<n);
	rep(i,1,lim-1)pcnt[i]=pcnt[i^lowbit(i)]+1; 
	rep(i,0,n-1){
		g[i][0]=1;
		rep(j,0,n-1){
			cin>>a[i][j];
			a[i][j]=a[i][j]*inv%mod;
			g[i][1<<j]=a[i][j];
		}
		rep(j,1,lim-1){
			g[i][j]=g[i][j^lowbit(j)]*g[i][lowbit(j)]%mod; 
		}
	}
	rep(flag,0,3){
		// 
		rep(i,0,lim-1)if(odd((pcnt[flag]+pcnt[i])))f[i]=mod-1;else f[i]=1;
		rep(i,0,n-1){
			rep(j,0,lim-1){
				int state=j;
				if(flag&1)state|=(1<<i);
				if(flag&2)state|=(1<<(n-i-1));
				int val=(g[i][state]-g[i][lim-1]+mod)%mod;
				f[j]=f[j]*val%mod;
			}
		}
		rep(i,0,lim-1)ret=(ret+f[i])%mod;
	}
	printf("%d\n",(1-ret+mod)%mod);

	return 0;
}