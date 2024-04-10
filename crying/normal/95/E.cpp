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
const int MAXN=1e5+10,INF=1e8;
int n,m,u,v;
int fa[MAXN],sz[MAXN];
int w[MAXN],tot,f[MAXN],cnt[MAXN],ans=INF;
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
void Merge(int x,int y){
	if(Find(x)==Find(y))return;
	sz[Find(y)]+=sz[Find(x)];
	fa[Find(x)]=Find(y);
}
bool lucky(int x){
	if(x<9)return (x==4) || (x==7);
	else return ((x%10==4) || (x%10==7)) && lucky(x/10);
}
int main(){
	cin>>n>>m;
	rep(i,1,n)fa[i]=i,sz[i]=1;
	rep(i,1,m){
		cin>>u>>v;Merge(u,v);
	}
	rep(i,1,n){if(Find(i)!=i)continue;
		cnt[sz[i]]++;
	}
	rep(i,1,n)f[i]=INF;
	rep(i,1,n){if(!cnt[i])continue;
		ll w=1,rest=cnt[i];
		while(rest){
			w=Min(w,rest);
			per(j,n,i*w)f[j]=Min(f[j],f[j-i*w]+w);
			rest-=w;
			w*=2;
		}
	}
	rep(i,1,n){
		if(lucky(i))ans=Min(ans,f[i]-1);
	}
	if(ans>=1e7)ans=-1;
	printf("%d",ans);
	return 0;
}