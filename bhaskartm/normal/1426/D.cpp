#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


int f(int n, int x){
	if(n<=x){
		return 0;
	}
	n--;
	return (n/x);
}

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
	int pre[n+1];
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=arr[i-1]+pre[i-1];
	}
	map<int, int>la;
	int las[n+1];
	for(int i=0; i<=n; i++){
		la[pre[i]]=-1;
	}
	for(int i=0; i<=n; i++){
		las[i]=la[pre[i]];
		la[pre[i]]=i;
	}
	int curr=-2;
	int ans=0;
	
	
	for(int i=0; i<=n; i++){
		if(las[i]==-1){
			continue;
		}
		if(las[i]<curr){
			continue;
		}
		ans++;
		curr=i-1;
	}
	cout<<ans;
	return 0;
}