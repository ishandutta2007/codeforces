//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define re register
signed main(){
	for(re int T=read(),n,pre,x,ans;T--;){
		n=read();
		ans=pre=0;
		for(re int i=1;i<=n;++i){
			x=read();
			if(x<0){
				ans+=max(-x-pre,0ll);
				pre-=-x-max(-x-pre,0ll);
			}
			else pre+=x;
		}
		cout<<ans<<"\n";
	}	
	return (0-0);
}