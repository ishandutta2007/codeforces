#include <bits/stdc++.h>
using namespace std;
int lindex[1000005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0; i<1000005; i++){
		lindex[i]=-1;
	}
	long long int n, x;
	cin>>n>>x;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		lindex[arr[i]]=i;
	}
	int maxi=0;
	set<int>s;
	s.insert(arr[0]);
	for(int i=0; i<n; i++){
		auto it=s.end();
		it--;
		if((*it)>arr[i]){
			maxi=max(arr[i], maxi);
		}
		s.insert(arr[i]);
	}
	set<int>s2;
	s2.insert(arr[n-1]);
	int mini=1000005;
	for(int i=n-2; i>=0; i--){
		auto it=s2.begin();
		if(arr[i]>(*it)){
			mini=min(mini, arr[i]);
		}
		s2.insert(arr[i]);
	}
	if(maxi==0){
		cout<<(x*(x+1))/2<<endl;
		return 0;
	}
	int last=-1;
	int pointer=maxi;
	long long int ans=0;
	
	set<int>s3;
	for(int i=1; i<=mini; i++){
		ans=ans+(x-pointer+1);
		
		int val=lindex[i];
		if(val>last){
			for(int j=max(0, last); j<=val; j++){
				s3.insert(arr[j]);
			}
			last=val;
		}
		if(s3.empty()){
			continue;
		}
		auto it=s3.end();
		it--;
		if((*it)>pointer){
			pointer=(*it);
		}
	}

	cout<<ans;
	return 0;
}