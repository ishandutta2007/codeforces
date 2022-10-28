#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
#define f first
#define s second

main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	vector<pair<int, int>>v;
	for(int i=0; i<n; i++){
		v.pb({arr[i], i+1});
	}
	sort(v.begin(), v.end());
	
	int index=0;
	int pre[n+1];
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+v[i-1].f;
	}
	
	int mini=0;
	int ans=0;
	for(int i=0; i<n-k; i++){
		
		ans-=((pre[i+k]-pre[i+1])-(k-1)*(v[i].f));
			
		ans+=(k-1)*(v[i+k].f)-(pre[i+k]-pre[i+1]);
		
		if(ans<mini){
			index=i+1;
			mini=ans;
		}
	}
	for(int i=index; i<index+k; i++){
		cout<<v[i].s<<" ";
	}
	return 0;
}