#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
	int x,y;
	friend point operator - (point a,point b){return point{a.x-b.x,a.y-b.y};}
	friend long long operator ^ (point a,point b){return 1ll*a.x*b.y-1ll*a.y*b.x;}
	friend long long operator * (point a,point b){return 1ll*a.x*b.x+1ll*a.y*b.y;}
}a[10],m[1010];
int k,n,mp[1010][8][8],p[10];
int tm,vis[1010],cnt,ans;
bool ok[1010],used[10];
bool in(point a,point b,point c)
{
	return ((b-a)^(c-a))==0&&(b-a)*(c-a)<0;
}
bool dfs(int x)
{
	++cnt;
	if(cnt>k||mp[x][p[cnt]][0]>k)return 0;
	int now=p[cnt];
	for(int i=1;i<=mp[x][now][0];++i)
		if(vis[mp[x][now][i]]!=tm&&!dfs(mp[x][now][i]))return 0;
	vis[x]=tm;
	return 1;
}
void calcp(int w)
{
	if(w==k+1)
	{
		for(int i=1;i<=n;++i)if(!ok[i])cnt=0,++tm,ok[i]=dfs(i)/*,ok[i]?printf("%d %d %d\n",p[1],p[2],i):0*/;
		return ;
	}
	for(int i=1;i<=k;++i)
		if(!used[i])
		{
			used[i]=1;p[w]=i;
			calcp(w+1);
			used[i]=0;
		}
}
int main()
{
	scanf("%d %d",&k,&n);
	for(int i=1;i<=k;++i)scanf("%d %d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;++i)scanf("%d %d",&m[i].x,&m[i].y);
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
			for(int l=1;l<=n;++l)
				if(l!=j&&in(m[l],m[j],a[i]))
				{
				//	printf("%d %d %d\n",l,j,i);
					if(mp[j][i][0]<k-1)mp[j][i][++mp[j][i][0]]=l;
					else mp[j][i][0]=100;
				}
	calcp(1);
	for(int i=1;i<=n;++i)if(ok[i])++ans;
	printf("%d",ans);
	return 0;
}