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
	int n;
	cin>>n;
	int arr[n];
	int tot=0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		tot+=arr[i];
	}
	int val[n];
	val[n-1]=arr[n-1];
	for(int i=n-2; i>=0; i--){
		val[i]=max(arr[i], val[i+1]+1);
	}
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=val[i];
	}
	int mini=sum;
	for(int i=1; i<n; i++){
		sum-=val[i-1];
		val[i-1]=arr[i-1];
		if(i!=1){
			val[i-1]=max(val[i-1], 1+val[i-2]);
		}
		sum+=val[i-1];
		sum-=val[i];
		val[i]=max(val[i], 1+val[i-1]);
		sum+=val[i];
		mini=min(mini, sum);
		
	}
	cout<<mini-tot;
	return 0;
}