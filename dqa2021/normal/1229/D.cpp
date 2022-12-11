#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
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

int n,k; ll ans;
int p[10],ip[10],np[10];
int mp[54400]; int mptot;

struct Edge{
	int to,nxt,val;
}edge[250];
int cnt,last[130];
inline void addedge(int x,int y,int v)
{
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
}

struct Rec{
	int u,v,w;
	bool mrk;  //mrk init
}rec[250]; int rectop;

int fat[130];
int find(int x)
{
	return fat[x]?fat[x]=find(fat[x]):x;
}

int getid(int *p)
{
	int id=0;
	for (int i=k,j=1;i;i--,j*=10) id+=p[i]*j;
	return id;
}

void dfs(int cur,int fat,int tot)
{
	ans+=tot;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to^fat)
			dfs(edge[i].to,cur,min(tot,edge[i].val));
}
int main()
{
	n=read(),k=read();
	for (int i=1;i<=k;i++) p[i]=i;
	do
	{
		//int id=0;
		//for (int i=k,j=1;i;i--,j*=10) id+=p[i]*j;
		mp[getid(p)]=++mptot;
		//printf("find %d\n",id);
	} while (next_permutation(p+1,p+k+1));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k;j++) ip[j]=read();
		for (int j=1;j<=k;j++) p[j]=j;
		do
		{
			for (int j=1;j<=k;j++) np[j]=p[ip[j]];
			rec[++rectop]=(Rec){mp[getid(p)],mp[getid(np)],i,false};
		} while (next_permutation(p+1,p+k+1));
		cnt=0; memset(last,0,sizeof last);
		memset(fat,0,sizeof fat);
		for (int j=rectop,x,y;j;j--)
			if (x=find(rec[j].u),y=find(rec[j].v),x^y)
			{
				fat[y]=x;
				addedge(rec[j].u,rec[j].v,rec[j].w);
				rec[j].mrk=true;
			}
		dfs(1,0,i);
		int tmp=0;
		for (int j=1;j<=rectop;j++)
			if (rec[j].mrk)
				rec[++tmp]=(Rec){rec[j].u,rec[j].v,rec[j].w,false};
		rectop=tmp;
	}
	printf("%I64d\n",ans);  //I64d !!!
	return 0;
}