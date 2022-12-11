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
#undef G
typedef long long ll;

int n,K;
struct Edge{
	int to,nxt;
}edge[400010];
int cnt=1,last[200010];
int fat[200010],dep[200010],siz[200010],rsiz[200010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
void dfs(int cur,int fat,int dep){
	::fat[cur]=fat; ::dep[cur]=dep; siz[cur]=1;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^fat){
			dfs(v,cur,dep+1);
			siz[cur]+=siz[v];
		}
	rsiz[cur]=siz[cur];
}
typedef pair<int,int> P;
priority_queue<P> que;
int main()
{
	n=read(),K=read();
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs(1,0,1);
	for (int i=1;i<=n;i++) if (siz[i]==1) que.push((P){dep[i]-1,i});
	ll ans=0;
	for (int i=1;i<=K;i++){
		P cur=que.top(); que.pop();
		ans+=cur.first; int u=cur.second;
		if (u^1){
			siz[fat[u]]-=rsiz[u];
			if (siz[fat[u]]==1) que.push((P){-rsiz[fat[u]]+1+dep[fat[u]]-1,fat[u]});
		}
	}
	printf("%I64d\n",ans);
	return 0;
}