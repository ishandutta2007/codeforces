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
const int MAXN=3e5+10;
ll T,n,m,p[MAXN],f[MAXN],g[MAXN];
map<ll,ll>cnt;
vector<ll>ret;
ll fa[MAXN],vis[MAXN];
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
int main(){
	cin>>T;
	while(T--){
		ret.clear();
		cin>>n>>m;
		ll val=0;
		rep(i,1,n){
			ll tmp;cin>>tmp;
			p[tmp]=i;
		}
		rep(i,1,n){
			if(i!=p[i])val++; 
		}
		f[0]=g[0]=f[n+1]=g[n+1]=0;
		cnt.clear();
		rep(i,1,n){
			cnt[p[i]-i]++;
			f[i]=i-cnt[n-i];
		}		
		cnt.clear();
		per(i,n,1){
			cnt[i-p[i]]++;
			g[i]=(n-i+1)-cnt[i-1];
		}
		rep(i,1,n){
			if((n-f[i]-g[i+1])<(n/3))continue;
			rep(j,1,n)fa[j]=j,vis[j]=0;
		//	printf("i:%d\n",i);
			rep(j,1,n){
				if(j<=i){
				//	printf("%d-%d\n",j+n-i,p[j]);
					fa[Find(j+n-i)]=Find(p[j]);	
				}else{
				//	printf("%d-%d\n",j-i+1,p[j]);
					fa[Find(j-i)]=Find(p[j]);
				}
			}
			ll num=0;
			rep(j,1,n){
				if(vis[Find(j)])continue;
				vis[Find(j)]=1;num++;
			}
			if(n-num<=m)ret.pb(n-i);
		}
		sort(ret.begin(),ret.end());
		ll sz=ret.size();
		printf("%lld ",sz);
		rep(j,0,sz-1)printf("%lld ",ret[j]);
		printf("\n");
	}

	return 0;
}
/*
1
4 1
2 3 1 4
3 1
*/