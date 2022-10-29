#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,x,a[N];
inline void work(){
	n=read(),x=read();
	int mn=2e5,mx=0;
	for(int i=1;i<=n;i++)a[i]=read(),mn=min(mn,a[i]),mx=max(mx,a[i]);
	ll ans=0;
	for(int i=2;i<=n;i++)ans+=abs(a[i]-a[i-1]);
	ans+=min(min(a[1],a[n])-1,(mn-1)*(1+(a[1]!=mn && a[n]!=mn)));
	ans+=max(0,min(x-max(a[1],a[n]),(x-mx)*(1+(a[1]!=mx && a[n]!=mx))));
	printf("%lld\n",ans);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}