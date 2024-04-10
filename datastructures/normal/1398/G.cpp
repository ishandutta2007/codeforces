#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
bitset <200001>awa,c;
int n,x,y,a[200005],ans[1000005],q,l;
inline int read(){
	register int x=0; 
	register char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
	cin>>n>>x>>y;
	for (register int i=0;i<=n;i++)a[i]=read(),awa[a[i]]=1;
	for (register int i=0;i<=n;i++)c|=(awa>>a[i]);
	memset(ans,-1,sizeof(ans));
	for (register int i=1;i<=200000;i++){
		if (!c[i])continue;
		for (register int j=2*(i+y);j<=1000000;j+=2*(i+y))ans[j]=2*(i+y);
	}
	cin>>q;
	while(q--){
		scanf("%d",&l);
		printf("%d ",ans[l]);
	}
	puts("");
	return 0;
}