#include<cstdio>
#include<algorithm>
#include<cctype>
#include<set>
#include<map>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}

int n,m,ctot,q;
int fat[100010];
int find(int x)
{
	return fat[x]?fat[x]=find(fat[x]):x;
}
set<int> st[100010];
typedef pair<int,int> P;
map<P,int> mp;
void mrg(int x,int y)
{
	if (x==y) return;
	if (st[x].size()>st[y].size()) swap(x,y);   //x->y
	for (set<int>::iterator i=st[x].begin();i!=st[x].end();++i) st[y].insert(*i);
	st[x].clear(); fat[x]=y;
}
void addedge(int x,int y,int w)
{
	st[find(x)].insert(y);
	if (!mp.count((P){x,w})) mp[(P){x,w}]=y;
	else mrg(find(y),find(mp[(P){x,w}]));
}
int main()
{
	int x,y,z,fx,fy; char opt[3];
	n=read(),m=read(),ctot=read(),q=read();
	while (m--)    //m--
	{
		x=read(),y=read(),z=read();
		addedge(x,y,z);
//	for (int i=1;i<=n;i++) printf("%d ",find(i)); puts("");
		addedge(y,x,z);
//	for (int i=1;i<=n;i++) printf("%d ",find(i)); puts("");
	}
	while (q--)
	{
		scanf("%s",opt); x=read(),y=read();
		if (opt[0]=='+') z=read(),addedge(x,y,z),addedge(y,x,z);
		else
		{
			fx=find(x),fy=find(y);
			if (fx==fy||st[fx].count(y)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}