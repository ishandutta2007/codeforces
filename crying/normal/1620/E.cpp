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
const int MAXN=1e6+10,LIM=5e5;
int q,op,x,y,tot,cur,fa[MAXN*2],rt[MAXN],tag[MAXN*2],col[MAXN*2];
int ans[MAXN];
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
int main(){
	tot=LIM;
	rep(i,1,tot)fa[i]=i,rt[i]=i,col[i]=i;
	cin>>q;
	rep(i,1,q){
		cin>>op;
		if(op==1){
			cin>>x;
			tot++;cur++;tag[tot]=cur;fa[tot]=Find(rt[x]);
		}else{
			cin>>x>>y;
			if(x==y)continue;
			fa[Find(rt[x])]=Find(rt[y]);
			tot++;fa[tot]=tot;rt[x]=tot;col[tot]=x;
		}
	}
	rep(i,1,tot){
		if(!tag[i])continue;
		int u=Find(i);
		ans[tag[i]]=col[u]; 
	}
	rep(i,1,cur)printf("%d ",ans[i]);
	return 0;
}