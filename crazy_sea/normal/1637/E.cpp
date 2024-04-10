#pragma GCC optimize(2)
#pragma GCC optimize("inline")
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<queue>
#define N 300010
using namespace std;
struct node{
	int val,a,b;
	bool operator <(const node&a) const
	{
		return val<a.val;
	}
};
priority_queue<node>q;
vector<int>v[N];
unordered_map<long long,bool>pp,p2;
const long long K=1e9+1;
bool chk(int a,int b)
{
	if(a==b) return 0;
	if(a>b) swap(a,b);
	if(pp[a*K+b]) return 0;
	else return 1;
}
void push(node x)
{
	int a=x.a,b=x.b;
	if(p2[a*K+b]) return;
	p2[a*K+b]=1;
	q.push(x);
}
long long ans;
int solve(int x,int y)
{
	p2.clear();
	while(!q.empty()) q.pop();
	int a=v[x].size()-1,b=v[y].size()-1;
	push((node){v[x][a]+v[y][b],a,b});
	while(!q.empty())
	{
		node k=q.top();
		if(1ll*(x+y)*k.val<ans) return 0;
		q.pop();
		a=k.a,b=k.b;
		if(chk(v[x][a],v[y][b])) return k.val;
		if(a>0) push((node){v[x][a-1]+v[y][b],a-1,b});
		if(b>0) push((node){v[x][a]+v[y][b-1],a,b-1});
	}
	return 0;
}
int n,a[N],b[N],m,x,y,p[N],len;
unordered_map<int,int>t;
void work()
{
	scanf("%d%d",&n,&m);
	t.clear();
	pp.clear();
	len=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i],t[a[i]]++;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		pp[x*K+y]=1;
	}
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=m;i++) v[t[b[i]]].push_back(b[i]);
	for(int i=1;i<=n;i++) if(v[i].size()) p[++len]=i;
	for(int i=1;i<=len;i++)
		for(int j=i;j<=len;j++)
			ans=max(ans,1ll*solve(p[i],p[j])*(p[i]+p[j]));
	for(int i=1;i<=n;i++) v[i].clear();
	printf("%lld",ans);
	ans=0;
}
int T;
int main()
{
	scanf("%d",&T);
	while(T--) work(),printf("\n");
}