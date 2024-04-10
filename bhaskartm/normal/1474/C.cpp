#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n=2*n;
		int arr[n];
		
		for(int i=0; i<n; i++){
			cin>>arr[i];
			
		}

		sort(arr, arr+n);
		bool ch=1;
		multiset<int>se;
		for(int i=0; i<n-1; i++){
			if(ch==0){
				break;
			}
			int x=arr[i]+arr[n-1];
			vector<pair<int, int>>v;
			int xx=x;
			se.clear();
			for(int j=0; j<n; j++){
				se.insert(arr[j]);
			}

			se.erase(se.find(arr[n-1]));
			se.erase(se.find(arr[i]));
			bool che=1;
			v.pb({arr[n-1], arr[i]});
			x=arr[n-1];
			while(1){
				if(se.empty()){
					break;
				}
				auto it=se.end();
				it--;
				int val=(*it);
				int val2=x-val;
				se.erase(se.find(val));
				
				if(se.find(val2)==se.end()){
					che=0;
					break;
				}
				else{
					v.pb({val, val2});
					
					se.erase(se.find(val2));
					x=val;
				}
			}
			if(che){
				cout<<"YES"<<endl;
				cout<<xx<<endl;
				for(auto u:v){
					cout<<u.f<<" "<<u.s<<endl;
				}
				ch=0;
			}
		}
		if(ch){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}