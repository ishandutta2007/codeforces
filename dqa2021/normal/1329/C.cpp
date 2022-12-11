#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
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
typedef long long ll;

int n,m,w[1<<20]; ll sum;
int dep[1<<20],maxdep[1<<20];
typedef pair<int,int> P;
priority_queue<P> que;
int ans[1048600],anstot;
#define ls (cur<<1)
#define rs (cur<<1|1)
void update(int cur){
//	del.push((P){w[cur],cur});
	if (maxdep[cur]==dep[cur]) return w[cur]=0,void();
	int son=w[ls]>w[rs]?ls:rs;
	w[cur]=w[son]; update(son);
	if (!w[ls]&&!w[rs]) maxdep[cur]=dep[cur];
	else maxdep[cur]=w[ls]<w[rs]?maxdep[rs]:maxdep[ls];
//	if (maxdep[cur]>m) que.push((P){w[cur],cur});
}
void dfs(int cur){
	if (!w[cur]) return;
	if (maxdep[cur]>m) return que.push((P){w[cur],cur}),void();
	dfs(ls); dfs(rs);
}
void init(){
}
void solve()
{
	n=read(),m=read(); sum=0; anstot=0;
	for (int i=1;i<(1<<n);i++) w[i]=read(),sum+=w[i],maxdep[i]=n; que.push((P){w[1],1});
	int tot=(1<<n)-(1<<m);
	while (tot--){
//		while (!del.empty()&&del.top()==que.top()) que.pop(),del.pop();
		P cur=que.top(); que.pop();
//		printf("get %d %d\n",cur.first,cur.second);
		ans[++anstot]=cur.second;
		sum-=cur.first; update(cur.second); dfs(cur.second);
	}
	printf("%I64d\n",sum);
	for (int i=1;i<=anstot;i++) printf("%d ",ans[i]); puts("");
	for (int i=1;i<(1<<n);i++) w[i]=0;
//	while (!del.empty()) del.pop();
	while (!que.empty()) que.pop();
}
int main()
{
	dep[1]=1; for (int i=2;i<(1<<20);i++) dep[i]=dep[i>>1]+1;
	for (int T=read();T--;) init(),solve();
	return 0;
}