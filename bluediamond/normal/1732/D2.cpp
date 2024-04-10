#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rng(228);
#else
  mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

signed main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	
	int t;
	cin>>t;
	vector<pair<int,ll>> ops(t);
	set<ll> ever;
	map<ll,int> mx;
	for(int i=0;i<t;i++){
		string s;
		ll x;
		cin>>s>>x;
		assert(s=="+"||s=="-"||s=="?");
		int type;
		if(s=="+")type=1;
		if(s=="-")type=0;
		if(s=="?")type=2;
		ops[i]={type, x};
		if(s=="+"){
			ever.insert(x);
		}
		if(s=="?"){
			if(!mx.count(x))mx[x]=1;
			while(ever.count(x*mx[x])){
				mx[x]++;
			}
		}
	}
	map<ll, set<int>> nope;
	map<ll, vector<ll>> w;
	for(auto &it:mx){
		for(int j=1;j<=it.second;j++){
			nope[it.first].insert(j);
			w[it.first*j].push_back(it.first);
		}
	}
	for(auto &it:ops){
		int type=it.first;
		ll x=it.second;
		if(type==0){
			for (auto &k:w[x]){
				nope[k].insert(x/k);
			}
		}
		if(type==1){
			for (auto &k:w[x]){
				nope[k].erase(x/k);
			}
		}
		if(type==2){
			assert(!nope[x].empty());
			cout<<x*(*nope[x].begin())<<"\n";
		}	
	}
	return 0;
}

 
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */