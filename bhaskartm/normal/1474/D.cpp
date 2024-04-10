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
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		if(n==2){
			if(arr[0]==arr[1]){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
			continue;
		}
		int pre[n];
		pre[0]=0;
		int val=arr[0];
		for(int i=1; i<n-1; i++){
			if(pre[i-1]==-1){
				pre[i]=-1;
				continue;
			}
			pre[i]=val;

			if(val<0){
				pre[i]=-1;
				continue;
			}
			val=arr[i]-val;
		}
		int suf[n];
		suf[n-1]=0;
		val=arr[n-1];
		for(int i=n-2; i>0; i--){
			if(suf[i+1]==-1){
				suf[i]=-1;
				continue;
			}
			suf[i]=val;
			if(val<0){
				suf[i]=-1;
				continue;
			}
			val=arr[i]-val;
		}
		bool che=0;
		for(int i=0; i<n-1; i++){
			if(pre[i]==-1 || suf[i+1]==-1){
				continue;
			}
			
			if(pre[i]+arr[i+1]==suf[i+1]+arr[i] && arr[i]>=pre[i] && arr[i+1]>=suf[i+1] ){
				che=1;
				
				break;
			}
			if(pre[i]+arr[i]==suf[i+1]+arr[i+1] && arr[i+1]>=pre[i] && arr[i]>=suf[i+1]){
				che=1;
				break;
			}
		}
		
		if(che){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}