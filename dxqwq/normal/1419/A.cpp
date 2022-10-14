#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
int read09(){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	return c-'0'; 
}
int T,n,a[1005];
signed main(){
	T=read();
	while(T--){
		n=read();
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			a[i]=read09();
			if(i%2==1&&a[i]%2==1)flag1=0;
			if(i%2==0&&a[i]%2==0)flag2=0;
		}
		if(n&1)puts(flag1?"2":"1");
		else puts(flag2?"1":"2");
	}
	return 0;
}