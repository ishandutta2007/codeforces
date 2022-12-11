#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 700
int a[MN+5],g[MN+5][MN+5],l[MN+5][MN+5],r[MN+5][MN+5];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
	int n=read(),i,j,k,x;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)g[i][j]=gcd(a[i],a[j])>1;
	for(i=0;i<=n;++i)l[i+1][i]=r[i+1][i]=1;
	for(x=0;x<n;++x)for(i=1;i+x<=n;++i)for(j=i+x,k=i;k<=j;++k)
		l[i][j]|=g[i-1][k]&r[i][k-1]&l[k+1][j],
		r[i][j]|=g[k][j+1]&r[i][k-1]&l[k+1][j];
	for(i=1;i<=n;++i)if(r[1][i-1]&l[i+1][n])return 0*puts("Yes");
	puts("No");
}