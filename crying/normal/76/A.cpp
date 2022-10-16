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
const ll MAXN=210,MAXM=5e4+10,INF=3e18;
struct Edge{
	int u,v,w1,w2;
	bool operator<(const Edge& e2)const{
		return w1<e2.w1;
	}
}edge[MAXM],t[MAXN],tmp[MAXN];
bool cmp(const Edge& e1,const Edge& e2){
	return e1.w2<e2.w2;
}
int n,m,s,g,tot;
ll ans=INF;
int fa[MAXN];
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
int Kruskal(){
	int cnt=0,val=0;
	sort(t+1,t+1+tot,cmp);
	rep(i,1,n)fa[i]=i;
	rep(i,1,tot){
		int u=t[i].u,v=t[i].v;
		if(Find(u)==Find(v))continue;
		tmp[++cnt]=t[i];val=t[i].w2;fa[Find(u)]=Find(v);
	}
	rep(i,1,cnt)t[i]=tmp[i];tot=cnt;
	if(cnt==n-1)return val;
	else return -1;
}
int main(){
	cin>>n>>m>>g>>s;
	rep(i,1,n)fa[i]=i;
	rep(i,1,m){
		cin>>edge[i].u>>edge[i].v>>edge[i].w1>>edge[i].w2;
		fa[Find(edge[i].u)]=Find(edge[i].v);
	}
	rep(i,1,n)if(Find(i)!=Find(1))return printf("-1"),0;
	sort(edge+1,edge+1+m);
	rep(i,1,m){
		t[++tot]=edge[i];
		int cost=Kruskal();
		if(cost!=-1){
			ans=Min(ans,(ll)edge[i].w1*g+(ll)cost*s);
		}
	}
	cout<<ans;
	return 0;
}