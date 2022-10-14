#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;
	scanf("%d",&x);
	return x;
}
int a[1000003];
struct node
{
	int pos;
};
bool cmp(node x,node y)
{
	return a[x.pos]>a[y.pos];
}
bool cmpcmp(node x,node y)
{
	return x.pos<y.pos;
}

node b[1000003];
int n,k;
int main()
{
	n=read(),k=read();
	for(int i=1; i<=n; i++) b[i].pos=a[i]=read();
	sort(b+1,b+n+1,cmp);
	sort(b+1,b+k+1,cmpcmp);
	b[0].pos=0;
	long long ans=0;
	for(int i=1; i<=k; i++) ans+=a[b[i].pos];
	printf("%lld ",ans);
	ans=1;
	for(int i=2; i<=k; i++) ans*=b[i].pos-b[i-1].pos,ans%=998244353;
	printf("%lld",ans);
	return 0;
}