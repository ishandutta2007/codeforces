#include<bits/stdc++.h>
using namespace std;
#define re register int
#define un unsigned
#define ll un long long
#define ak *
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
inline ll qpow(ll x,ll y,ll p,ll z=1)
{
 	for(;y;y>>=1,x=(x*x)%p) z=(y&1)?(x*z)%p:z;
	return z;
}
int n,a[5000005],l,r,ans;
int main()
{
	n=r=read();l=1;
	for(re i=1;i<=n;i++) a[i]=read();
	if(a[l]!=a[r]) return cout<<n-1,0;
	while(a[l]==a[r]) l++; ans=max(ans,r-l);
	l=1;while(a[l]==a[r]) r--; ans=max(ans,r-l);
	re op=0;r=n;
	while(a[l]==a[r])
	{
		if(!op) l++;
		else r--;
		op^=1;
	}
	ans=max(ans,r-l);
	cout<<ans;
	return 0;
}