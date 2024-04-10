#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
signed main(){
	for(int T=read(),n,x,sum,mx;T--;){
		n=read();
		sum=mx=0;
		for(int i=1;i<=n;i++){
			x=read();
			sum+=x;
			mx=max(mx,x);
		}
		if(mx>(sum>>1)||(sum&1))puts("T");
		else puts("HL");
	} 
	return (0-0);
}