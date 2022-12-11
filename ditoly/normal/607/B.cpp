#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
const int MN=505;
int c[MN+5],f[MN][MN];
int cal(int l,int r)
{
	if(l>=r)return 1;
	if(f[l][r])return f[l][r];
	f[l][r]=c[l]==c[r]?cal(l+1,r-1):MN;
	for(int i=l;i<r;++i)f[l][r]=min(f[l][r],cal(l,i)+cal(i+1,r));
	return f[l][r];
}
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)c[i]=read();
	printf("%d",cal(1,n));
}