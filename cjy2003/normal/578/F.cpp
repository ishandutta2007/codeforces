#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,mod,f[11000],dy[11000],cnt1,cnt2,a1[210][210],a2[210][210],ans;
char s[110][110];
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
inline int id(int x,int y){return x*(m+1)+y;}
int find(int x)
{
	if(x!=f[x])return f[x]=find(f[x]);
	return x;
}
inline bool merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return 0;
	f[x]=y;
	return 1;
}
inline void add1(int x,int y)
{
//	printf("%d %d\n",x,y);
	x=dy[find(x)],y=dy[find(y)];
//	printf("%d %d\n",x,y);
	--a1[x][y],--a1[y][x];
	++a1[x][x],++a1[y][y];
}
inline void add2(int x,int y)
{
	x=dy[find(x)],y=dy[find(y)];
	--a2[x][y],--a2[y][x];
	++a2[x][x],++a2[y][y];	
}
void work(int a[210][210],int cnt)
{
/*	for(int i=1;i<cnt;++i)
	{
		for(int j=1;j<cnt;++j)printf("%d ",a[i][j]);
		printf("\n");
	}*/
	bool fl=0;
	for(int i=1;i<cnt;++i)
	{
		for(int j=i;j<cnt;++j)
			if(a[j][i])
			{
				if(j!=i)swap(a[i],a[j]),fl^=1;
				break;
			}
		int inv=kpow(a[i][i],mod-2);
		for(int j=i+1;j<cnt;++j)
		{
			int c=1ll*inv*a[j][i]%mod;
			for(int k=i;k<cnt;++k)a[j][k]=(a[j][k]+1ll*(mod-c)*a[i][k])%mod;
		}
	}
	int res=1;
	for(int i=1;i<cnt;++i)res=1ll*res*a[i][i]%mod;
	if(fl)res=-res;
	res<0?res+=mod:0;
//	printf("%d\n",res);
	(ans+=res)>=mod?ans-=mod:0;
}
int main()
{
	scanf("%d %d %d",&n,&m,&mod);
	for(int i=0;i<(n+1)*(m+1);++i)f[i]=i;			
	for(int i=1;i<=n;++i)
	{
		scanf(" %s",s[i]+1);
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]==47&&!merge(id(i,j-1),id(i-1,j)))return printf("0"),0;
			if(s[i][j]==92&&!merge(id(i-1,j-1),id(i,j)))return printf("0"),0;
		}
	}
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			if(find(id(i,j))==id(i,j))dy[id(i,j)]=(i+j)&1?cnt1++:cnt2++;
	if(cnt1<=201)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(s[i][j]=='*')
				{
					if((i+j)&1)add1(id(i-1,j-1),id(i,j));
					else add1(id(i,j-1),id(i-1,j));
				}
		work(a1,cnt1);
	}
	if(cnt2<=201)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(s[i][j]=='*')
				{
					if((i+j)&1)add2(id(i,j-1),id(i-1,j));
					else add2(id(i-1,j-1),id(i,j));
				}
		work(a2,cnt2);
	}
	printf("%d",ans);
	return 0;
}