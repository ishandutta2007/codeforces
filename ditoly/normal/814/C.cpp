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
#define MN 1500
char s[MN+5];
int ans[256][MN+5],a[MN+5];
inline void rw(int&a,int b){if(b>a)a=b;}
int main()
{
	int n=read(),i,j,k;
	scanf("%s",s+1);
	for(i='a';i<='z';++i)
	{
		for(j=1;j<=n;++j)a[j]=a[j-1]+(s[j]!=i);
		for(j=1;j<=n;++j)for(k=1;k<=j;++k)
			rw(ans[i][a[j]-a[k-1]],j-k+1);
		for(j=1;j<=n;++j)rw(ans[i][j],ans[i][j-1]);
	}
	for(i=read();i--;)j=read(),scanf("%s",s),printf("%d\n",ans[s[0]][j]);
}