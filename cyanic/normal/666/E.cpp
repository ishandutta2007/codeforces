#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define qwq(x) cerr<<"# "<<#x<<" = "<<x<<endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bits bitset<N>
using namespace std;
typedef unsigned long long u64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=500005;
namespace seg{
	int lc[N*20],rc[N*20],sz;
	pii T[N*20];
	int ins(int l,int r,int x){
		int o=++sz;
		if(l==r)return T[o]=mp(1,-x),o;
		int m=(l+r)>>1;
		if(x<=m)lc[o]=ins(l,m,x);
		else rc[o]=ins(m+1,r,x);
		T[o]=max(T[lc[o]],T[rc[o]]);
		return o;
	}
	int merge(int x,int y,int l,int r){
		if(!x||!y)return x|y;
		if(l==r){
			int o=++sz;
			T[o]=mp(T[x].fi+T[y].fi,-l);
			return o;
		}
		int m=(l+r)>>1,o=++sz;
		lc[o]=merge(lc[x],lc[y],l,m);
		rc[o]=merge(rc[x],rc[y],m+1,r);
		T[o]=max(T[lc[o]],T[rc[o]]);
		return o;
	}
	pii	qry(int o,int l,int r,int x,int y){
		if(!o)return mp(0,0);
		if(l==x&&y==r)return T[o];
		int m=(l+r)>>1;
		if(y<=m)return qry(lc[o],l,m,x,y);
		if(m<x)return qry(rc[o],m+1,r,x,y);
		return max(qry(lc[o],l,m,x,m),qry(rc[o],m+1,r,m+1,y));
	}
}

int n;

namespace sam{
	int fa[N],t[N][26],mx[N],cur[N];
	int rt=1,sz=1,las; vi e[N];
	void init(){las=rt;}
	int nw(int v){return mx[++sz]=v,sz;}
	void ins(int c,int pos){
		int p=las,np=nw(mx[p]+1);
		if(pos)cur[np]=seg::ins(1,n,pos);
		for(;!t[p][c];p=fa[p])t[p][c]=np;
		if(!p)return (void)(fa[np]=rt,las=np);
		int q=t[p][c];
		if(mx[q]==mx[p]+1)fa[np]=q;
		else{
			int nq=nw(mx[p]+1);
			fa[nq]=fa[q],fa[q]=fa[np]=nq;
			memcpy(t[nq],t[q],sizeof t[q]);
			for(;t[p][c]==q;p=fa[p])t[p][c]=nq;
		}
		las=np;
	}
	void dfs(int u){
		for(auto v:e[u])
			dfs(v),cur[u]=seg::merge(cur[u],cur[v],1,n);
	}
	void build(){
		rep(i,2,sz)e[fa[i]].pb(i);
		dfs(rt);
	}
	pii solve(int p,int len,int l,int r){
		while(p!=rt&&mx[fa[p]]>=len)p=fa[p];
		if(mx[p]<len)return mp(0,0);
		return seg::qry(cur[p],1,n,l,r);
	}
}

int owo[N],ovo[N],m,Q,a,b,c,d;
char s[N],t[N];

int main(){
	scanf("%s",s+1);
	m=strlen(s+1);
	read(n);
	rep(i,1,n){
		scanf("%s",t+1);
		sam::init();
		for(int k=1;t[k];k++)
			sam::ins(t[k]-'a',i);
	}
	sam::build();
	int pos=sam::rt,len=0;
	rep(i,1,m){
		while(pos&&!sam::t[pos][s[i]-'a'])
			pos=sam::fa[pos],len=sam::mx[pos];
		if(!pos){
			pos=sam::rt,len=0;
			continue;
		}
		pos=sam::t[pos][s[i]-'a'],len++;
		owo[i]=pos,ovo[i]=len;
	}
	read(Q);
	while(Q--){
		read(c),read(d),read(a),read(b);
		if(ovo[b]<b-a+1){
			printf("%d 0\n",c);
			continue;
		}
		pii res=sam::solve(owo[b],b-a+1,c,d);
		if(!res.fi)printf("%d 0\n",c);
		else printf("%d %d\n",-res.se,res.fi);
	}
	return 0;
}