#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

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
	for(int i=0; i<n; i++){
		if(arr[i]>i+1){
			cout<<-1;
			return 0;
		}
	}
	int ans[n];
	for(int i=0; i<n; i++){
		ans[i]=-1;
	}
	int maxi=arr[n-1];
	set<int>se;
	for(int i=0; i<maxi; i++){
		se.insert(i);
	}
	if(arr[0]==1){
		ans[0]=0;
		se.erase(0);
	}
	for(int i=1; i<n; i++){
		if(arr[i]!=arr[i-1]){
			ans[i]=arr[i-1];
			se.erase(arr[i-1]);
		}
	}
	int pointer=0;
	while(!se.empty()){
		while(ans[pointer]!=-1){
			pointer++;
		}
		auto it=se.begin();
		int val=(*it);
		ans[pointer]=val;
		se.erase(val);
	}
	for(int i=0; i<n; i++){
		if(ans[i]==-1){
			ans[i]=1000000;
		}
	}
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}