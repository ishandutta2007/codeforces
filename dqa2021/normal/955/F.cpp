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
typedef long long ll;

int n; ll ans;
struct Edge{
	int to,nxt;
}edge[600010];
int cnt=1,last[300010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int f[300010][19];
int bin[300010];
int dep[300010],maxdep[300010];
void dfs1(int cur,int fat,int dep)
{
	int chtot=0;
	::dep[cur]=maxdep[cur]=dep;
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		if (edge[i].to==fat) continue;
		dfs1(edge[i].to,cur,dep+1);
		maxdep[cur]=max(maxdep[cur],maxdep[edge[i].to]);
		chtot++;
	}
	for (int i=18;i>=2;i--)
	{
		(*bin)=0;
		for (int j=last[cur];j;j=edge[j].nxt)
			if (edge[j].to^fat)
				bin[++*bin]=f[edge[j].to][i-1];
		sort(bin+1,bin+(*bin)+1);
		int l=1,r=chtot,mid;
		if (l>r||!(bin[(*bin)-l+1]>=l)) continue;
		while (l<r)
		{
			mid=l+r+1>>1;
			if (bin[(*bin)-mid+1]>=mid) l=mid;
			else r=mid-1;
		}
		f[cur][i]=l;
	}
	f[cur][1]=n;
}
void dfs2(int cur,int fat)
{
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to^fat)
		{
			dfs2(edge[i].to,cur);
			for (int j=1;j<=18;j++)
				f[cur][j]=max(f[cur][j],f[edge[i].to][j]);
		}
		
	ans+=maxdep[cur]-dep[cur]+1;
	for (int j=18;j;j--)
	{
		if (f[cur][j]<2) continue;
		if (j==18||f[cur][j+1]<2) ans+=1LL*j*(f[cur][j]-1);
		else ans+=1LL*j*(f[cur][j]-f[cur][j+1]);
	}
}
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("A.out","w",stdout);
    
	n=read();
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs1(1,0,1);
	dfs2(1,0);
	printf("%I64d\n",ans);  //I64d!!!
	return 0;
}