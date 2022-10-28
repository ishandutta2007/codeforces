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
		int arr[n];
		vector<int>pos;
		vector<int>neg;
		
		int z=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			if(arr[i]==0){
				z++;
				continue;
			}
			if(arr[i]>0){
				pos.pb(arr[i]);
			}
			else{
				neg.pb(arr[i]);
			}
		}
		int ps=pos.size();
		int ns=neg.size();
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());
		if(n==5){
			
			int ans=1;
			for(int i=0; i<n; i++){
				ans=ans*arr[i];
				
				continue;
			}
			cout<<ans<<endl;
			continue;
		}
		if(pos.size()+neg.size()<5){
			cout<<0<<endl;
			continue;
		}
		int val1=-1e18;
		int val2=-1e18;
		int val3=-1e18;
		if(pos.size()+neg.size()==5 && (ns%2)==1){
			cout<<0<<endl;
			continue;
		}
		if(ps==0 && z!=0){
			cout<<0<<endl;
			continue;
		}
		if(ps==0 && z==0){
			int ans=1;
			for(int i=ns-1; i>=ns-5; i--){
				ans=ans*neg[i];
			}
			cout<<ans<<endl;
			continue;
		}
		
		if(ps>=1 && ns>=4){
			int ans=1;
			ans=pos.back();
			for(int i=0; i<4; i++){
				ans=ans*neg[i];
			}
			
			val1=ans;
			
		}
		if(ps>=3 && ns>=2){
			int ans=1;
			for(int i=ps-1; i>=ps-3; i--){
				ans=ans*pos[i];
			}
			for(int i=0; i<2; i++){
				ans=ans*neg[i];
			}
			val2=ans;
		}
		if(ps>=5){
			int ans=1;
			for(int i=ps-1; i>=ps-5; i--){
				ans=ans*pos[i];
			}
			val3=ans;
		}
		int maxi=val1;
		maxi=max(maxi, val2);
		maxi=max(maxi, val3);
		cout<<maxi<<endl;
	}
	return 0;
}