#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define pb push_back

 main() {
 	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int mid=(n/2);
	vector<int>f;
	int point=n-1;
	while(point>mid){
		f.pb(point);
		point-=m;
	}
	vector<int>b;
	int point2=0;
	while(point2<mid){
		b.pb(point2);
		point2+=m;
	}
	int ans=0;
	for(auto u:f){
		ans+=(2*(arr[u]-arr[mid]));
	}
	for(auto u:b){
		ans+=(2*(arr[mid]-arr[u]));
	}
	cout<<ans;
	return 0;
}