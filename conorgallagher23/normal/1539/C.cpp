#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
LL read(){
	char ch=getchar(); LL x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}
const int N=200005;

LL n,k,x,a[N],b[N],cnt;

int main(){
	n=read(); k=read(); x=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) if(a[i]>a[i-1]+x) b[++cnt]=a[i]-a[i-1];
	sort(b+1,b+cnt+1);
	LL ans=cnt+1;
	for(int i=1;i<=cnt;i++){
		LL tar;
		if(b[i]%x==0) tar=b[i]/x;
		else tar=b[i]/x+1;
		tar--;
		if(k>=tar) k-=tar,ans--;
		else break;
	}
	cout<<ans<<'\n';
	return 0;
}