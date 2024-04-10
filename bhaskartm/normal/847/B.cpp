#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int in[1005];
int l[1005];
int r[1005];
vector<vector<int>>adj;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	vector<vector<int>>v;
	vector<int>v1;
	v1.pb(arr[0]);
	v.pb(v1);
	int sz=1;
	for(int i=1; i<n; i++){
		if(v[sz-1].back()>arr[i]){
			vector<int>v2;
			v2.pb(arr[i]);
			v.pb(v2);
			sz++;
			continue;
		}
		int lo=0;
		int hi=sz-1;
		int ans=0;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			if(v[mid].back()<arr[i]){
				ans=mid;
				hi=mid-1;
			}
			else{
				lo=mid+1;
			}
		}
		v[ans].pb(arr[i]);
	}
	for(int i=0; i<v.size(); i++){
		for(auto u:v[i]){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}