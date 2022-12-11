#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,p[200020][6],f[200020][120],jc[6]={1,1,2,6,24,120},trans[120][120],siz[200020][120];
int find(int pos,int x)
{
	if(x!=f[pos][x])return f[pos][x]=find(pos,f[pos][x]);
	return x;
}
int res;
long long ans;
int get(int a[])
{
	int res=0,cnt=0;
	for(int i=1;i<=k;++i)
	{
		cnt=a[i]-1;
		for(int j=1;j<i;++j)cnt-=a[j]<a[i];
		res+=jc[k-i]*cnt;
	}
	return res;
}
int x[6],y[6],z[6];
bool vis1[6],vis2[6];
void dfs2(int w)
{
	if(w==k+1)
	{
		for(int i=1;i<=k;++i)z[y[i]]=x[i];
		trans[get(x)][get(y)]=get(z);
		return ;
	}
	for(int i=1;i<=k;++i)
		if(!vis2[i])
		{
			vis2[i]=1;y[w]=i;
			dfs2(w+1);
			vis2[i]=0;
		}	
}
void dfs1(int w)
{
	if(w==k+1)return dfs2(1),void();
	for(int i=1;i<=k;++i)
		if(!vis1[i])
		{
			vis1[i]=1;x[w]=i;
			dfs1(w+1);
			vis1[i]=0;
		}
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k;++j)
			scanf("%d",&p[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=0;j<jc[k];++j)
			siz[i][j]=1,f[i][j]=j;
	dfs1(1);
//	for(int i=0;i<jc[k];++i)
//	{
//		for(int j=0;j<jc[k];++j)
//			printf("%d ",trans[i][j]);
//		printf("\n");
//	}
	int x,y;
	for(int i=n;i;--i)
	{
		++res;
		int id=get(p[i]),nxt;
		for(int j=0;j<jc[k];++j)
		{
			nxt=trans[j][id];
			for(int l=i;l<=n;++l)
			{
				x=find(l,j),y=find(l,nxt);
				if(x!=y)
				{
					res-=siz[l][find(l,0)];
					siz[l][y]+=siz[l][x];
					f[l][x]=y;
					res+=siz[l][find(l,0)];
				}
				else break;
			}
		}
		ans+=res;
	//	printf("%d\n",res);
	}
	printf("%lld",ans);
	return 0;
}