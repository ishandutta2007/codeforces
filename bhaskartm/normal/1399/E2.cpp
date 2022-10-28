#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define pb push_back
#define f first
#define s second
#define int long long int
vector<vector<pair<int, pair<int,int>>>>adj;
int le[100005];
multiset<pair<int, pair<int, int>>>s1;
multiset<pair<int, pair<int, int>>>s2;
int tot;
int sum1;
int sum2;

void dfs(int v, int p){
	if(adj[v].size()==1 && v!=1){
		le[v]=1;
		return;
	}
	for(auto u:adj[v]){
		if(u.f==p){
			continue;
		}
		dfs(u.f, v);
		le[v]+=le[u.f];
		int w=u.s.f;
		int ne=(u.s.f)/2;
		int dec=le[u.f]*(w-ne);
		if(u.s.s==1){
			s1.insert({dec, {w, le[u.f]}});
			sum1+=(le[u.f]*(u.s.f));
		}
		else{
			s2.insert({dec, {w, le[u.f]}});
			sum2+=(le[u.f]*(u.s.f));
		}
		tot+=(le[u.f]*(u.s.f));
	}
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, S;
		cin>>n>>S;
		s1.clear();
		s2.clear();
		sum1=0;
		sum2=0;
		adj.clear();
		adj.resize(n+1);
		tot=0;
		for(int i=0; i<=n; i++){
			le[i]=0;
		}
		for(int i=0; i<n-1; i++){
			int u, v, w, c;
			cin>>u>>v>>w>>c;
			adj[u].pb({v, {w, c}});
			adj[v].pb({u, {w, c}});
		}
		dfs(1, 1);
		
		int sc1=sum1;
		int sc2=sum2;
		int ste=0;
		vector<int>v1;
		vector<int>v2;
		v1.pb(0);
		v2.pb(0);
	
	
		while(sc1>0){
			
			auto it=s1.end();
			it--;
			int dec=(*it).f;
			int w=(*it).s.f;
			int num=(*it).s.s;
			
			sc1-=dec;
			
			s1.erase(s1.find((*it)));
			w=(w/2);
			int ne=(w/2);
			s1.insert({(w-ne)*num, {w, num}});
			if(v1.empty()){
				v1.pb(dec);
			}
			else{
				v1.pb(dec+v1.back());
			}
			
		}
		
		while(sc2>0){
			auto it=s2.end();
			it--;
			int dec=(*it).f;
			int w=(*it).s.f;
			int num=(*it).s.s;
		
			sc2-=dec;
			s2.erase(s2.find((*it)));
			w=(w/2);
			int ne=(w/2);
			s2.insert({(w-ne)*num, {w, num}});
			if(v2.empty()){
				v2.pb(dec);
			}
			else{
				v2.pb(dec+v2.back());
			}
		}
		
		
		int totd=(tot-S);
		if(totd<=0){
			cout<<0<<endl;
			continue;
		}
		int mini=1e18;
		for(int i=0; i<v1.size(); i++){
			int ste=i;
			int rem=totd-v1[i];
			
			if(rem<=0){
				mini=min(mini, ste);
				continue;
			}
			int ind=lower_bound(v2.begin(), v2.end(), rem)-v2.begin();
			
			if(ind==v2.size()){
				continue;
			}
			mini=min(mini, ste+2*(ind));
		}
		cout<<mini<<endl;
	}
	return 0;
}