#include<bits/stdc++.h>
using namespace std;



int main() {
	int n, k;
	cin>>n>>k;
	long long int arr[n];
	for(int i; i<=n; i++){
		cin>>arr[i];
	}
	long long int suf[n];
	suf[n-1]=arr[n-1];
	for(int i=n-2; i>=0; i--){
		suf[i]=suf[i+1]+arr[i];
	}
	sort(suf+1, suf+n);
	
	long long int sum=0;
	for(int i=n-1; i>=n-k+1; i--){
		sum=sum+suf[i];
	}
	sum=sum+suf[0];
	cout<<sum;
	return 0;
}