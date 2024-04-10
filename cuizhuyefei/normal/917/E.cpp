#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,m,q,ans[N];vector<Pii>e[N];
struct sampos{
	int x,y,len;bool gg;
	sampos(){x=1;y=0;len=0;gg=0;}
}zheng[N],fan[N];
struct SAM{
	int ch[N][26],Max[N],fa[N],cnt=1,lst=1,dl[N],dr[N],num;
	Vi pos[N],s[N],e[N];Pii right[N];
	void ins(int c, int i, int j){
		int p=lst,np=++cnt;lst=np;Max[np]=Max[p]+1;
		for(;!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p)fa[np]=1;
		else{
			int q=ch[p][c];
			if(Max[q]==Max[p]+1)fa[np]=q;
			else{
				int nq=++cnt;Max[nq]=Max[p]+1;
				memcpy(ch[nq],ch[q],104);
				fa[nq]=fa[q];fa[q]=fa[np]=nq;
				for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
			}
		}
		if(SZ(pos[i])<=j)pos[i].resize(j+1);pos[i][j]=np;
		if(SZ(s[i])<=j)s[i].resize(j+1);s[i][j]=c;
		right[np]=Pii(i,j);
	}
	void dfs(int u){
		dl[u]=++num;
		rep(i,0,SZ(e[u])-1)dfs(e[u][i]),right[u]=max(right[u],right[e[u][i]]);
		dr[u]=num;
	}
	int qaq[N][26];
	void init(){
		rep(i,2,cnt)e[fa[i]].pb(i);
		dfs(1);
		rep(i,1,cnt)rep(j,0,SZ(e[i])-1){
			int v=e[i][j];
			if(Max[i]!=Max[v])qaq[i][s[right[v].fi][right[v].se+Max[i]]]=j;
		}
	}
	inline sampos trans(sampos a, int c){
		if(a.gg)return a;
		if(!a.y){
		//	rep(i,0,SZ(e[a.x])-1){
			if(SZ(e[a.x]))rep(i,qaq[a.x][c],qaq[a.x][c]){
				int v=e[a.x][i];assert(i<SZ(e[a.x]));
				if(Max[a.x]<Max[v]&&c==s[right[v].fi][right[v].se+Max[a.x]]){
					a.len++;if(a.len==Max[v])a.x=v,a.y=0;else a.y=v;
					return a;
				}
			}
			a.gg=1;return a;
		}
		int v=a.y;
		if(c==s[right[v].fi][right[v].se+a.len]){
			a.len++;if(a.len==Max[v])a.x=v,a.y=0;return a;
		}
		a.gg=1;return a;
	}
	void debug(){
		rep(i,1,cnt){
			printf("%d:%d %d\n",i,fa[i],Max[i]);
			rep(j,0,SZ(e[i])-1){
				int v=e[i][j];
				printf("e %d %d ",i,v);
				rep(k,Max[i],Max[v]-1)printf("%c",'a'+s[right[v].fi][right[v].se+k]);
				puts("");
			}
		//	rep(j,0,25)if(ch[i][j])printf("ch[%d][%c]=%d\n",i,'a'+j,ch[i][j]);
		}
	}
}sam1,sam2;
struct AC{
	int pos[N],ch[N][26],fail[N],tot,dl[N],dr[N],num;Vi e[N],s[N];
	void ins(char *s, int n, int p){
		int now=0;rep(i,1,n){
			int c=s[i]-'a';
			if(!ch[now][c])ch[now][c]=++tot;
			now=ch[now][c];
		}
		pos[p]=now;
	}
	void dfs(int u){
		rep(i,0,25)if(!ch[u][i])ch[u][i]=ch[fail[u]][i];
		dl[u]=++num;rep(i,0,SZ(e[u])-1)dfs(e[u][i]);
		dr[u]=num;
		/*rep(i,0,25)if(!ch[u][i]){
			int x=fail[u];while(x&&!ch[x][i])x=fail[x];ch[u][i]=ch[x][i];
		}*/
		//root first is correct???
	}
	void init(){
		static int q[N];int f=0,r=0;
		rep(i,0,25)if(ch[0][i]){q[r++]=ch[0][i];}
		while(f!=r){
			int u=q[f++];
			rep(i,0,25)if(ch[u][i]){
				int v=ch[u][i],x=fail[u];
				while(x&&!ch[x][i])x=fail[x];
				fail[v]=ch[x][i];q[r++]=v;
			}
		}
		rep(i,1,tot)e[fail[i]].pb(i);
		dfs(0);
	}
	int v[N];
	void Modify(int p, int x){
		while(p<=num+1)v[p]+=x,p+=p&-p;
	}
	int Query(int p){int r=0;while(p)r+=v[p],p-=p&-p;return r;}
	void modify(int u, int x){
		Modify(dl[u],x);
	}
	int query(int u){
		u=pos[u];return Query(dr[u])-Query(dl[u]-1);
	}
}ac1,ac2;
	struct atom{
		int x,l,r,idx,v,k;
	};
	bool cmp(atom a, atom b){
		if(a.k!=b.k)return a.k<b.k;
		if(a.x!=b.x)return a.x<b.x;
		return a.idx<b.idx;
	}
struct yzrqaq{
	atom s[N<<2];int n,v[N],sz;
	void ins(int x, int y, int k, int idx){//printf("ins %d %d %d %d\n",x,y,k,idx);
		atom u;u.x=x;u.l=u.r=y;u.idx=idx;u.k=k;s[++n]=u;
	}
	void insm(int k, int l1, int r1, int l2, int r2){//printf("ins %d %d %d %d %d\n",k,l1,r1,l2,r2);
		assert(l1<=r1&&l2<=r2);
		atom u;u.x=l1;u.l=l2;u.r=r2;u.idx=0;u.v=1;u.k=k;s[++n]=u;
		u.x=r1+1;u.v=-1;s[++n]=u;
	}
	void modify(int p, int x){while(p<=sz)v[p]+=x,p+=p&-p;}//printf("m %d %d\n",p,x);
	int query(int p){int r=0;while(p)r+=v[p],p-=p&-p;return r;}//printf("q %d\n",p);
	void solve(int l1,int l2){
		sort(s+1,s+n+1,cmp);sz=max(l1,l2);
		rep(l,1,n){
			int r;for(r=l;r<=n;r++)if(s[l].k!=s[r].k)break;
			rep(i,l,r-1){
				if(!s[i].idx)modify(s[i].l,s[i].v),modify(s[i].r+1,-s[i].v);
				else ans[s[i].idx]+=query(s[i].l);
			}
			rep(i,l,r-1)if(!s[i].idx)modify(s[i].l,-s[i].v),modify(s[i].r+1,s[i].v);//clear
			l=r-1;
		}
	}
}yzr;
struct Que{int u,v,k,idx;};vector<Que>Pass[N];
bool gg[N];int T,sz[N],bel[N];
void getsz(int u, int fa){
	sz[u]=1;Pass[u].clear();
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa&&!gg[e[u][i].fi]){
		int v=e[u][i].fi;getsz(v,u);sz[u]+=sz[v];
	}
}
void getcen(int u, int fa, Pii &res){
	int mx=T-sz[u];
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa&&!gg[e[u][i].fi]){
		int v=e[u][i].fi;getcen(v,u,res);umax(mx,sz[v]);
	}
	res=min(res,Pii(mx,u));
}
void getbel(int u, int fa, int val){
	bel[u]=val;
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa&&!gg[e[u][i].fi])
		getbel(e[u][i].fi,u,val);
}
void solveac(int u, int fa, int x, int y){
	ac1.modify(x,1);ac2.modify(y,1);
	rep(i,0,SZ(Pass[u])-1)
		ans[Pass[u][i].idx]+=Pass[u][i].v==u?ac1.query(Pass[u][i].k):ac2.query(Pass[u][i].k);
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa&&!gg[e[u][i].fi]){
		int v=e[u][i].fi,c=e[u][i].se;
		solveac(v,u,ac1.ch[x][c],ac2.ch[y][c]);
	}
	ac1.modify(x,-1);ac2.modify(y,-1);
}
void solvesam(int u, int fa, sampos x, sampos y){
	zheng[u]=x;fan[u]=y;
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa&&!gg[e[u][i].fi])//TLE
		solvesam(e[u][i].fi,u,sam1.trans(x,e[u][i].se),sam2.trans(y,e[u][i].se));
}
void solve(int rt,vector<Que>qaq){
	getsz(rt,0);T=sz[rt];Pii res(1e9,0);getcen(rt,0,res);
	rt=res.se;gg[rt]=1;
	bel[rt]=-1;rep(i,0,SZ(e[rt])-1)if(!gg[e[rt][i].fi])getbel(e[rt][i].fi,rt,i);
	vector<vector<Que> >nxt;nxt.resize(SZ(e[rt]));
	vector<Que>tmp;
	rep(i,0,SZ(qaq)-1)
		if(bel[qaq[i].u]>=0&&bel[qaq[i].v]>=0&&bel[qaq[i].u]==bel[qaq[i].v])
			nxt[bel[qaq[i].u]].pb(qaq[i]);
		else tmp.pb(qaq[i]);
	qaq=tmp;tmp.clear();
	rep(i,0,SZ(qaq)-1)Pass[qaq[i].u].pb(qaq[i]),Pass[qaq[i].v].pb(qaq[i]);
//	printf("solve %d %d\n",rt,SZ(qaq));
//	rep(i,0,SZ(qaq)-1)printf("query %d %d %d %d\n",qaq[i].u,qaq[i].v,qaq[i].k,qaq[i].idx);
	//ac
	solveac(rt,0,0,0);
	//sam
	sampos t1,t2;solvesam(rt,0,t1,t2);
	rep(i,0,SZ(qaq)-1){
		yzr.ins(sam1.dl[zheng[qaq[i].v].x],sam2.dl[fan[qaq[i].u].x],qaq[i].k,qaq[i].idx);
	//	printf("pos=%d\n",fan[qaq[i].u].x);
	}
	
	rep(i,0,SZ(e[rt])-1)if(!gg[e[rt][i].fi])solve(e[rt][i].fi,nxt[i]);
}
int main() {
	read(n);read(m);read(q);
	rep(i,1,n-1){
		int u,v;read(u);read(v);char S[3];scanf("%s",S);
		e[u].pb(Pii(v,S[0]-'a'));e[v].pb(Pii(u,S[0]-'a'));
	}
	rep(i,1,m){
		static char s[N],t[N];scanf("%s",s+1);int l=strlen(s+1);
		rep(i,1,l)t[i]=s[l-i+1];
		ac1.ins(s,l,i);ac2.ins(t,l,i);
		sam1.lst=1;per(j,l,1)sam1.ins(s[j]-'a',i,j);
		sam2.lst=1;per(j,l,1)sam2.ins(t[j]-'a',i,j);
	}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	ac1.init();ac2.init();
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	sam1.init();sam2.init();
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	vector<Que>qaq;
	rep(i,1,q){
		Que x;
		read(x.u);read(x.v);read(x.k);x.idx=i;qaq.pb(x);
	}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	solve(1,qaq);
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	rep(i,1,m){
		int l=SZ(sam1.s[i])-1;
		rep(j,1,l-1){//1..j j+1..l
			int u=sam1.pos[i][j+1],v=sam2.pos[i][l+1-j];
			while(sam1.fa[u]&&sam1.Max[u]==sam1.Max[sam1.fa[u]])u=sam1.fa[u];
			while(sam2.fa[v]&&sam2.Max[v]==sam2.Max[sam2.fa[v]])v=sam2.fa[v];
		//	printf("cutpos %d %d\n",u,v);
			yzr.insm(i,sam1.dl[u],sam1.dr[u],sam2.dl[v],sam2.dr[v]);
		}
	}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	yzr.solve(sam1.cnt+2,sam2.cnt+2);
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
//	sam2.debug();
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}