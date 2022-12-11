#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int n,head[210],nxt[410],to[410],deep[210],tot,t0t,ans;
map<string,int>m;string t1,t2,tt;
inline void addedge(int b,int e){nxt[++t0t]=head[b];head[b]=t0t;to[t0t]=e;}
inline int getv(string&x){if(m.find(x)!=m.end())return m[x];else return m[x]=++tot;}
void dfs(int u){
	ans=max(ans,deep[u]);
	for(int i=head[u];i;i=nxt[i]){
		deep[to[i]]=deep[u]+1;
		dfs(to[i]);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>t1>>tt>>t2;
		transform(t1.begin(),t1.end(),t1.begin(),::tolower);
		transform(t2.begin(),t2.end(),t2.begin(),::tolower);
		int v1=getv(t1),v2=getv(t2);
		//cout<<t1<<" "<<t2<<endl;
		//cout<<v1<<" "<<v2<<endl;
		addedge(v2,v1);
	}int v1=m[string("polycarp")];deep[v1]=1;dfs(v1);
	cout<<ans<<endl;
	return 0;
}