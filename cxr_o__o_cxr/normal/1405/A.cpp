//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define re register
int a[104];
int main(){
	for(re int T=read(),n;T--;){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=n;i;--i)cout<<a[i]<<" ";puts("");
	}	
	return (0-0);
}