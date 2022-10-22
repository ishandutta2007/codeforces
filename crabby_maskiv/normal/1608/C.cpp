#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
int n,m;
int a[N],b[N],id[N];
vector<int> g[N];
int dfn[N],low[N],scc[N],tot,len;
bool ins[N];
stack<int> s;
void tarjan(int u){
	dfn[u]=low[u]=++tot;
	ins[u]=1;
	s.push(u);
	for(auto v:g[u]){
		if(dfn[v]){
			if(ins[v]) low[u]=min(low[u],dfn[v]);
		}
		else{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
	}
	if(low[u]==dfn[u]){
		len++;
		while(!s.empty()){
			int x=s.top();s.pop();
			ins[x]=0;
			scc[x]=len;
			if(x==u) break;
		}
	}
}
inline bool cmpa(int x,int y){
	return a[x]<a[y];
}
inline bool cmpb(int x,int y){
	return b[x]<b[y];
}
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) cin>>b[i];
		tot=len=0;
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=n;i++) id[i]=i;
		sort(id+1,id+n+1,cmpa);
		for(i=1;i<n;i++) g[id[i+1]].push_back(id[i]);
		sort(id+1,id+n+1,cmpb);
		for(i=1;i<n;i++) g[id[i+1]].push_back(id[i]);
		for(i=1;i<=n;i++) low[i]=dfn[i]=0;
		tarjan(id[n]);
		for(i=1;i<=n;i++) cout<<(scc[i]==len);
		cout<<endl;
	}
	return 0;
}