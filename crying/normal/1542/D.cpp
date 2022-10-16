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
const int MAXN=510,mod=998244353;
int n,a[MAXN],x;
ll f[MAXN][MAXN],ans;
char op;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf(" %c",&op);
		if(op=='-')a[i]=-1;
		else scanf("%d",&a[i]);
	}
	rep(i,1,n){
		if(a[i]<0)continue;
		memset(f,0,sizeof f);
		f[0][0]=1;
		rep(j,0,n-1){
			rep(k,0,n){
				if(j>=i && k==0){
					f[j][k]=0;continue;
				}
				if(a[j+1]<0){
					if(k)f[j+1][k-1]=(f[j+1][k-1]+f[j][k])%mod;
					else f[j+1][k]=(f[j+1][k]+f[j][k])%mod;
					f[j+1][k]=(f[j+1][k]+f[j][k])%mod;
					continue;
				}
				if(a[j+1]>a[i]){
					f[j+1][k]=(f[j+1][k]+2*f[j][k])%mod;
				}else if(a[j+1]<a[i]){
					f[j+1][k+1]=(f[j+1][k+1]+f[j][k])%mod; 
					f[j+1][k]=(f[j+1][k]+f[j][k])%mod;
				}else{
					if(j+1==i){
						f[j+1][k+1]=(f[j+1][k+1]+f[j][k])%mod; // 
					}else if(j+1<i){
						f[j+1][k+1]=(f[j+1][k+1]+f[j][k])%mod;
						f[j+1][k]=(f[j+1][k]+f[j][k])%mod;
					}else{
						f[j+1][k]=(f[j+1][k]+2*f[j][k])%mod;
					}
				}
			}
		}
		rep(rest,1,n){
			ans=(ans+a[i]*f[n][rest]%mod)%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}