#include<cstdio>
#include<algorithm>
using namespace std;
char B[1<<26],*S=B,C;int X,F;
inline int read()
{
	for(F=1;(C=*S++)<'0'||C>'9';)if(C=='-')F=-1;
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X*F;
}
#define MN 100000
int a[MN+5],an;
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),i,x,ans=0;
	for(i=1;i<=n;++i)
		if((x=read())&1)a[++an]=x;
		else if(x>0)ans+=x;
	sort(a+1,a+an+1);
	ans+=a[an];
	for(i=an;--i>1;--i)if(a[i]+a[i-1]>0)ans+=a[i]+a[i-1];else break;
	printf("%d",ans);
}