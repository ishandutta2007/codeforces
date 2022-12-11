#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int x,y,w,id;
	bian(int xx=0,int yy=0,int ww=0,int ii=0){x=xx,y=yy,w=ww,id=ii;}
	friend bool operator < (bian a,bian b)
	{
		return a.w<b.w;
	}
}b[100010],s[5010],now;
int n,m,k,bn,sn,ans=0x7fffffff,f[5050],t[5050];
int find(int x)
{
	if(x!=f[x])return f[x]=find(f[x]);
	return x;
}
bool check(int ad)
{
	int p1=1,p2=1,cnt=0,fg;
	for(int i=1;i<=n;++i)f[i]=i;
	while(p1<=bn||p2<=sn)
	{
		if(b[p1].w<=s[p2].w+ad)now=b[p1],++p1,fg=0;
		else now=s[p2],++p2,fg=1;
		if(find(now.x)!=find(now.y))f[f[now.x]]=f[now.y],cnt+=fg;
	}
	return cnt>=k;
}
void getans(int ad)
{
	int p1=1,p2=1,cnt=0,tot=0,fg;
	for(int i=1;i<=n;++i)f[i]=i;
	while(p1<=bn||p2<=sn)
	{
		if(b[p1].w<=s[p2].w+ad)now=b[p1],++p1,fg=0;
		else now=s[p2],++p2,fg=1;
		if(fg&&cnt==k)continue;
		if(find(now.x)!=find(now.y))
		{
			t[++tot]=now.id;
			f[f[now.x]]=f[now.y];
			cnt+=fg;
		}
	}
	if(cnt<k||tot<n-1)
	{
		printf("-1");
		exit(0);
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	int x,y,w;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		if(x>y)swap(x,y);
		if(x==1)s[++sn]=bian(x,y,w,i);
		else b[++bn]=bian(x,y,w,i);
	}
	sort(s+1,s+1+sn);
	sort(b+1,b+1+bn);
	s[sn+1].w=0x3f3f3f3f;
	b[bn+1].w=0x3f3f3f3f;
	int l=-1e5-10,r=1e5+10,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	//	printf("%d %d\n",mid,ans);
	}
	if(ans==0x7fffffff)
	{
		printf("-1");
		return 0;
	}
	getans(ans);
	printf("%d\n",n-1);
	for(int i=1;i<n;++i)
		printf("%d ",t[i]);
	return 0;
}