#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 3000
int c[MN+5],u[MN+5],a[MN+5];
vector<int> v[MN+5];
bool cmp(int x,int y){return c[x]<c[y];}
int main()
{
	int n,m,i,j,k;long long ans=1e18,s,p;
	n=read();m=read();
	for(i=1;i<=n;++i)v[read()].push_back(i),c[i]=read(),a[i]=i;
	for(i=1;i<=m;++i)sort(v[i].begin(),v[i].end(),cmp);
	sort(a+1,a+n+1,cmp);
	for(i=v[1].size();i<=n;++i)if(i)
	{
		memset(u,0,sizeof(u));
		for(j=0;j<v[1].size();++j)u[v[1][j]]=1;
		for(s=p=0,j=2;j<=m;++j)if(v[j].size()>=i)
			for(k=0;k<=v[j].size()-i;++k)s+=c[v[j][k]],u[v[j][k]]=1,++p;
		for(j=1;p<i-v[1].size();++p){while(u[a[j]])++j;s+=c[a[j]];u[a[j]]=1;}
		ans=min(ans,s);
	}
	cout<<ans;
}