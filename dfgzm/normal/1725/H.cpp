#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
const int maxn=2e5+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
int n,m,a[maxn],c[4];
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read()%3,++c[a[i]];
	if(c[0]==0||c[0]==n){
		puts("1");
		for(int i=1;i<=n;i++)
			printf("%d",i<=n/2);
		return 0;
	}
	if(c[0]<=n/2){
		puts("0");int cnt=n/2-c[0];
		for(int i=1;i<=n;i++)
			printf("%d",!a[i]?1:(cnt?--cnt,1:0));
	}else{
		puts("2");int cnt=c[0]-n/2;
		for(int i=1;i<=n;i++)
			printf("%d",a[i]?1:(cnt?--cnt,1:0));
	}
	return 0;
}