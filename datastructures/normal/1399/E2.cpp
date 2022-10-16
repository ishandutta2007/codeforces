#include <iostream>
#include <cstdio>
#include <queue>
#define inf 1000000000
#define int long long
using namespace std; 
int t,n,s,nows,ans;
int u[200005],v[200005],w[200005],c[200005],first[200005],nxt[200005],size[200005];
int len1,q1[5000005],len2,q2[5000005];
struct node{
	int num,size,val;
	bool operator <(const node &x)const{
		return x.val>val;
	}
};
priority_queue <node>h1,h2; 
inline void dfs(int now,int fa){
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=fa){
			dfs(v[i],now);
			size[now]+=size[v[i]];
			nows+=w[i]*size[v[i]];
			node x;
			x.num=w[i],x.size=size[v[i]];
			x.val=(x.num-x.num/2)*x.size;
			if (c[i]==1)h1.push(x);
			if (c[i]==2)h2.push(x);
		}
	if (size[now]==0)size[now]=1;
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		for (int i=1;i<n;i++){
			scanf("%lld%lld%lld%lld",&u[i],&v[i],&w[i],&c[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i],w[i+n]=w[i],c[i+n]=c[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		dfs(1,0);
		while(!h1.empty()){
			node x=h1.top();
			h1.pop();
			q1[++len1]=x.val;
			q1[len1]+=q1[len1-1];
			x.num/=2;
			x.val=(x.num-x.num/2)*x.size;
			if (x.val>0)h1.push(x);
		}
		while(!h2.empty()){
			node x=h2.top();
			h2.pop();
			q2[++len2]=x.val;
			q2[len2]+=q2[len2-1];
			x.num/=2;
			x.val=(x.num-x.num/2)*x.size;
			if (x.val>0)h2.push(x);
		}
		int j=len2;
		ans=inf;
		for (int i=0;i<=len1;i++){
			while(q1[i]+q2[j-1]>=nows-s&&j>0)j--;
			if (q1[i]+q2[j]>=nows-s)ans=min(ans,i+2*j);
		}
		cout<<ans<<endl;
		nows=ans=len1=len2=0;
		for (int i=1;i<=2*n;i++)u[i]=v[i]=w[i]=c[i]=first[i]=nxt[i]=size[i]=0;
	}
	return 0;
}