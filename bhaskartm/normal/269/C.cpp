#include<bits/stdc++.h>
using namespace std;
struct P{
	int to,val,id,dir;
};
vector<P>G[202000];
 
int n,m,x,y,z,deg[202000],ans[202000];
queue<int>q;
 
int main(){
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		cin>>x>>y>>z;
		G[x].push_back((P){y,z,i,0});
		G[y].push_back((P){x,z,i,1});
		deg[x]+=z; deg[y]+=z;
	}
	deg[1]=0;
	for (int i=1;i<n;++i) deg[i]/=2;
	for (q.push(1);!q.empty();q.pop()){
		x=q.front();
		for (auto o:G[x]) if (deg[o.to]){
			ans[o.id]=o.dir;
			if (!(deg[o.to]-=o.val)) q.push(o.to);
		}
	}
	for (int i=1;i<=m;i++) puts(ans[i]?"1":"0");
}