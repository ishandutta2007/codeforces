#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}

int n; int ans;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt=1,last[100010],deg[100010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
	deg[x]++,deg[y]++;
}
struct Rec{
	int u,t;
}rec[1000010]; int top;
void dfs(int x,int f,int t){
	rec[++top]=(Rec){x,t};
	int l=t-1,r=t;
	while (r<ans&&r-l+1<=deg[x]) r++;
	while (l>0&&r-l+1<=deg[x]) l--;
	//r-l>deg[x]
	int p=t; if (p==r) rec[++top]=(Rec){x,l},p=l;
	for (int i=last[x],v;i;i=edge[i].nxt){
		if ((v=edge[i].to)==f) continue;
		dfs(v,x,++p);
		rec[++top]=(Rec){x,p};
		if (p==r) rec[++top]=(Rec){x,l},p=l;
	}
}
int main()
{
	n=read(); for (int i=1;i<n;i++) addedge(read(),read());
	for (int i=1;i<=n;i++) ans=max(ans,deg[i]);
	rec[++top]=(Rec){1,0}; int tot=0;
	for (int i=last[1],v;i;i=edge[i].nxt){
		v=edge[i].to;
		dfs(v,1,++tot);
		rec[++top]=(Rec){1,tot};
	}
	printf("%d\n",top);
	for (int i=1;i<=top;i++) printf("%d %d\n",rec[i].u,rec[i].t);
	return 0;
}