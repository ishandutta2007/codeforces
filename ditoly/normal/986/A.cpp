#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define MK 100
int a[MN+5][MK+5],q[MN+5],qn;
vector<int> v[MN+5];
inline void ins(int x,int y)
{
	v[x].push_back(y);
	v[y].push_back(x);
}
int main()
{
	int n,m,k,s,i,j,l;
	n=read();m=read();k=read();s=read();
	for(i=1;i<=n;++i)a[i][read()]=1;
	while(m--)ins(read(),read());
	for(i=1;i<=k;++i)
	{
		for(qn=0,j=1;j<=n;++j)if(a[j][i])q[++qn]=j;
		for(j=1;j<=qn;++j)for(l=0;l<v[q[j]].size();++l)
			if(!a[v[q[j]][l]][i])a[q[++qn]=v[q[j]][l]][i]=a[q[j]][i]+1;
	}
	for(i=1;i<=n;++i)
	{
		sort(a[i]+1,a[i]+k+1);
		for(l=0,j=1;j<=s;++j)l+=a[i][j]-1;
		printf("%d ",l);
	}
}