#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>v1;
		vector<int>v2;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			if(x%2==0){
				v1.pb(x);
			}
			else{
				v2.pb(x);
			}
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int a1=0;
		int a2=0;
		int che=0;
		while(1){
			che=1-che;
			if(v1.empty() && v2.empty()){
				break;
			}
			if(che){
				if(v1.empty()){
					v2.pop_back();
					continue;
				}
				if(v2.empty()){
					a1+=v1.back();
					v1.pop_back();
					continue;
				}
				if(v1.back()>v2.back()){
					a1+=v1.back();
					v1.pop_back();
					continue;
				}
				else{
					v2.pop_back();
					continue;
				}
			}
			else{
				if(v1.empty()){
					a2+=v2.back();
					v2.pop_back();
					continue;
				}
				if(v2.empty()){
					v1.pop_back();
					continue;
				}
				if(v1.back()>v2.back()){
					v1.pop_back();
					continue;
				}
				else{
					a2+=v2.back();
					v2.pop_back();
				}
			}
		}
		if(a1>a2){
			cout<<"Alice"<<endl;
		}
		else if(a1==a2){
			cout<<"Tie"<<endl;
		}
		else{
			cout<<"Bob"<<endl;
		}
	}
	return 0;
}