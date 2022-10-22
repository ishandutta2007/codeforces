#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e6+10;
int n,a[o],b[o],nxt[o];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=n;i;--i) b[a[i]]=i;
	nxt[a[n]]=n+1;
	for(int i=a[n]-1;i;--i) if(b[i+1]) nxt[i]=b[i+1];else nxt[i]=nxt[i+1];
	for(long long W=1,w,t,kl,kr;1;++W) if(W*W+W>=a[1]){
		w=W;kl=max(0ll,w*w-a[1]);kr=w*w+w-a[1];
		for(int i,j=1;j<=n&&kl<=kr;j=i){
			for(;w*w+w<a[j]+kl;++w);
			t=w*w+w-kl;i=(t>a[n]?n+1:nxt[t]);kl=max(kl,w*w-a[j]);kr=min(kr,w*w+w-a[i-1]);
		}
		if(kl<=kr){printf("%lld",kl);return 0;}
	}
}