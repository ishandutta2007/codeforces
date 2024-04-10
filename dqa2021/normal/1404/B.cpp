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
#undef G

int n,S,T,A,B;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int dep[100010];
void dfs(int x,int f,int d){
	dep[x]=d;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f){
			dfs(v,x,d+1);
		}
}
int find(){
	int res=1;
	for (int i=2;i<=n;i++) if (dep[i]>dep[res]) res=i;
	return res;
}
void init(){
	cnt=1; memset(last+1,0,n<<2);
}
void solve(){
	n=read(),S=read(),T=read(),A=read(),B=read();
	for (int i=1;i<n;i++) addedge(read(),read());
	if (B<=A+A) return puts("Alice"),void();
	dfs(S,0,0); if (dep[T]<=A) return puts("Alice"),void();
	dfs(1,0,0); dfs(find(),0,0);
	puts(dep[find()]>A+A?"Bob":"Alice");
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}