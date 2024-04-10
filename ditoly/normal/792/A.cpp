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
#define MN 200000
int a[MN+5];
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),i,mn=0x7FFFFFFF,cnt=0;
	for(i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(i=1;i<n;++i)
	{
		a[i]=a[i+1]-a[i];
		if(a[i]<mn)mn=a[i],cnt=0;
		if(a[i]==mn)++cnt;
	}
	printf("%d %d",mn,cnt);
}