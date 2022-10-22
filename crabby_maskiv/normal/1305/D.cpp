#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll mod=998244353;
int n,m;
struct edge{
	int v,nxt;
}g[N<<1];
int hd[N],tl[N],Pe;
inline void add(int u,int v){
	int p=++Pe;g[p].v=v;
	if(!hd[u]) hd[u]=tl[u]=p;
	else tl[u]=g[tl[u]].nxt=p;
}
bool vis[N];
int d[N];
int f;
bool flag=0;
void dfs(int u,int last){
	if(u==f){
		flag=1;
		return;
	}
	for(int p=hd[u];p;p=g[p].nxt){
		int v=g[p].v;if(v==last) continue;
		dfs(v,u);
		if(flag){
			vis[u]=1;
			return;
		}
	}
}
void dfs1(int u,int last){
	for(int p=hd[u];p;p=g[p].nxt){
		int v=g[p].v;if(v==last) continue;
		d[v]=d[u]+(!vis[v]);
		dfs1(v,u);
	}
}
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(j=1;j<=n/2+1;j++){
		int tmp=0;
		for(i=1;i<=n;i++)
			tmp+=(!vis[i]);
		if(tmp==1){
			cout<<"! ";
			for(i=1;i<=n;i++){
				if(!vis[i]){
					cout<<i<<endl;
					return 0;
				}
			}
		}
		memset(d,0,sizeof(d));d[1]=(!vis[1]);
		dfs1(1,0);
		tmp=0;
		for(i=1;i<=n;i++){
			if(!vis[i]&&d[i]>d[tmp])
				tmp=i;
		}
		int u,v=tmp;
		memset(d,0,sizeof(d));d[v]=(!vis[v]);
		dfs1(v,0);
		tmp=0;
		for(i=1;i<=n;i++){
			if(!vis[i]&&d[i]>d[tmp])
				tmp=i;
		}
		u=tmp;
		cout<<"? "<<u<<" "<<v<<endl;
		cin>>f;
		if(f==u||f==v){
			if(d[u]==2){
				cout<<"! "<<f<<endl;
				return 0;
			}
		}
		flag=0;dfs(u,0);
		flag=0;dfs(v,0);
	}
	return 0;
}