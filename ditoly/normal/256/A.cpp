#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000000
vector<int> v[MN+5];
int a[MN+5],an;
int main()
{
	int n=read(),i,j,x,ii,jj,d,p,ans=0;
	for(i=1;i<=n;++i)
	{
		if(v[x=read()].empty())a[++an]=x;
		v[x].push_back(i);ans=max(ans,(int)v[x].size());
	}
	for(i=1;i<=an;++i)for(j=1;j<=an;++j)if(i!=j)for(ii=jj=d=p=0;;)
	{
		while(ii<v[a[i]].size()&&v[a[i]][ii]<d)++ii;
		if(ii<v[a[i]].size())d=v[a[i]][ii],++p;else{ans=max(ans,p);break;}
		while(jj<v[a[j]].size()&&v[a[j]][jj]<d)++jj;
		if(jj<v[a[j]].size())d=v[a[j]][jj],++p;else{ans=max(ans,p);break;}
	}
	printf("%d",ans);
}