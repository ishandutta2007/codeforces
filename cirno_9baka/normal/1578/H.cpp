#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,f[505][505],p[505][505],ans,a[505],b[505],s,o;
char c[505][505];
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%s",c[i]+1);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			f[i][j]=(c[i][j]=='W'?0:1);
			if(f[i][j])
			{
				p[i][j]^=1;
				p[i+1][j]^=1;
				p[i][j+1]^=1;
				p[i+1][j+1]^=1;
			}
		}
	for(i=2;i<=n;++i)
		a[i]=p[i][1];
	for(i=2;i<=m;++i)
		b[i]=p[1][i];
	o=p[1][1];
	for(i=2;i<=n;++i)
		for(j=2;j<=m;++j)
		{
			a[i]^=p[i][j],b[j]^=p[i][j];
			s+=p[i][j];
			o^=p[i][j];
		}
	for(i=2;i<=n;++i)
	{
		s+=a[i];
		o^=a[i];
	}
	for(i=2;i<=m;++i)
	{
		s+=b[i];
		o^=b[i];
	}
	s+=o;
	int fl=0;
	for(i=2;i<=n;++i)
		for(j=2;j<=m;++j)
			if(o&&p[i][j]&&a[i]&&b[j])
				fl=1;
	s-=fl;
	cout<<s;
}