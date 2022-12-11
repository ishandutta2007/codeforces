#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char s[500050];
int sa[500050],height[500050],rk[500050],xx[500050],yy[500050],t[500050];
void getsa()
{
	int *x=xx,*y=yy,m=200;
	for(int i=1;i<=n;++i)++t[x[i]=s[i]];
	for(int i=2;i<=m;++i)t[i]+=t[i-1];
	for(int i=n;i;--i)sa[t[x[i]]--]=i;
	memset(t+1,0,m<<2);
	for(int len=1;;len<<=1)
	{
		int tot=0;
		for(int i=n-len+1;i<=n;++i)y[++tot]=i;
		for(int i=1;i<=n;++i)if(sa[i]>len)y[++tot]=sa[i]-len;
		for(int i=1;i<=n;++i)++t[x[i]];
		for(int i=2;i<=m;++i)t[i]+=t[i-1];
		for(int i=n;i;--i)sa[t[x[y[i]]]--]=y[i];
		memset(t+1,0,m<<2);
		swap(x,y);
		x[sa[1]]=1;m=1;
		for(int i=2;i<=n;++i)x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+len]==y[sa[i-1]+len]?m:++m;
		if(m==n)break;
	}
	for(int i=1;i<=n;++i)rk[sa[i]]=i;
	for(int i=1,k=0;i<=n;++i)
	{
		if(rk[i]==1)continue;
		if(k)--k;
		while(s[i+k]==s[sa[rk[i]-1]+k])++k;
		height[rk[i]]=k;
	}
}
int last[1000010];
vector<int>pos[1000010];
long long ans;
int main()
{
	scanf("%d %s",&n,s+1);
	getsa();
	pos[n].push_back(-n-1);
//	for(int i=1;i<=n;++i)printf("%d ",rk[i]);printf("\n");
//	for(int i=1;i<=n;++i)printf("%d ",height[i]);printf("\n");
	for(int i=n,cur=n;i;--i)
	{
		cur+=s[i]=='('?1:-1;
		int l=i+height[rk[i]]+1,r=last[cur+1]?last[cur+1]:n+1;
		pos[cur].push_back(-i);
//		printf("%d %d\n",l,r);
		if(l<=r)ans+=upper_bound(pos[cur].begin(),pos[cur].end(),-l)-lower_bound(pos[cur].begin(),pos[cur].end(),-r);
		last[cur]=i;
	}
	printf("%lld",ans);
	return 0;
}