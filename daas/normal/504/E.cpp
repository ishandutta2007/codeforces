#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
const int mod1=1e9+7;
const int mod2=1e9+9;
const int base1=151;
const int binv1=483443712;
const int base2=131;
const int binv2=526717562;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,head[300010],tot,sum[300010][2],inv[300010][2],Hash[300010][2],FHash[300010][2];
int deep[300010],st[600001][22],tim,id[300001],jump[300010][20];
int len[300010],top[300010],son[300010],Rank[300010];
vector<int> Q[300010][2];
char s[300010];
struct sb
{
	int to,nextn;
}a[600010];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void format(int u,int fa)
{
	Hash[u][0]=(1ll*Hash[fa][0]*base1%mod1+(s[u]-'a'))%mod1;
	Hash[u][1]=(1ll*Hash[fa][1]*base2%mod2+(s[u]-'a'))%mod2;
	FHash[u][0]=(1ll*sum[deep[fa]][0]*(s[u]-'a')+FHash[fa][0])%mod1;
	FHash[u][1]=(1ll*sum[deep[fa]][1]*(s[u]-'a')+FHash[fa][1])%mod2;
	deep[u]=deep[fa]+1;
	int LOG=log2(deep[u]);
	jump[u][0]=fa;
	for(int i=1;i<=LOG;++i)
		jump[u][i]=jump[jump[u][i-1]][i-1];
	st[++tim][0]=u;
	id[u]=tim;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		format(v,u);
		st[++tim][0]=u;
		if(len[v]>len[son[u]])
			son[u]=v;
		len[u]=max(len[u],len[v]);
	}
	++len[u];
}
void fun(int u,int toop)
{
	top[u]=toop;
	if(u==toop)
	{
		int fb=u;
		while(fb && Q[toop][1].size()<len[u])
			Q[toop][1].push_back(fb),fb=jump[fb][0];
	}
	Q[toop][0].push_back(u);
	Rank[u]=Q[toop][0].size();
	if(!son[u])
		return;
	fun(son[u],toop);
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==jump[u][0] || v==son[u])
			continue;
		fun(v,v);
	}
}
int LCA(int x,int y)
{
	int l=id[x],r=id[y];
	if(l>r)
		swap(l,r);
	//cout<<"LC AK IOI "<<l<<" "<<r<<endl;
	int LOG=log2(r-l+1);
	if(deep[st[r][LOG]]<deep[st[l+(1<<LOG)-1][LOG]])
		return st[r][LOG];
	else
		return st[l+(1<<LOG)-1][LOG];
}
int get(int id,int K)
{
	if(!K)
		return id;
	if(K==deep[id])
		return 0;
	int LOG=log2(K),bck=top[jump[id][LOG]];
	if(deep[id]-deep[bck]>=K)
		return Q[bck][0][deep[id]-deep[bck]-K];
	else
		return Q[bck][1][K-deep[id]+deep[bck]];
}
int calc1(int l,int r,int lca,int len)
{
	//cout<<l<<" "<<r<<" "<<lca<<" "<<len<<endl;
	//cout<<"WRP AK IOI "<<deep[l]-deep[lca]+1<<endl;
	if(len<=deep[l]-deep[lca]+1)
	{
		//cout<<"type1\n";
		int id=get(l,len);
		//cout<<id<<endl;
		return (Hash[l][0]-1ll*Hash[id][0]*sum[deep[l]-deep[id]][0]%mod1+mod1)%mod1;
	}
	else
	{
		//cout<<"type2\n";
		int v1=(Hash[l][0]-1ll*Hash[jump[lca][0]][0]*sum[deep[l]-deep[lca]+1][0]%mod1+mod1)%mod1;
		len-=deep[l]-deep[lca]+1;
		int id=get(r,deep[r]-deep[lca]-len);
		//cout<<id<<endl;
		int v2=(FHash[id][0]-FHash[lca][0]+mod1)%mod1;
		if(deep[lca]>=deep[l]-deep[lca]+1)
			return (v1+1ll*v2*inv[2*deep[lca]-deep[l]-1][0]%mod1)%mod1;
		else
			return (v1+1ll*v2*sum[deep[l]-2*deep[lca]+1][0]%mod1)%mod1;
	}
}
int calc2(int l,int r,int lca,int len)
{
	if(len<=deep[l]-deep[lca]+1)
	{
		int id=get(l,len);
		return (Hash[l][1]-1ll*Hash[id][1]*sum[deep[l]-deep[id]][1]%mod2+mod2)%mod2;
	}
	else
	{
		int v1=(Hash[l][1]-1ll*Hash[jump[lca][0]][1]*sum[deep[l]-deep[lca]+1][1]%mod2+mod2)%mod2;
		len-=deep[l]-deep[lca]+1;
		int id=get(r,deep[r]-deep[lca]-len);
		int v2=(FHash[id][1]-FHash[lca][1]+mod2)%mod2;
		if(deep[lca]>=deep[l]-deep[lca]+1)
			return (v1+1ll*v2*inv[2*deep[lca]-deep[l]-1][1]%mod2)%mod2;
		else
			return (v1+1ll*v2*sum[deep[l]-2*deep[lca]+1][1]%mod2)%mod2;
	}
}
int main()
{
	n=read();
	sum[0][0]=sum[0][1]=inv[0][0]=inv[0][1]=1;
	for(int i=1;i<=n;++i)
	{
		sum[i][0]=1ll*base1*sum[i-1][0]%mod1;
		inv[i][0]=1ll*binv1*inv[i-1][0]%mod1;
		sum[i][1]=1ll*base2*sum[i-1][1]%mod2;
		inv[i][1]=1ll*binv2*inv[i-1][1]%mod2;
	}
	scanf("%s",s+1);
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
	}
	format(1,0);
	fun(1,1);
	for(int i=1;i<=tim;++i)
	{
		int LOG=log2(i);
		for(int j=1;j<=LOG;++j)
			if(deep[st[i][j-1]]<deep[st[i-(1<<j-1)][j-1]])
				st[i][j]=st[i][j-1];
			else
				st[i][j]=st[i-(1<<j-1)][j-1];
	}
	m=read();
	for(int i=1;i<=m;++i)
	{
		int l1=read(),r1=read(),l2=read(),r2=read();
		int lca1=LCA(l1,r1),lca2=LCA(l2,r2);
		int l=1,r=min(deep[l1]+deep[r1]-2*deep[lca1],deep[l2]+deep[r2]-2*deep[lca2])+1,ans=0;
		//cout<<l1<<" "<<r1<<" "<<lca1<<" "<<l2<<" "<<r2<<" "<<lca2<<" "<<l<<" "<<r<<endl;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(calc1(l1,r1,lca1,mid)==calc1(l2,r2,lca2,mid) && calc2(l1,r1,lca1,mid)==calc2(l2,r2,lca2,mid))
				ans=mid,l=mid+1;
			else
				r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}