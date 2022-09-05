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
const int N = 666666;
int qt[N],qtsz,sta[N],top,bs[N],cas;
int n,m,q,dfn[N],bel[N],fa[N],low[N],num,tot,cnt,block[N];ll R;
int head[N],to[N<<1],nxt[N<<1],edgenum=1;
void addedge(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
void getoneedge(int u, int v){
	addedge(u,v);addedge(v,u);
}
namespace yzr{
	int dfn[N],dr[N],num,fa[N],dep[N],jmp[N][19];Vi e[N];
	bool cmp1(int x, int y){return dfn[x]<dfn[y];}
	void addedge(int u, int v){e[u].pb(v);e[v].pb(u);}//printf("virtree %d %d\n",u,v);}
	void dfs(int u, int Fa, int Dep){
		fa[u]=Fa;dep[u]=Dep;dfn[u]=++num;
		rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)dfs(e[u][i],u,Dep+1);
		dr[u]=num;
	}
	int getlca(int u, int v){
		if(dep[u]<dep[v])swap(u,v);int del=dep[u]-dep[v];
		rep(i,0,18)if(del>>i&1)u=jmp[u][i];if(u==v)return u;
		per(i,18,0)if(jmp[u][i]!=jmp[v][i])u=jmp[u][i],v=jmp[v][i];
		return jmp[u][0];
	}
	void ini(){
		rep(i,1,n)if(!dep[i])dfs(i,0,1);
		rep(i,1,n)jmp[i][0]=fa[i];
		rep(j,1,18)rep(i,1,n)jmp[i][j]=jmp[jmp[i][j-1]][j-1];
	//	printf("qaq %d\n",getlca(2,7));
	}
	bool isup(int u, int v){return dfn[u]<=dfn[v]&&dr[u]>=dfn[v];}
	void virtualtree(int *s, int len){
		sort(s+1,s+len+1,cmp1);
		static int ext[N],sta[N];int sz=0,top=0;
		rep(i,1,len)
			if(!top||isup(sta[top],s[i]))fa[s[i]]=sta[top],sta[++top]=s[i];
			else{
				int lca=getlca(sta[top],s[i]);
				while(top>=2&&dep[sta[top-1]]>dep[lca])top--;
				if(sta[top-1]==lca)top--,fa[s[i]]=sta[top],sta[++top]=s[i];
				else{
					ext[++sz]=lca;
					fa[sta[top]]=lca;top--;
					fa[lca]=sta[top];sta[++top]=lca;
					fa[s[i]]=lca;sta[++top]=s[i];
				}
			}
		/*if(cas==q){
			rep(i,1,n)rep(j,i+1,n)printf("%d %d:%d\n",i,j,getlca(i,j));
			rep(i,1,len)printf("fa %d %d\n",s[i],fa[s[i]]);
			rep(i,1,sz)printf("fa %d %d\n",ext[i],fa[ext[i]]);
		}*/
		rep(i,1,len)if(fa[s[i]])getoneedge(s[i],fa[s[i]]),fa[s[i]]=0;
		rep(i,1,sz)if(fa[ext[i]])getoneedge(ext[i],fa[ext[i]]),fa[ext[i]]=0;
		rep(i,1,sz)qt[++qtsz]=ext[i];
	}
}
void tarjan(int u, int Fa, int *bel){
	dfn[u]=low[u]=++num;sta[++top]=u;
	L(i,u)
		if(!dfn[to[i]]){tarjan(to[i],i>>1,bel),umin(low[u],low[to[i]]);}
		else if((i>>1)!=Fa&&dfn[to[i]]<dfn[u])umin(low[u],dfn[to[i]]);
	if(dfn[u]==low[u]){
		cnt++;block[cnt]=tot;
		while(1){int x=sta[top--];bel[x]=cnt;if(x==u)break;}
	}
}
int rotate(int x){x=(x+R)%n;return !x?x+n:x;}
bool cmp(int x, int y){return block[x]!=block[y]?block[x]<block[y]:x<y;}
int main() {
	read(n);read(m);read(q);
	rep(i,1,m){
		int u,v;read(u);read(v);getoneedge(u,v);
	}
	rep(i,1,n)if(!dfn[i]){
		++tot;tarjan(i,0,bel);
	}
	rep(u,1,n)L(i,u)if(u<to[i]&&bel[u]!=bel[to[i]])yzr::addedge(bel[u],bel[to[i]]);
	rep(i,1,n)head[i]=0;edgenum=1;yzr::ini();
	memset(dfn,0,sizeof(dfn));
	
//	rep(i,1,n)printf("%d:%d\n",i,bel[i]);
	
	for(cas=1;cas<=q;cas++){
		int v,E;read(v);read(E);qtsz=0;
		static int dot[N<<1],ori[N];int sz=v;
		rep(i,1,v){
			read(dot[i]),dot[i]=rotate(dot[i]);
			dot[i]=bel[dot[i]],ori[i]=dot[i];
		//	printf("bel_dot %d\n",dot[i]);
		}
		rep(i,1,E){
			int u,v;read(u);read(v);
			u=rotate(u);v=rotate(v);
			u=bel[u];v=bel[v];
			dot[++sz]=u;dot[++sz]=v;
			if(u!=v)getoneedge(u,v);
		//	printf("bel_edge %d %d\n",u,v);
		}
		sort(dot+1,dot+sz+1,cmp);int newsz=0;
		rep(i,1,sz)if(dot[i]!=dot[newsz])dot[++newsz]=dot[i];sz=newsz;
		rep(l,1,sz){
			int r=l;while(r+1<=sz&&block[dot[l]]==block[dot[r+1]])r++;
			yzr::virtualtree(dot+l-1,r-l+1);
			l=r;
		}
		rep(i,1,qtsz)dot[++sz]=qt[i];sort(dot+1,dot+sz+1);sz=unique(dot+1,dot+sz+1)-dot-1;
	//	printf("Q ");rep(i,1,v)printf("%d ",ori[i]);puts("");
	//	printf("dot ");rep(i,1,sz)printf("%d ",dot[i]);puts("");
	//	rep(i,1,sz)L(j,dot[i])if(dot[i]<to[j])printf("%d %d\n",dot[i],to[j]);
		tarjan(ori[1],0,bs);bool ok=1;rep(i,2,v)ok&=bs[ori[1]]==bs[ori[i]];
		if(ok)R+=cas,puts("YES");else puts("NO");
		rep(i,1,sz)head[dot[i]]=0,dfn[dot[i]]=0;edgenum=1;
	}
	return 0;
}