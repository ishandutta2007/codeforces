#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> v[100010];
set<pair<int,int> ,greater<pair<int,int> > > p;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,M;
		cin>>N>>M;
		for(int i=0;i<M;i++){
			int a,b;
			cin>>a>>b;
			v[a].insert(b);
			v[b].insert(a);
		}
		for(int i=2;i<=N;i++){
			if(v[1].find(i)!=v[1].end())p.insert({1,i});
			else p.insert({0,i});
		}
		int sol=0;
		vector<int> k;
		while(p.size()>0){
			set<pair<int,int> >::iterator it=p.end();
			it--;
			pair<int,int> o=*it;
			p.erase(o);
			sol+=o.first;
			for(auto x:p){
				if(x.first==0)break;
				if(v[o.second].find(x.second)==v[o.second].end()){
					k.push_back(x.second);
				}
			}
			for(int i=0;i<k.size();i++){
				p.erase({1,k[i]});
				p.insert({0,k[i]});
			}
			while(k.size())k.pop_back();
		}
		cout<<sol;
		return 0;
}