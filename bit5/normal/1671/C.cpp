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
int n,x;
ll a[N];
inline void work(){
	n=read(),x=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	ll d=0,ans=0;
	for(int i=n;i;i--){
		ll tmp=x-a[i]-d*i;
		if(tmp<0)continue;
		ll D=tmp/i+1;
		ans+=D*i,d+=D;	
	}
	printf("%lld\n",ans);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}