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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
const ll MAXN=510,mod=998244353;
int T,n,a[MAXN*2][MAXN],tag[MAXN*2],g[MAXN*2][MAXN*2];
int bucket[MAXN];
ll ans;
vector<int>ret;
int check(int i,int j){
	rep(k,1,n)if(a[i][k]==a[j][k])return 1;
	return 0;
}
void dfs(){
	int flag=0;
	rep(i,1,2*n)if(!tag[i])flag=i;
	if(!flag)return;
	rep(j,1,n){
		int pos=0;
		rep(i,1,n*2)bucket[a[i][j]]=0;
		rep(i,1,n*2){if(tag[i])continue;
			bucket[a[i][j]]++;
		}
		rep(i,1,n*2){if(tag[i])continue;
			if(bucket[a[i][j]]==1)pos=i;
		}
		if(pos!=0){
			ret.pb(pos);
			rep(i,1,n*2){
				if(g[i][pos])tag[i]=1;
			}
			dfs();
			return;
		}
	}
	ans=ans*2%mod;
	ret.pb(flag);
	rep(i,1,n*2)if(g[i][flag])tag[i]=1;
	dfs();
}
void solve(){
	scanf("%d",&n);
	rep(i,1,n*2){
		tag[i]=0;
		rep(j,1,n){
			scanf("%d",&a[i][j]);
		}
	}
	rep(i,1,n*2){
		rep(j,i,n*2){
			if(check(i,j)){
				g[i][j]=g[j][i]=1;
			}else g[i][j]=g[j][i]=0;
		}
	}
	ans=1;ret.clear();
	dfs();
	printf("%lld\n",ans);
	sort(ret.begin(),ret.end());
	for(auto v:ret)printf("%d ",v);printf("\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}