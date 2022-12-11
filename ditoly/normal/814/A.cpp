#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100
int a[MN+5],b[MN+5];
int main()
{
	int n,k,i,j;
	n=read();k=read();
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=k;++i)b[i]=read();
	sort(b+1,b+k+1);
	for(i=1,j=k;i<=n;++i)if(!a[i])a[i]=b[j--];
	for(i=1;i<n;++i)if(a[i]>a[i+1])return 0*puts("Yes");
	puts("No");
}