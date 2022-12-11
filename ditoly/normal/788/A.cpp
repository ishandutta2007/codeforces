#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
char B[1<<26],*S=B,C;int X,F;
inline int read()
{
	for(F=1;(C=*S++)<'0'||C>'9';)if(C=='-')F=-1;
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X*F;
}
#define MN 200000
int a[MN+5];
ll s[MN+5];
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),i,p;long long mx=0,mn;
	for(i=1;i<=n;++i)a[i]=read();
	for(mn=0,i=p=1;i<n;++i,p*=-1)
	{
		s[i]=s[i-1]+abs(a[i+1]-a[i])*p;
		mx=max(mx,s[i]-mn);
		if(~i&1)mn=min(mn,s[i]);
	}
	for(mn=0,i=1,p=-1;i<n;++i,p*=-1)
	{
		s[i]=s[i-1]+abs(a[i+1]-a[i])*p;
		mx=max(mx,s[i]-mn);
		if(i&1)mn=min(mn,s[i]);
	}
	printf("%I64d",mx);
}