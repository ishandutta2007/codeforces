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
const int MAXN=1e5+1;
const int SQRN=318;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,N,q,Type,base,zone[MAXN],a[MAXN],tim,num[MAXN],top,sum[SQRN][MAXN],ans,can[SQRN][SQRN][SQRN];
vector<int> col[MAXN];
int calc(int l,int r,int K)
{
	if(!K) return r-l+1;
	int bck=0,lid=(l-1)/base+1,rid=(r-1)/base+1;
	//dragon is forever god
	if(lid==rid)
	{
		for(int i=l;i<=r;++i) if(zone[i]>=K && col[a[i]][zone[i]-K]>=l) ++bck;
		return bck;
	}
	for(int i=lid+1;i<rid;++i) bck+=can[K][i][lid+1];
	for(int i=l;i<=lid*base;++i) if(zone[i]+K<col[a[i]].size() && col[a[i]][zone[i]+K]<=(rid-1)*base) ++bck;
	for(int i=(rid-1)*base+1;i<=r;++i) if(zone[i]>=K && col[a[i]][zone[i]-K]>=l) ++bck;
	return bck;
}
int head[MAXN],tot,dfn[MAXN],size[MAXN],V[MAXN];
struct node
{
	int to,nextn;
}A[MAXN*2];
void ADD(int from,int to)
{
	A[++tot].to=to,A[tot].nextn=head[from];
	head[from]=tot;
}
void format(int u,int fa)
{
	++tim;
	a[tim]=num[tim]=V[u];
	dfn[u]=tim;
	size[u]=1;
	for(int i=head[u];i!=0;i=A[i].nextn)
	{
		int v=A[i].to;
		if(v==fa) continue;
		format(v,u);
		size[u]+=size[v];
	}
}
int main()
{
	n=read(),q=read();
	for(int i=1;i<=n;++i) V[i]=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
	}
	format(1,0);
	sort(num+1,num+n+1);
	m=unique(num+1,num+n+1)-num-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=lower_bound(num+1,num+m+1,a[i])-num;
		col[a[i]].push_back(i);
		zone[i]=col[a[i]].size()-1;
	}
	base=sqrt(n);
	for(int i=1;i<=m;++i) if(col[i].size()>base)
	{
		++top;
		for(int j=1;j<=n;++j) sum[top][j]=sum[top][j-1]+(a[j]==i);
	}
	N=(n-1)/base+1;
	for(int i=1;i<=base;++i)
	{
		for(int j=N;j>=1;--j)
		{
			int l=(j-1)*base+1,r=min(n,j*base);
			for(int k=l;k<=r;++k) if(zone[k]>=i)
			{
				int v=col[a[k]][zone[k]-i];
				++can[i][j][(v-1)/base+1];
			}
			for(int k=N;k>=1;--k) can[i][j][k]+=can[i][j][k+1];
		}
	}
	while(q--)
	{
		int x=read(),K=read();
		int l=dfn[x],r=dfn[x]+size[x]-1;
		if(K<=base) printf("%d\n",(calc(l,r,K-1)-calc(l,r,K)));
		else
		{
			ans=0;
			for(int i=1;i<=top;++i) if(sum[i][r]-sum[i][l-1]>=K) ++ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}
//ore no turn,draw!