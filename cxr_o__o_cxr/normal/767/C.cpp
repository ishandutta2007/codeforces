//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e6+4;
int n,sum,rt,ans[N],a[N],siz[N];
vector<int>e[N];
inline void dfs(int x){
	siz[x]=a[x];
	for(auto v:e[x]){
		dfs(v);
		siz[x]+=siz[v];
	}
	if((siz[x]==sum)){
		ans[++ans[0]]=x;
		siz[x]=0;
	}
}
int main(){
	n=read();
	for(int i=1,x;i<=n;i++){
		x=read();
		if(x)e[x].push_back(i);
		else rt=i;
		a[i]=read();
		sum+=a[i];
	}
	if(sum%3){puts("-1");return (0-0);}
	sum/=3;
	dfs(rt);
//	assert(ans[0]<=2);
	if(ans[0]<=2)puts("-1");
	else cout<<ans[1]<<" "<<ans[2];
	return (0-0);
}