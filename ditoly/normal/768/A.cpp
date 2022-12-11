#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 100000
int a[MN+5];
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),i,ans=0;;
	for(i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i)if(a[i]!=a[1]&&a[i]!=a[n])++ans;
	printf("%d",ans);
}