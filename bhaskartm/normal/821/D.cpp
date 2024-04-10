#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	bool booly=false;
	int index=-1;
	vector<pair<int, int>>e;
	for(int i=0; i<k; i++){
		int u, v;
		cin>>u>>v;
		if(u==n && v==m){
			booly=true;
			index=i;
		}
		e.pb({u, v});
	}
	if(booly==false){
		e.pb({n, m});
	}
	vector<vector<int>>adj;
	adj.resize(k+1);
	for(int i=0; i<=k; i++){
		for(int j=i+1; j<=k; j++){
			auto p1=e[i];
			auto p2=e[j];
			if(min(abs(p1.f-p2.f), abs(p1.s-p2.s))<=2){
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	int d[3*k+5];
	int pro[3*k+5];
	
	for(int i=0; i<3*k+5; i++){
		d[i]=1000000000;
		pro[i]=0;
	}
	d[0]=0;
	set<pair<int, int>>se;
	se.insert({d[0], 0});
	while(!se.empty()){
		auto it=se.begin();
		int no=(*it).s;
		if(pro[no]==1){
			se.erase((*it));
			continue;
		}
		pro[no]=1;
		int node=no/3;
		int pos=no%3;
		int dis=(*it).f;
		se.erase((*it));
		for(auto u:adj[node]){
			if(pos==0){
				if(min(abs(e[u].f-e[node].f), abs(e[u].s-e[node].s))==2){
					if(1+dis<d[3*u]){
						d[3*u]=1+dis;
						se.insert({d[3*u], 3*u});
					}
				}
				else if(abs(e[u].f-e[node].f)==1 && abs(e[u].s-e[node].s)==1){
					if(d[3*u+1]>dis+1){
						d[3*u+1]=dis+1;
						se.insert({d[3*u+1], 3*u+1});
					}
					if(d[3*u+2]>dis+1){
						d[3*u+2]=dis+1;
						se.insert({d[3*u+2], 3*u+2});
					}
				}
				else if(e[u].f==e[node].f && abs(e[u].s-e[node].s)==1){
					if(d[3*u]>dis){
						d[3*u]=dis;
						se.insert({d[3*u], 3*u});
					}
				}
				else if(e[u].f==e[node].f ){
					if(d[3*u+2]>dis+1){
						d[3*u+2]=dis+1;
						se.insert({d[3*u+2], 3*u+2});
					}
				}
				else if(e[u].s==e[node].s && abs(e[u].f-e[node].f)==1){
					if(d[3*u]>dis){
						d[3*u]=dis;
						se.insert({d[3*u], 3*u});
					}
				}
				else if(e[u].s==e[node].s){
					if(d[3*u+1]>dis+1){
						d[3*u+1]=dis+1;
						se.insert({d[3*u+1], 3*u+1});
					}
				}
				else{
					if(d[3*u]>1+dis){
						d[3*u]=1+dis;
						se.insert({d[3*u], 3*u});
					}
				}
			}
			else if(pos==1){
				if(min(abs(e[u].f-e[node].f), abs(e[u].s-e[node].s))==2){
					if(1+dis<d[3*u]){
						d[3*u]=1+dis;
						se.insert({d[3*u], 3*u});
					}
				}
				else if(e[u].s==e[node].s){
					if(d[3*u+1]>dis){
						d[3*u+1]=dis;
						se.insert({d[3*u+1], 3*u+1});
					}
				}
				else if(abs(e[u].s-e[node].s)==1){
					if(d[3*u]>dis){
						d[3*u]=dis;
						se.insert({d[3*u], 3*u});
					}
				}
				else if(e[u].f==e[node].f){
					if(d[3u+2]>1+dis){
						d[3*u+2]=1+dis;
						se.insert({d[3*u+2], 3*u+2});
					}
				}
				else{
					if(d[3*u]>1+dis){
						d[3*u]=1+dis;
						se.insert({d[3*u], 3*u});
					}
				}
			}
			else{
				if(min(abs(e[u].f-e[node].f), abs(e[u].s-e[node].s))==2){
					if(1+dis<d[3*u]){
						d[3*u]=1+dis;
						se.insert({d[3*u], 3*u});
					}
				}
				else if(e[u].f==e[node].f){
					if(d[3*u+2]>dis){
						d[3*u+2]=dis;
						se.insert({d[3*u+2], 3*u+2});
					}
				}
				else if(abs(e[u].f-e[node].f)==1){
					if(d[3*u]>dis){
						d[3*u]=dis;
						se.insert({d[3*u], 3*u});
					}
				}
				else if(e[u].s==e[node].s){
					if(d[3u+1]>1+dis){
						d[3*u+1]=1+dis;
						se.insert({d[3*u+1], 3*u+1});
					}
				}
				else{
					if(d[3*u]>1+dis){
						d[3*u]=1+dis;
						se.insert({d[3*u], 3*u});
					}
				}
			}
		}
	}
	int ans=1000000000;
	if(booly==true){
		ans=min(ans, d[3*index]);
		ans=min(ans, d[3*index+1]);
		ans=min(ans, d[3*index+2]);
		if(ans==1000000000){
			cout<<-1;
			return 0;
		}
		else{
			cout<<ans;
			return 0;
		}
	}
	
	for(int i=0; i<3*k; i++){
		int node=i/3;
		int pos=i%3;
		
		
		if(pos==0){
			if(e[node].f>=n-1 || e[node].s>=m-1){
			
			ans=min(d[3*node]+1, ans);
			
			}
		}
		else if(pos==1){
			if(e[node].s==m){
				ans=min(ans, d[3*node+1]);
			}
			else if(e[node].s>=m-1 || e[node].f>=n-1){
				ans=min(ans, d[3*node+1]+1);
			}
		}
		else{
			if(e[node].f==n){
				ans=min(ans, d[3*node+2]);
			}
			else if(e[node].s>=m-1 || e[node].f>=n-1){
				ans=min(ans, d[3*node+2]+1);
			}
		}
	}
	if(ans==1000000000){
		cout<<-1;
	}
	else{
		
		cout<<ans;
	}
	
	return 0;
}