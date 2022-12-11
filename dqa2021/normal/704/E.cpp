#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<set>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
const double eps=1e-9;

int n,m;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int fat[100010],dep[100010],son[100010],siz[100010];
int top[100010],id[100010],od[100010];
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=dep; siz[cur]=1;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^fat)
		{
			dfs1(v,cur,dep+1);
			siz[cur]+=siz[v];
			if (!son[cur]||siz[v]>siz[son[cur]]) son[cur]=v;
		}
}
void dfs2(int cur,int top)
{
	::top[cur]=top; od[id[cur]=++*id]=cur;
	if (siz[cur]==1) return;
	dfs2(son[cur],top);
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (v=edge[i].to,(v^fat[cur])&&(v^son[cur]))
			dfs2(v,v);
}

struct Node{
	double st,et;
	int sp,ep;
	bool x,y;
}node[2500000]; int nodetot;
struct Rec{
	double tim1; bool tim2,opt; int val;
}rec[5000000]; int rectop;
bool operator<(const Rec x,const Rec y)
{
	if (fabs(x.tim1-y.tim1)>eps) return x.tim1<y.tim1;
	if (x.tim2^y.tim2) return x.tim2<y.tim2;
	return x.opt>y.opt;
}
typedef pair<int,int> P;
#define st first
#define nd second
void work(double t,double c,int u,int v)
{
	static P A[100],B[100]; int Atot=0,Btot=0;
	while (top[u]^top[v])
	{
		if (dep[top[u]]<dep[top[v]]) B[++Btot]=(P){id[top[v]]-1,id[v]},v=fat[top[v]];
		else A[++Atot]=(P){id[top[u]]-1,id[u]},u=fat[top[u]];
	}
	if (dep[u]<dep[v]) B[++Btot]=(P){id[u],id[v]};
	else if (dep[u]>dep[v]) A[++Atot]=(P){id[v],id[u]};
	int s=(dep[u]<dep[v]?id[u]:id[v]);
	for (int i=1;i<=Atot;i++)
	{
		double tt=t+(A[i].nd-A[i].st)/c;
		node[++nodetot]=(Node){t,tt,A[i].nd,A[i].st,0,1};  //[)
		rec[++rectop]=(Rec){t,0,0,nodetot};
		rec[++rectop]=(Rec){tt,0,1,nodetot};
		t=tt;
	}
	node[++nodetot]=(Node){t,t,s,s,0,0};
	rec[++rectop]=(Rec){t,0,0,nodetot};
	rec[++rectop]=(Rec){t,1,1,nodetot};
	for (int i=Btot;i;i--)
	{
		double tt=t+(B[i].nd-B[i].st)/c;
		node[++nodetot]=(Node){t,tt,B[i].st,B[i].nd,1,0};
		rec[++rectop]=(Rec){t,1,0,nodetot};
		rec[++rectop]=(Rec){tt,1,1,nodetot};
		t=tt;
	}
}
#undef st
#undef nd
double tim;
struct Cmp{
	bool operator()(int x,int y)
	{
		double s=(node[x].ep^node[x].sp?(node[x].ep-node[x].sp)/(node[x].et-node[x].st):0),
			   t=(node[y].ep^node[y].sp?(node[y].ep-node[y].sp)/(node[y].et-node[y].st):0);
		double a=node[x].sp+s*(tim-node[x].st),
			   b=node[y].sp+t*(tim-node[y].st);
		if (fabs(a-b)>eps) return a<b;
		if (fabs(s-t)>eps) return s<t;
		return x<y;
	}
};
set<int,Cmp> st;
typedef set<int,Cmp>::iterator It;
void checkans(double &ans,int x,int y)
{
//	printf("checkans %d %d\n",x,y);
	#define k1 myk1
	#define k2 myk2
	#define b1 myb1
	#define b2 myb2
	double k1,k2,b1,b2;
	if (node[x].sp^node[x].ep) k1=(node[x].sp-node[x].ep)/(node[x].st-node[x].et),b1=node[x].sp-k1*node[x].st;
	else k1=0,b1=node[x].sp;
	if (node[y].sp^node[y].ep) k2=(node[y].sp-node[y].ep)/(node[y].st-node[y].et),b2=node[y].sp-k2*node[y].st;
	else k2=0,b2=node[y].sp;
	double a; bool b;
	if (fabs(node[x].st-node[y].st)>eps)
		if (node[x].st<node[y].st) a=node[y].st,b=node[y].x;
		else a=node[x].st,b=node[x].x;
	else a=node[x].st,b=node[x].x|node[y].x;
	double c; bool d;
	if (fabs(node[x].et-node[y].et)>eps)
		if (node[x].et<node[y].et) c=node[x].et,d=node[x].y;
		else c=node[y].et,d=node[y].y;
	else c=node[x].et,d=node[x].y|node[y].y;
	if (fabs(k1-k2)<eps)
	{
		if (fabs(b1-b2)<eps)
			if (a+eps<c||fabs(a-c)<eps&&!b&&!d)
				ans=min(ans,a/*+(b?eps:0)*/);
		return;
	}
	double e=(b2-b1)/(k1-k2);
	if ((b?a+eps<e:a<e+eps)&&(d?e+eps<c:e<c+eps)) ans=min(ans,e);
	#undef k1
	#undef k2
	#undef b1
	#undef b2
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs1(1,0,1); dfs2(1,1);
	for (int i=1,t,c,u,v;i<=m;i++)
	{
		t=read(),c=read(),u=read(),v=read();
		work(t,c,u,v);
	}
	double ans=1e18;
	sort(rec+1,rec+rectop+1);
	for (int i=1,t;i<=rectop;i++)
	{
		if (ans<rec[i].tim1+eps) break;
		if (rec[i].opt)
		{
//			printf("erase %d\n",rec[i].val);
			It x,y; x=y=st.lower_bound(rec[i].val);
			if (x!=st.begin()&&(++y)!=st.end()) checkans(ans,*--x,*y);
			st.erase(rec[i].val);
			continue;
		}
		tim=rec[i].tim1;
//		printf("insert %d\n",rec[i].val);
		It x,y,z; x=y=z=st.insert(rec[i].val).first; t=*y;
		if (x!=st.begin()) checkans(ans,*--x,t);
		if ((++z)!=st.end()) checkans(ans,t,*z);
	}
	if (ans==1e18) puts("-1");
	else printf("%.10lf\n",fabs(ans)<eps?0.0:ans);
	return 0;
}