#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
int to[N],c[N];
bool vis[N];
int b[N],len;
void dfs(int u){
	b[++len]=u;vis[u]=1;
	if(to[u]!=b[1]) dfs(to[u]);
}
int solve(int u){
	int i,j,k;
	len=0;
	dfs(u);
	int ret=len;
	for(i=1;i<=len;i++){
		if(len%i) continue;
		for(j=1;j<=i;j++){
			for(k=j;k<=len;k+=i)
				if(c[b[k]]!=c[b[j]]) break;
			if(k>len) ret=min(ret,i);
		}
	}
	return ret;
}
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) vis[i]=0;
		for(i=1;i<=n;i++) cin>>to[i];
		for(i=1;i<=n;i++) cin>>c[i];
		int ans=n;
		for(i=1;i<=n;i++){
			if(!vis[i])
				ans=min(ans,solve(i));
		}
		cout<<ans<<endl;
	}
	return 0;
}