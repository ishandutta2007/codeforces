#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
void no()
{
	printf("-1");
	exit(0);
}
struct bian{int nxt,to;}bi[400040];
int n,a[200020],b[200020],head[200020],num,c[200020],f[200020];
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
int st[200020],tp;
bool vis[200020],used[200020];
long long ans,res;
void bfs(int s,int e)
{
	static int q[200020],h,t,x,y;
	memset(vis+1,0,n);
	h=0,t=1,q[t]=e,vis[e]=1,f[e]=0;
	while(h<t)
	{
		x=q[++h];
		for(int i=head[x];i;i=bi[i].nxt)
		{
			y=bi[i].to;
			if(!vis[y])vis[y]=1,q[++t]=y,f[y]=x;
		}
	}
	x=s;tp=0;
	while(x)st[++tp]=x,x=f[x];
}
int cnt,siz[200020],dep[200020];
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;f[v]=fa;
	siz[v]=b[v]!=c[v];
	int d=0;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs(u,v);siz[v]+=siz[u];
		if(siz[u])++d;
	}
	if(d>=3||(d==2&&siz[v]!=cnt))no();
}
int pa[200020],plen;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	int x,y,z,w;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	memcpy(c+1,a+1,n<<2);
	for(int i=1;i<=n;++i)
	{
		if(c[i]==0)x=i;
		if(b[i]==0)y=i;
	}
	bfs(x,y);z=x;w=y;
//	if(a[1]==168461){for(int i=1;i<=tp;++i)printf("%d %d %d\n",st[i],a[i],b[i]);printf("\n");};
	for(int i=2;i<=tp;++i)used[st[i]]=1;res=tp-1;
	for(int i=1;i<tp;++i)c[st[i]]=c[st[i+1]];c[st[tp]]=0;
	for(int i=1;i<=n;++i)cnt+=b[i]!=c[i];
	if(!cnt)return printf("0 %d",tp-1),0;
	dfs(y,0);
	memset(vis+1,0,n);
	int p=0,q=0;
	for(int i=1;i<=n;++i)if(b[i]!=c[i]&&dep[i]>dep[p])p=i;//printf("%d\n",p);
	tp=0;x=p;
	while(b[x]!=c[x])st[++tp]=x,vis[x]=1,x=f[x];
//	if(a[1]==168461){for(int i=1;i<=tp;++i)printf("%d %d %d\n",st[i],a[i],b[i]);printf("\n");}
	for(int i=1;i<=n;++i)if(b[i]!=c[i]&&!vis[i]&&dep[i]>dep[q])q=i;//printf("%d\n",q);
	int cur=tp;y=q;
	while(b[y]!=c[y]&&!vis[y])st[++tp]=y,vis[y]=1,y=f[y];
	if(!q)q=y=x;
//	else if(a[1]==168461)printf("%d\n",x);
	if(x!=y)no();//printf("!\n");
	for(int i=1;i<=n;++i)if(b[i]!=c[i]&&!vis[i])no();
	reverse(st+cur+1,st+tp+1);
//	if(a[1]==168461){for(int i=cur+1;i<=tp;++i)printf("%d %d %d\n",st[i],a[i],b[i]);printf("\n");}
//	for(int i=1;i<=tp;++i)printf("%d ",st[i]);printf("\n");
	//printf("%d\n",x);
	int len;
	for(int i=1;i<=tp;++i)if(c[st[1]]==b[st[i]])len=i-1;
	for(int i=1;i<=tp;++i)if(c[st[i]]!=b[st[(i+len-1)%tp+1]])no();
//	if(a[1]==168461)printf("len:%d\n",len);

//	ans+=1ll*min(len,tp-len)*(tp+1);
	memcpy(pa+1,st+1,tp<<2);plen=tp;
	bfs(z,x);
//	for(int i=1;i<=tp;++i)printf("%d ",st[i]);printf("\n");
	for(int i=2;i<=tp;++i)if(!used[st[i]])res+=2;
	long long s=res;
	for(int i=tp-1,j=cur;i>0&&j>0;--i,--j)
		if(st[i]==pa[j])s-=2;
		else break;
//	printf("%d\n",s);
	ans=s+1ll*len*(plen+1);
	s=res;
	for(int i=tp-1,j=cur+1;i>0;--i,++j)
		if(st[i]==pa[j])s-=2;
		else break;
	ans=min(ans,s+1ll*(plen-len)*(plen+1));
	if(p>q)swap(p,q);
//	check(z,p,q,w);
//	check(z,q,p,w);
	printf("%d %d %lld",p,q,ans);
	return 0;
}