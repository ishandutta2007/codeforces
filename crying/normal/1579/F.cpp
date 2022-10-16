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
const int MAXN=1e6+10;
int T,n,d,a[MAXN],vis[MAXN],tot,ans;
vector<int>v[MAXN];
void solve(){
	scanf("%d%d",&n,&d);
	tot=ans=0;
	rep(i,1,n){
		scanf("%d",&a[i]);
		vis[i]=0;
	}
	rep(i,1,n){
		if(vis[i])continue;
		int u=i;tot++;v[tot].clear();
		int flag=0,lst=-1,fr=-1;
		while(!vis[u]){
			vis[u]=1;
			if(a[u]==0)flag=1;
			if(a[u]==0 && fr==-1)fr=v[tot].size();
			v[tot].pb(u);
			u=u+d;if(u>n)u-=n;
		}
		if(!flag){printf("-1\n");return;}
		int sz=v[tot].size();
		per(i,sz-1,0){
			if(a[v[tot][i]]==0)lst=i;
			int ret=fr-i;
			if(ret<0)ret+=sz;
			if(lst!=-1){
				ret=min(ret,lst-i);
			}
			ans=max(ans,ret);
		}
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();

	return 0;
}