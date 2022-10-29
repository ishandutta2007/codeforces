#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int po[30];

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	po[0]=1;
	for(int i=1; i<30; i++){
		po[i]=2*po[i-1];
	}
	while(t--){
		int n, k;
		cin>>n>>k;
		map<int, bool>np;
		string st;
		cin>>st;
		set<int>ones;
		for(int i=0; i<k; i++){
			if(st[i]=='0'){
				ones.insert(i);
			}
		}
		for(int i=k-1; i<st.size(); i++){
			if(ones.size()==0){
				np[0]=1;
			}
			else{
				auto it=ones.begin();
				int ind=(*it);
				if(i-ind>20){
					
				}
				else{
					int val=0;
					for(auto it:ones){
						val+=po[i-it];
					}
					np[val]=1;
				}
			}
			if(i==n-1){
				continue;
			}
			if(st[i+1]=='0'){
				ones.insert(i+1);
			}
			if(ones.find(i-k+1)!=ones.end()){
				ones.erase(i-k+1);
			}
		}
		int ans=-1;
		for(int i=0; i<1000005; i++){
			if(np[i]){
				continue;
			}
			ans=i;
			break;
		}
		vector<int>v;
		while(ans!=0){
			v.pb(ans%2);
			ans=ans/2;
		}
		while(v.size()<k){
			v.pb(0);
		}
		reverse(v.begin(), v.end());
		if(v.size()>k){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			for(auto u:v){
				cout<<u;
			}
			cout<<endl;
		}
	}
	return 0;
}