#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
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
const int MAXN=1e5+10;
const long double EPS=1e-12;
pi Pre[MAXN][10];
ll n,k,tot,tmp;
long double val[MAXN],f[MAXN][10];
ll ans[MAXN],a[MAXN],b[MAXN];
int main(){
	scanf("%lld%lld",&tmp,&k);
	rep(i,1,tmp){
		scanf("%lld",&b[i]);
		if(b[i]!=1){
			a[++n]=b[i];
		}else{
			ans[++tot]=1;
		}
	}
	sort(a+1,a+1+n);
	rep(i,1,n){
		val[i]=log2(a[i]);
	}
	memset(f,0,sizeof f);
	rep(i,1,n){
		f[i][a[i]%10]=val[i];
		Pre[i][a[i]%10]=mp(i,a[i]%10);
		rep(j,0,9){
			if(f[i-1][j]>f[i][j]){
				f[i][j]=f[i-1][j];
				Pre[i][j]=mp(i-1,j); 
			}
		}
		rep(j,0,9){
			if(f[i-1][j]){
				if(f[i][(j*a[i])%10]<f[i-1][j]+val[i]){
					f[i][(j*a[i])%10]=f[i-1][j]+val[i];
					Pre[i][(j*a[i])%10]=mp(i,(j*a[i])%10);
				}
			} 
		}
	}
	if(!f[n][k]){
		printf("-1\n");return 0;
	}
	int u=n,v=k;
	while(u>=1){
		int preu=Pre[u][v].fr,prev=Pre[u][v].se;
		if(mp(u,v)==mp(preu,prev)){
			ans[++tot]=a[u];
			if(f[u][v]==val[u])break; // 
			rep(j,0,9){
				if((j*a[u])%10==v && (fabs(f[u-1][j]+val[u]-f[u][v])<EPS)){
					preu=u-1;prev=j;goto END;
				}
			}
			END:u=preu,v=prev; 
		}else{u=preu,v=prev;}
	}
	printf("%lld\n",tot);
	rep(i,1,tot)printf("%lld ",ans[i]);
	return 0;
}