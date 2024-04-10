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
const int N = 600004, inf = 0x3f3f3f3f;
int n,m,L,R,A[N],B[N],qzA[N],qzB[N],hzA[N],hzB[N];Pii seg[N];
int head[N],to[N*8],nxt[N*8],edgenum;
int dy(int x, int y){return x+y*n;}//y=0 1
inline void addedge(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
int dfn[N],low[N],sta[N],top,col[N],num,cnt;
bool insta[N];
inline void tarjan(int u) {
	dfn[u]=low[u]=++num; sta[++top]=u; insta[u]=1;
	L(i,u) if (!dfn[to[i]]) {
		tarjan(to[i]); low[u]=min(low[u],low[to[i]]);
	}
	else if (insta[to[i]]) low[u]=min(low[u],dfn[to[i]]);
	if (dfn[u]==low[u]) {
		cnt++;
		while (1) {
			int x=sta[top--]; insta[x]=0; 
			col[x]=cnt; if (x==u) break;
		}
	}
}
bool cmp1(int x, int y){return seg[x].se<seg[y].se;}
bool cmp2(int x, int y){return seg[x].fi<seg[y].fi;}
void solve(int p1, int b1, int p2, int b2){
//	cerr<<p1<<' '<<b1<<' '<<p2<<' '<<b2<<endl;
	memset(head,0,sizeof(head));edgenum=1;num=cnt=top=0;
	memset(dfn,0,sizeof(dfn));memset(insta,0,sizeof(insta));
	rep(i,1,m){
		addedge(dy(A[i],0),dy(B[i],1));addedge(dy(A[i],1),dy(B[i],0));
		addedge(dy(B[i],0),dy(A[i],1));addedge(dy(B[i],1),dy(A[i],0));
	}
	int tot=n*2;
	rep(i,1,n)qzA[i]=++tot;rep(i,2,n)addedge(qzA[i],qzA[i-1]);
	rep(i,1,n)qzB[i]=++tot;rep(i,2,n)addedge(qzB[i],qzB[i-1]);
	rep(i,1,n)hzA[i]=++tot;rep(i,1,n-1)addedge(hzA[i],hzA[i+1]);
	rep(i,1,n)hzB[i]=++tot;rep(i,1,n-1)addedge(hzB[i],hzB[i+1]);
	static int id[N],s[N];
	rep(i,1,n)id[i]=i;sort(id+1,id+n+1,cmp1);rep(i,1,n)s[i]=seg[id[i]].se;
	rep(i,1,n)addedge(qzA[i],dy(id[i],0)),addedge(qzB[i],dy(id[i],1));
	rep(i,1,n){
		int p=lower_bound(s+1,s+n+1,seg[i].fi)-s-1;
		if(p)addedge(dy(i,0),qzB[p]),addedge(dy(i,1),qzA[p]);
	}
	//minr>=L-s[1]
	int sum=0;
	rep(i,1,n)if(seg[i].se<L-s[1]&&i!=p2)addedge(dy(i,b2^1),dy(i,b2)),sum++;//,cerr<<i<<' '<<b2<<endl;
	if(sum==n-1)return;//gg
	rep(i,1,n)id[i]=i;sort(id+1,id+n+1,cmp2);rep(i,1,n)s[i]=seg[id[i]].fi;
	rep(i,1,n)addedge(hzA[i],dy(id[i],0)),addedge(hzB[i],dy(id[i],1));
	rep(i,1,n){
		int p=upper_bound(s+1,s+n+1,seg[i].se)-s;
		if(p<=n)addedge(dy(i,0),hzB[p]),addedge(dy(i,1),hzA[p]);
	}
	//maxl<=R-s[n]
	sum=0;
	rep(i,1,n)if(seg[i].fi>R-s[n]&&i!=p1)addedge(dy(i,b1^1),dy(i,b1)),sum++;//,cerr<<i<<' '<<b1<<' '<<seg[i].fi<<' '<<R-s[n]<<endl;
	if(sum==n-1)return;//gg
	addedge(dy(p1,b1^1),dy(p1,b1));addedge(dy(p2,b2^1),dy(p2,b2));
	rep(i,1,tot)if(!dfn[i])tarjan(i);
	rep(i,1,n)if(col[dy(i,0)]==col[dy(i,1)])return;
	static int ans[N];rep(i,1,n)ans[i]=col[dy(i,0)]<col[dy(i,1)]?1:2;
	Pii zuo(-inf,inf),you(-inf,inf);
	rep(i,1,n)
		if(ans[i]==1)umax(zuo.fi,seg[i].fi),umin(zuo.se,seg[i].se);
		else umax(you.fi,seg[i].fi),umin(you.se,seg[i].se);
	assert(zuo.fi<=zuo.se&&you.fi<=you.se&&zuo.fi+you.fi<=R&&zuo.se+you.se>=L);
	int x=zuo.fi,y=you.fi;
	if(x+y<L){if(zuo.se+y<L)x=zuo.se;else x=L-y;}
	if(x+y<L){if(x+you.se<L)y=you.se;else y=L-x;}
	puts("POSSIBLE");printf("%d %d\n",x,y);
	rep(i,1,n)printf("%d",ans[i]);exit(0);
}
int main() {
	read(L);read(R);
	read(n);read(m);rep(i,1,n)read(seg[i].fi),read(seg[i].se);
	rep(i,1,m)read(A[i]),read(B[i]);
	/*if(n==1){
		if(seg[1].fi<=R&&seg[1].se>=L){
			puts("POSSIBLE");printf("%d %d\n1",x,y);
		}
		else puts("IMPOSSIBLE");
		return 0;
	}*/
	Pii qj(-inf,inf);
	rep(i,1,n)umax(qj.fi,seg[i].fi),umin(qj.se,seg[i].se);
	if(qj.fi<=qj.se&&qj.fi<=R&&!m){//one side
		puts("POSSIBLE");printf("%d %d\n",qj.fi,max(0,L-qj.fi));
		rep(i,1,n)printf("%d",1);exit(0);
	}
	
	int p1=1,p2=1;
	rep(i,1,n)if(seg[i].fi>seg[p1].fi)p1=i;//max_l
	rep(i,1,n)if(seg[i].se<seg[p2].se)p2=i;//min_r
	solve(p1,0,p2,1);
	solve(p1,0,p2,0);
	puts("IMPOSSIBLE");
	return 0;
}