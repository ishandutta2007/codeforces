#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
int t,n,s,nows,ans,u[200005],v[200005],w[200005],first[200005],nxt[200005],size[200005];
struct node{
	int num,size,val;
	bool operator <(const node &x)const{
		return x.val>val; 
	} 
};
priority_queue <node>h;
inline void dfs(int now,int fa){
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=fa){
			dfs(v[i],now);
			size[now]+=size[v[i]];
			nows+=size[v[i]]*w[i];
			node c;
			c.num=w[i],c.size=size[v[i]];
			c.size=size[v[i]];
			c.val=(c.num-c.num/2)*size[v[i]];
			h.push(c);
		}
	if (size[now]==0)size[now]=1;
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		for (int i=1;i<n;i++){
			scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i],w[i+n]=w[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		dfs(1,0);
		while(nows>s){
			node c=h.top();
			h.pop();
			nows-=c.val;
			ans++;
			c.num/=2;
			c.val=(c.num-c.num/2)*c.size;
			if (c.val>0)h.push(c);
		}
		cout<<ans<<endl;
		nows=ans=0;
		for (int i=1;i<=n*2;i++)u[i]=v[i]=w[i]=first[i]=nxt[i]=size[i]=0;
		while(!h.empty())h.pop();
	}
	return 0;
}