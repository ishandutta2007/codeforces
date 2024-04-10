#include<cstdio>
#include<algorithm>
#include<cctype>
#include<map>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;


int Q; int curtot;
map<ll,int> id; int idtot;  //for circle

int last[100010],nxt[100010],nodetot;   //stk for//caution rename
struct Node{
	int x,y;
}node[100010];
bool operator<(const Node x,const Node y)
{
	if (x.x^y.x) return x.x<y.x; return x.y<y.y;
}

int bin[100010];

map<Node,int> ans[262200];  //for symmetrical
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
void update(int x,int y,int val)
{
	int tmp=gcd(x,y); x/=tmp,y/=tmp;
	//printf("update %d %d\n",x,y);
	int pos=(x^(x<<13)^y^(y>>7))&262143;
	ans[pos][(Node){x,y}]+=val;
}
int query(int x,int y)
{
	int tmp=gcd(x,y); x/=tmp,y/=tmp;
	//printf("query %d %d\n",x,y);
	int pos=(x^(x<<13)^y^(y>>7))&262143;
	return ans[pos][(Node){x,y}];
}
int main()
{
	Q=read();
	int opt,x,y;
	while (Q--)
	{
		opt=read(),x=read(),y=read();
		if (opt==1)
		{
			curtot++;
			ll tmp=1LL*x*x+1LL*y*y;
			int tmpid;
			if (!id.count(tmp)) tmpid=id[tmp]=++idtot;
			else tmpid=id[tmp];  //id for node_group(based on circle)
			//printf("put in group %d: %lld\n",tmpid,tmp);
			//printf("nodeid %d\n",nodetot+1);
			//printf("%d %d ",nodetot+1,nodetot+1);
			update(x,y,1);
			for (int i=last[tmpid];i;i=nxt[i]) /*printf("insert %d %d ",i,nodetot+1),*/update(x+node[i].x,y+node[i].y,2);
			int nodeid=++nodetot; node[nodeid]=(Node){x,y};
			nxt[nodeid]=last[tmpid]; last[tmpid]=nodeid;
			continue;
		}
		if (opt==2)
		{
			curtot--;
			ll tmp=1LL*x*x+1LL*y*y;
			int tmpid=id[tmp];
			update(x,y,-1);
			(*bin)=0;
			for (int i=last[tmpid];i;i=nxt[i])
			{
				if (node[i].x==x&&node[i].y==y) continue;
				bin[++*bin]=i; update(x+node[i].x,y+node[i].y,-2);
			}
			last[tmpid]=0;
			for (int i=1;i<=(*bin);i++)
			{
				nxt[bin[i]]=last[tmpid]; last[tmpid]=bin[i];
			}
			continue;
		}
		printf("%d\n",curtot-query(x,y));
	}
	return 0;
}