//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=3e5+4,inf=0x3f3f3f3f;
int n,ans[N];
vector<int>a[N];
int main(){
	for(int T=read();T--;){
		n=read();
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<=n;i++){
			a[read()].push_back(i);
		}
		memset(ans,0x3f,sizeof(int)*(n+1));
		for(int i=1,pre,mx;i<=n;i++)if(!a[i].empty()){
			a[i].push_back(n+1);
			pre=mx=0;
			for(auto v:a[i]){
				mx=max(mx,v-pre);
				pre=v;
			}
			ans[mx]=min(ans[mx],i);
		}
		for(int i=1;i<=n;i++){
			ans[i]=min(ans[i],ans[i-1]);
			if(ans[i]==inf)cout<<"-1 ";
			else cout<<ans[i]<<" ";
		}
		puts("");
	}
	return (0-0);
}