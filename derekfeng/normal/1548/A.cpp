#include<bits/stdc++.h>
using namespace std;
int n,m,a[200004],g[200004],q;
int u,v,ans,op;
int main(){
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		if(g[u]>0&&a[u]>0)ans--;
		if(g[v]>0&&a[v]>0)ans--;
		g[u]++,g[v]++;
		a[min(u,v)]++;
		if(g[u]>0&&a[u]>0)ans++;
		if(g[v]>0&&a[v]>0)ans++;
	}
	cin>>q;
	while(q--){
		cin>>op;
		if(op==1){
			cin>>u>>v;
			if(g[u]>0&&a[u]>0)ans--;
			if(g[v]>0&&a[v]>0)ans--;
			g[u]++,g[v]++;
			a[min(u,v)]++;
			if(g[u]>0&&a[u]>0)ans++;
			if(g[v]>0&&a[v]>0)ans++;	
		}
		if(op==2){
			cin>>u>>v;
			if(g[u]>0&&a[u]>0)ans--;
			if(g[v]>0&&a[v]>0)ans--;
			g[u]--,g[v]--;
			a[min(u,v)]--;
			if(g[u]>0&&a[u]>0)ans++;
			if(g[v]>0&&a[v]>0)ans++;
		}
		if(op==3)cout<<n-ans<<"\n";
	}
}