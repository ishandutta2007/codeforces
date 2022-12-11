#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n;
struct Edge{
	int to,nxt;
}edge[400010];
int cnt=1,last[200010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int siz[2][200010];
void dfs(int x,int f,int d){
	siz[d][x]=1;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f){
			dfs(v,x,d^1);
			siz[0][x]+=siz[0][v];
			siz[1][x]+=siz[1][v];
		}
}
int main()
{
	n=read();
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs(1,0,0);
	printf("%d\n",min(siz[0][1],siz[1][1])-1);
	return 0;
}