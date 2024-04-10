#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'
int arr[200005];

bool f(int val, int start, int end, int cnt){
	vector<int>v;
	for(int i=start; i<=end; i++){
		if(v.size()==0){
			if(arr[i]<=val){
				v.pb(i);
			}
		}
		else{
			if(v.back()!=i-1 && arr[i]<=val){
				v.pb(i);
			}
		}
	}
	return (v.size()>=cnt);
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int mini1=1e10;
	int mini2=1e10;
	int lo=1;
	int hi=1e10;
	
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(k%2==1){
			if(f(mid, 0, n-1, (k+1)/2)){
				hi=mid-1;
				mini1=mid;
			}
			else{
				lo=mid+1;
			}
		}
		else{
			
			if(f(mid, 0, n-2, (k/2))){
				hi=mid-1;
				mini1=mid;
			}
			else{
				lo=mid+1;
			}
		}
	}
	lo=1;
	hi=1e10;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(k%2==1){
			if(f(mid, 1, n-2, (k/2))){
				mini2=mid;
				hi=mid-1;
			}
			else{
				lo=mid+1;
			}
		}
		else{
			if(f(mid, 1, n-1, (k/2))){
				mini2=mid;
				hi=mid-1;
			}
			else{
				lo=mid+1;
			}
		}
	}
	
	cout<<min(mini1, mini2)<<endl;
	return 0;
}