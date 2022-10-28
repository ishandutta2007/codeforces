#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
int pro[10005];
int n, m, l, s1, t1;
vector<vector<pair<int, pair<int, int>>>>adj;
vector<pair<pair<int, int>, pair<int, int>>>edge;

int djk(){
	int dis[n];
	int process[n];
	for(int i=0; i<n; i++){
		dis[i]=pow(10, 14);
		process[i]=0;
	}
	dis[s1]=0;
	
	set<pair<int, int>>se;
	se.insert({dis[s1], s1});
	while(!se.empty()){
		auto it=se.begin();
		int v=(*it).s;
		if(process[v]){
			se.erase((*it));
			continue;
		}
		process[v]=1;
		se.erase((*it));
		for(auto u:adj[v]){
			int w=u.s.f;
			if(pro[u.s.s]==0){
				continue;
			}
			if(pro[u.s.s]==2){
				w=1;
			}
			if(w+dis[v]<dis[u.f]){
				dis[u.f]=w+dis[v];
				se.insert({dis[u.f], u.f});
			}
		}
	}
	return dis[t1];
}

int djk2(int value){
	int dis[n];
	int process[n];
	for(int i=0; i<n; i++){
		dis[i]=pow(10, 14);
		process[i]=0;
	}
	dis[s1]=0;
	
	set<pair<int, int>>se;
	se.insert({dis[s1], s1});
	while(!se.empty()){
		auto it=se.begin();
		int v=(*it).s;
		if(process[v]){
			se.erase((*it));
			continue;
		}
		process[v]=1;
		se.erase((*it));
		for(auto u:adj[v]){
			int w=u.s.f;
			if(pro[u.s.s]==0){
				continue;
			}
			if(pro[u.s.s]==2){
				w=1;
			}
			if(pro[u.s.s]==3){
				w=value;
			}
			if(w+dis[v]<dis[u.f]){
				dis[u.f]=w+dis[v];
				se.insert({dis[u.f], u.f});
			}
		}
	}
	return dis[t1];
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m>>l>>s1>>t1;
	adj.resize(n+1);
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		if(w!=0){
			pro[i]=1;
		}
		edge.pb({{u, v}, {w, i}});
		adj[u].pb({v, {w, i}});
		adj[v].pb({u, {w, i}});
	}
	int val=djk();
	if(val==l){
		cout<<"YES"<<endl;
		for(auto u:edge){
			cout<<u.f.f<<" "<<u.f.s<<" ";
			if(pro[u.s.s]==0){
				cout<<10000000000000<<endl;
			}
			else{
				cout<<u.s.f<<endl;
			}
		}
		return 0;
	}
	if(val<l){
		cout<<"NO";
		return 0;
	}
	for(auto e:edge){
		if(pro[e.s.s]==1){
			continue;
		}
		pro[e.s.s]=2;
		int mini=djk();
		if(mini>l){
			continue;
		}
		pro[e.s.s]=3;
		int lo=1;
		int hi=pow(10, 13);
		int ans=-1;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			int val=djk2(mid);
			if(val>l){
				hi=mid-1;
				continue;
			}
			if(val<l){
				lo=mid+1;
				continue;
			}
			else{
				ans=mid;
				break;
			}
		}
		cout<<"YES"<<endl;
		for(auto e:edge){
			cout<<e.f.f<<" "<<e.f.s<<" ";
			if(pro[e.s.s]==0){
				cout<<1000000000000<<endl;
			}
			if(pro[e.s.s]==1){
				cout<<e.s.f<<endl;
			}
			if(pro[e.s.s]==2){
				cout<<1<<endl;
			}
			if(pro[e.s.s]==3){
				cout<<ans<<endl;
			}
		}
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}