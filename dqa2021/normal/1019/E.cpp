#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
const double eps=1e-8;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}
typedef long long ll;
void print(ll x)
{
	if (x>9) print(x/10); putchar(x%10+48);
}

int n,m;
struct Edge{
	int to,nxt,a,b;
}edge[200010];
int cnt,last[100010];
inline void addedge(int x,int y,int a,int b)
{
	edge[++cnt]=(Edge){y,last[x],a,b},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],a,b},last[y]=cnt;
}
namespace E
{
	struct Edge{
		int to,nxt,x,y;
	}edge[400010];
	int cnt=1,last[200010],idtot;  //idtot=n
	inline void addedge(int x,int y,int a,int b)
	{
//		printf("E::addedge %d %d %d %d\n",x,y,a,b);
		edge[++cnt]=(Edge){y,last[x],a,b},last[x]=cnt;
		edge[++cnt]=(Edge){x,last[y],a,b},last[y]=cnt;
	}
	void dfs(int cur,int fat)  //:: and E::
	{
		for (int i=::last[cur],lst=cur;i;i=::edge[i].nxt)
			if (::edge[i].to!=fat)
			{
				idtot++; addedge(idtot,lst,0,0); addedge(idtot,::edge[i].to,::edge[i].a,::edge[i].b); lst=idtot;
				dfs(::edge[i].to,cur);
			}
	}
	bool mrk[200010];
	int siz[200010];
	void getsiz(int cur,int fat)
	{
		siz[cur]=1;
		for (int i=last[cur];i;i=edge[i].nxt)
			if (!mrk[i>>1]&&edge[i].to!=fat)
			{
				getsiz(edge[i].to,cur); siz[cur]+=siz[edge[i].to];
			}
	}
	int Rt,RtSiz,Siz;
	void getroot(int cur,int fat)
	{
		for (int i=last[cur];i;i=edge[i].nxt)
			if (!mrk[i>>1]&&edge[i].to!=fat)
			{
				getroot(edge[i].to,cur);
				if (Rt==-1||RtSiz>max(siz[edge[i].to],Siz-siz[edge[i].to])) Rt=(i>>1),RtSiz=max(siz[edge[i].to],Siz-siz[edge[i].to]);
			}
	}
	struct Node{
		ll x,y;
	}recl[100010],recr[100010],stk[3100010];
	int stktop;
	int totl,totr;  //init
	bool operator<(const Node x,const Node y)
	{
		if (x.x!=y.x) return x.x<y.x; return x.y<y.y;
	}
	bool operator==(const Node x,const Node y)
	{
		return x.x==y.x&&x.y==y.y;
	}
	double slope(Node x,Node y)
	{
		if (x.x!=y.x) return (double)(x.y-y.y)/(x.x-y.x);
		if (x.y<y.y) return /*puts("test"),*/1e100; return -1e100;    //+-1e100
	}
	void dfs1(int cur,int fat,ll x,ll y)
	{
//		printf("dfs1 %d %d %lld %lld\n",cur,fat,x,y);
		if (cur<=n) recl[++totl]=(Node){x,y};
		for (int i=last[cur];i;i=edge[i].nxt)
			if (!mrk[i>>1]&&edge[i].to!=fat)
				/*printf("from %d to %d  %d %d  %lld %lld  %lld %lld\n",cur,edge[i].to,edge[i].x,edge[i].y,x,y,(x+edge[i].x),(y+edge[i].y)),*/
				dfs1(edge[i].to,cur,x+edge[i].x,y+edge[i].y);
	}
	void dfs2(int cur,int fat,ll x,ll y)
	{
		if (cur<=n) recr[++totr]=(Node){x,y};
		for (int i=last[cur];i;i=edge[i].nxt)
			if (!mrk[i>>1]&&edge[i].to!=fat)
				dfs2(edge[i].to,cur,x+edge[i].x,y+edge[i].y);
	}
	int stk1[100010],stk2[100010];
	void solve(int cur)
	{
		getsiz(cur,0);
		if (siz[cur]==1) return;
		Siz=siz[cur],Rt=-1; getroot(cur,0);
		mrk[Rt]=true; totl=totr=0;
		dfs1(edge[Rt<<1].to,0,0,0); dfs2(edge[Rt<<1|1].to,0,0,0);
		if (!totl||!totr)  //caution no contribution !!
		{
			int tmp=Rt; solve(edge[tmp<<1].to); solve(edge[tmp<<1|1].to); return;
		}
		sort(recl+1,recl+totl+1); sort(recr+1,recr+totr+1);
//		printf("solve %d-%d\n",edge[Rt<<1].to,edge[Rt<<1|1].to);
//		for (int i=1;i<=totl;i++) printf("%lld %lld  ",recl[i].x,recl[i].y); puts("");
//		for (int i=1;i<=totr;i++) printf("%lld %lld  ",recr[i].x,recr[i].y); puts("");
		int tmp=0;
		for (int i=1;i<=totl;i++)
			if (i==1||!(recl[i]==recl[i-1])) recl[++tmp]=recl[i];
		totl=tmp;
		tmp=0;
		for (int i=1;i<=totr;i++)
			if (i==1||!(recr[i]==recr[i-1])) recr[++tmp]=recr[i];
		totr=tmp;
		(*stk1)=(*stk2)=0;  //stk1 stk2  and  stk
		for (int i=1;i<=totl;i++)
		{
			while ((*stk1)>1&&slope(recl[stk1[(*stk1)-1]],recl[stk1[*stk1]])<slope(recl[stk1[*stk1]],recl[i])+eps) (*stk1)--;
			stk1[++*stk1]=i;
		}
		for (int i=1;i<=totr;i++)
		{
			while ((*stk2)>1&&slope(recr[stk2[(*stk2)-1]],recr[stk2[*stk2]])<slope(recr[stk2[*stk2]],recr[i])+eps) (*stk2)--;
			stk2[++*stk2]=i;
		}
		int hd1=1,hd2=1;
		stk[++stktop]=(Node){recl[stk1[hd1]].x+recr[stk2[hd2]].x+edge[Rt<<1].x,recl[stk1[hd1]].y+recr[stk2[hd2]].y+edge[Rt<<1].y};
		while (hd1<(*stk1)||hd2<(*stk2))    //(*stk1) and totl
		{
			if (hd1==(*stk1)) hd2++;
			else if (hd2==(*stk2)) hd1++;
			else
			{
				if (slope((Node){recl[stk1[hd1]].x+recr[stk2[hd2]].x,recl[stk1[hd1]].y+recr[stk2[hd2]].y},(Node){recl[stk1[hd1+1]].x+recr[stk2[hd2]].x,recl[stk1[hd1+1]].y+recr[stk2[hd2]].y})+eps<
					slope((Node){recl[stk1[hd1]].x+recr[stk2[hd2]].x,recl[stk1[hd1]].y+recr[stk2[hd2]].y},(Node){recl[stk1[hd1]].x+recr[stk2[hd2+1]].x,recl[stk1[hd1]].y+recr[stk2[hd2+1]].y}))
					hd2++;
				else hd1++;
			}
			stk[++stktop]=(Node){recl[stk1[hd1]].x+recr[stk2[hd2]].x+edge[Rt<<1].x,recl[stk1[hd1]].y+recr[stk2[hd2]].y+edge[Rt<<1].y};
		}
		tmp=Rt; solve(edge[tmp<<1].to); solve(edge[tmp<<1|1].to);
	}
	void work()
	{
		sort(stk+1,stk+stktop+1);
		int tmp=0;
		for (int i=1;i<=stktop;i++) if (i==1||!(stk[i]==stk[i-1])) stk[++tmp]=stk[i];
		stktop=0;
		for (int i=1;i<=tmp;i++)
		{
			while (stktop>1&&slope(stk[stktop-1],stk[stktop])<slope(stk[stktop],stk[i])+eps) stktop--;
			stk[++stktop]=stk[i];
		}
		int pos=1;
		for (int i=0;i<m;i++)
		{
			while (pos<stktop&&stk[pos+1].x*i+stk[pos+1].y>stk[pos].x*i+stk[pos].y) pos++;
			printf("%lld ",stk[pos].x*i+stk[pos].y);
// 			print(stk[pos].x*i+stk[pos].y); putchar(' ');
		}
		puts("");
	}
}

int main()
{
	read(n);read(m);
	if (n==1)
	{
		while (m--) printf("0 "); puts("");
		return 0;
	}
	E::idtot=n;
	for (int i=2,x,y,a,b;i<=n;i++)
	{
		read(x);read(y);read(a);read(b);
		addedge(x,y,a,b);
	}
	E::dfs(1,0); E::solve(1);
	E::work();
	return 0;
}