#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define pb push_back
#define f first
#define s second
#define int long long int

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		set<int>one;
		set<int>z;
		for(int i=0; i<n; i++){
			if(s[i]=='0'){
				z.insert(i);
			}
			else{
				one.insert(i);
			}
		}
		
		int num=1;
		int ans[n];
		int iter=0;
		while(1){
			iter++;
			if(z.empty() && one.empty()){
				break;
			}
			if(z.empty()){
				auto it=one.begin();
				int nu=(*it);
				one.erase(nu);
				ans[nu]=num;
				num++;
				continue;
			}
			if(one.empty()){
				auto it=z.begin();
				int nu=(*it);
				z.erase(nu);
				ans[nu]=num;
				num++;
				continue;
			}
			vector<int>v0;
			vector<int>v1;
			int last=-1;
			if((*(one.begin()))<(*(z.begin()))){
				int ty=1;
				while(1){
					if(ty==0){
						auto it=z.upper_bound(last);
						if(it==z.end()){
							break;
						}
						v0.pb(*it);
						ty=1-ty;
						last=(*it);
						continue;
					}
					if(ty==1){
						auto it=one.upper_bound(last);
						if(it==one.end()){
							break;
						}
						v1.pb(*it);
						ty=1-ty;
						last=(*it);
						continue;
					}
				}
			}
			else{
				int ty=0;
				
				
				while(1){
					if(ty==0){
						auto it=z.upper_bound(last);
						if(it==z.end()){
							break;
						}
						v0.pb(*it);
						ty=1-ty;
						last=(*it);
						
						continue;
					}
					if(ty==1){
						auto it=one.upper_bound(last);
						if(it==one.end()){
							break;
						}
						v1.pb(*it);
						ty=1-ty;
						last=(*it);
						continue;
					}
				}
			}
			for(auto u:v0){
				ans[u]=num;
			}
			for(auto u:v1){
				ans[u]=num;
			}
			for(auto u:v0){
				z.erase(u);
			}
			for(auto u:v1){
				one.erase(u);
			}
			num++;
		}
		cout<<num-1<<endl;
		for(int i=0; i<n; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}