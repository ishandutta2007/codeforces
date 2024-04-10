#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

int val[400005];
int up[400005];
int mini[400005];
int maxi[400005];
int ans=0;
vector<int>v;

void f(int l, int r){
	vector<int>vecs;
	for(int i=l; i<=r; i++){
		vecs.pb(v[i]);
	}
	vector<int>v1;
	vector<int>v2;
	v1.pb(vecs[0]);
	for(int i=1; i<vecs.size(); i++){
		if(vecs[i]>v1.back() && v2.empty()){
			v2.pb(vecs[i]);
			continue;
		}
		if(v2.empty() && vecs[i]<v1.back()){
			v1.pb(vecs[i]);
			continue;
		}
		if(!v2.empty()){
			if(vecs[i]>v1.back() && vecs[i]>v2.back()){
				
			}
			if(vecs[i]<v1.back() && vecs[i]<v2.back()){
				if(v1.back()<v2.back()){
					v1.pb(vecs[i]);
				}
				else{
					v2.pb(vecs[i]);
				}
				continue;
			}
			if(vecs[i]<v1.back()){
				v1.pb(vecs[i]);
				continue;
			}
			else{
				v2.pb(vecs[i]);
			}
		}
	}
	int vals=0;
	for(auto u:v1){
		if(up[u]){
			vals++;
		}
	}
	for(auto u:v2){
		if(!up[u]){
			vals++;
		}
	}
	ans+=min(vals, r-l+1-vals);
	return;
}
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		int a, b;
		cin>>a>>b;
		if(a<=n && b<=n){
			cout<<-1;
			return 0;
		}
		if(a>b){
			swap(a, b);
			up[b]=1;
		}
		val[a]=b;
	}
	
	
	for(int i=1; i<=n; i++){
		v.pb(val[i]);
	}
	
	vector<int>v1;
	vector<int>v2;
	v1.pb(v[0]);
	for(int i=1; i<v.size(); i++){
		if(v[i]>v1.back() && v2.empty()){
			v2.pb(v[i]);
			continue;
		}
		if(v2.empty() && v[i]<v1.back()){
			v1.pb(v[i]);
			continue;
		}
		if(!v2.empty()){
			if(v[i]>v1.back() && v[i]>v2.back()){
				cout<<-1;
				return 0;
			}
			if(v[i]<v1.back() && v[i]<v2.back()){
				if(v1.back()<v2.back()){
					v1.pb(v[i]);
				}
				else{
					v2.pb(v[i]);
				}
				continue;
			}
			if(v[i]<v1.back()){
				v1.pb(v[i]);
				continue;
			}
			else{
				v2.pb(v[i]);
			}
		}
	}
	mini[0]=v[0];
	for(int i=1; i<n; i++){
		mini[i]=min(mini[i-1], v[i]);
	}
	maxi[n-1]=v[n-1];
	for(int i=n-2; i>=0; i--){
		maxi[i]=max(maxi[i+1], v[i]);
	}
	vector<int>di;
	di.pb(-1);
	for(int i=0; i<n-1; i++){
		if(mini[i]>maxi[i+1]){
			di.pb(i);
		}
	}
	di.pb(n-1);
	for(int i=0; i<di.size()-1; i++){
		f(di[i]+1, di[i+1]);
	}
	
	cout<<ans;
	return 0;
}