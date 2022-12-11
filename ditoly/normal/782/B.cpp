#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 60000
int x[MN+5],v[MN+5];
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),i,p;double l=0,r=0x3FFFFFFF,mid,mn,mx,ans;
	for(i=1;i<=n;++i)x[i]=read();
	for(i=1;i<=n;++i)v[i]=read();
	for(p=1;p<=100;++p)
	{
		mid=(l+r)/2;
		for(mn=1e18,mx=-1e18,i=1;i<=n;++i)
			mn=min(mn,x[i]+mid*v[i]),mx=max(mx,x[i]-mid*v[i]);
		if(mx-mn<1e-12)ans=r=mid;
		else l=mid;
	}
	printf("%.12lf",ans);
}