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
const int MAXN=1e5+10,mod=1e9+7;
ll n,m,u,v,w,cnt;
ll fa[MAXN],d[MAXN],vis[MAXN];
ll power[MAXN];
int Find(int x){
	if(fa[x]==x)return x;
	int rt=Find(fa[x]);
	d[x]^=d[fa[x]];
	return fa[x]=rt;
}
int main(){
	power[0]=1;
	rep(i,1,1e5)power[i]=power[i-1]*2%mod;
	cin>>n>>m;
	rep(i,1,n)fa[i]=i;
	rep(i,1,m){
		cin>>u>>v>>w;
		int ru=Find(u),rv=Find(v);
		if(ru==rv){
			if(w==1){
				if(d[u]!=d[v])return printf("0"),0;
			}else{
				if(d[u]==d[v])return printf("0"),0;
			}
		}else{
			if(w==1){
				d[ru]=d[u]^d[v]; 
			}else{
				d[ru]=1^d[u]^d[v];
			}
			fa[ru]=rv;
		}
	}
	rep(i,1,n){
		if(vis[Find(i)])continue;
		vis[Find(i)]=1;cnt++;
	}
	cout<<power[cnt-1];
	return 0;
}