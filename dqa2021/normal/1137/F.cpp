#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}

int n,q; int tim;
int tri[400010];
void add(int x,int val)
{
	//printf("add %d %d\n",x,val);
	for (;x<=n+q;x+=x&-x) tri[x]+=val;   //q don't change
}
int ask(int x)
{
	int res=0;
	for (;x;x-=x&-x) res+=tri[x];
	return res;
}
struct Node{
	Node *ch[2],*f;
	bool rev;
	int col,siz;  //set at root
	bool isroot()
	{
		return f->ch[0]!=this&&f->ch[1]!=this;
	}
	bool which()
	{
		return this==f->ch[1];
	}
	void pushdown()
	{
		if (!rev) return; rev=false;
		swap(ch[0],ch[1]);
		ch[0]->rev^=1; ch[1]->rev^=1;
	}
	void pushup()
	{
		siz=ch[0]->siz+1+ch[1]->siz;   //null->siz=0  //remember to pushup
	}
	void rotate()
	{
		bool tmp=which()^1;
		Node *y=f;
		f=y->f; if (!y->isroot()) f->ch[y->which()]=this;
		y->ch[tmp^1]=ch[tmp]; ch[tmp]->f=y;  //null->f changed
		y->f=this; ch[tmp]=y;
		swap(col,y->col);
		y->pushup(); pushup();
	}
	void flash()
	{
		if (!isroot()) f->flash(); pushdown();
	}
	void splay()
	{
		flash();
		while (!isroot())
			if (f->isroot()) rotate();
			else if (which()^f->which()) rotate(),rotate();
			else f->rotate(),rotate();
	}
	
	Node* access(Node*);
	void makeroot();
	int query();
}node[200010],*null;  //init of null
Node* Node::access(Node *lst=null)
{
	splay(); pushdown();
	ch[1]->col=col;  //caution col upd
	ch[1]=null; pushup();
	add(col,-siz); add(tim,siz);
	ch[1]=lst; pushup();
	if (f!=null) return f->access(this); return this;
}
void Node::makeroot()
{
	tim++; access(); splay(); rev^=1; col=tim;
}
int Node::query()
{
	splay(); pushdown();
	
	//printf("%d %d\n",ch[1]->siz,ask(col-1));
	//printf("col %d\n",col);
	//printf("query %d: %d\n",(int)(this-node),ch[1]->siz+ask(col-1)+1);
	
	return ch[1]->siz+ask(col-1)+1;
}

struct Edge{
	int to,nxt;
}edge[400010];
int cnt=1,last[200010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int fat[200010],chtot[200010];
priority_queue<int,vector<int>,greater<int> > que;
void dfs(int cur,int fat)
{
	::fat[cur]=fat; if (fat) chtot[fat]++;
	node[cur]=(Node){{null,null},(fat?node+fat:null),false,0,1};
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to^fat)
			dfs(edge[i].to,cur);
	if (!chtot[cur]) que.push(cur);
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	null=new Node(); *null=(Node){{null,null},null,false,0,0};

	n=tim=read(),q=read();
	for (int i=1;i<=n+q;i++)
	{
		int l=i-(i&-i)+1,r=i;
		if (l<=n) tri[i]=min(r,n)-l+1;
	}
	//for (int i=1;i<=n;i++) add(i,1);
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs(n,0);
	for (int i=1;i<=n;i++)
	{
		int u=que.top(); que.pop();
		node[u].col=i;
		//printf("col %d is %d\n",u,i);
		if (fat[u])
		{
			chtot[fat[u]]--;
			if (!chtot[fat[u]]) que.push(fat[u]);
		}
	}
	
	char opt[20]; int x,y;
	//while (q--)
	for (int i=1;i<=q;i++)
	{
		scanf("%s",opt); x=read();
		if (opt[0]=='u')
		{
			node[x].makeroot();
			continue;
		}
		if (opt[0]=='w')
		{
			printf("%d\n",node[x].query());
			continue;
		}
		y=read();
		printf("%d\n",node[x].query()<node[y].query()?x:y);
	}
	return 0;
}