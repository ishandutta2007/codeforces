#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n;
string s[1000010];

int ch[26][1000010],fil[1000010],dep[1000010],ctot=1;
int g[1000010],h[1000010];  // max-dep key on fail tree

void ins(const string &s){
	int o=1;
	rep(i,0,s.size()-1){
		const int c=s[i]-'a';
		if (!ch[c][o]) ch[c][o]=++ctot,dep[ctot]=i+1;
		o=ch[c][o];
	}
	g[o]=dep[o];
}

int que[1000010],hd,tl;
void bfs(){
	fil[1]=1;
	rep(i,0,25) if (ch[i][1]) que[++tl]=ch[i][1],fil[que[tl]]=1; else ch[i][1]=1;
	while (hd<tl){
		const int u=que[++hd];
		rep(i,0,25){
			int &v=ch[i][u];
			if (v){
				fil[v]=ch[i][fil[u]];
				que[++tl]=v;
			}
			else{
				v=ch[i][fil[u]];
			}
		}
	}
	rep(i,1,tl){
		const int &x=que[i];
		if (!g[x]) g[x]=g[fil[x]],h[x]=h[fil[x]];
		else h[x]=x;
	}
}

int dfn[1000010],id[1000010],siz[1000010];
int lst[1000010],nxt[1000010];
inline void addedge(int x,int y){
	nxt[y]=lst[x],lst[x]=y;
}

void dfs(int x){
	id[dfn[++*dfn]=x]=++*id; siz[x]=1;
	for (int y=lst[x];y;y=nxt[y]){
		dfs(y);
		siz[x]+=siz[y];
	}
}

int work(const string &s){
//	printf("work %s\n",s.c_str());
	const int lim=s.size();
	int z=0;
	static int p[1000010];
	p[0]=1;
	rep(i,0,lim-1){
		p[i+1]=ch[s[i]-'a'][p[i]];
	}
	rep(i,0,lim) fprintf(stderr,"  p %d = %d\n",i,p[i]);
//	printf("lim %d p[lim] %d\n",lim,p[lim]);
	p[lim]=fil[p[lim]];
	int S=lim+1;
	static int c[1000010]; int top=0;
	per(i,1,lim){
		if (!g[p[i]]) continue;
		if (S<=i-g[p[i]]+1) c[++top]=id[p[i]];
		else c[++top]=id[fil[h[p[i]]]];
		S=min(S,i-g[p[i]]+1);
	}
//	rep(i,1,top) printf("  ban c %d = %d\n",i,c[i]);
	sort(c+1,c+top+1);
	static int vis[1000010],tim; ++tim;
	const auto chk=[&](const int &x){
		if (vis[x]==tim) return 0;
		vis[x]=tim;
		const int p=lower_bound(c+1,c+top+1,id[x])-c;
//		printf("ask %d: %d\n",x,p<=top&&c[p]<id[x]+siz[x]);
		return p<=top&&c[p]<id[x]+siz[x]?0:1;
	};
	rep(i,1,lim){
		if (g[p[i]]) z+=chk(h[p[i]]);
	}
//	printf("ans %d\n",z);
	return z;
}

void solve(){
	n=read();
	rep(i,1,n){
		static char t[1000010];
		scanf("%s",t);
		s[i]=t;
		ins(s[i]);
	}
	bfs();
	rep(i,2,ctot) addedge(fil[i],i);
	dfs(1);
	int ans=0;
	rep(i,1,n) ans+=work(s[i]);
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}