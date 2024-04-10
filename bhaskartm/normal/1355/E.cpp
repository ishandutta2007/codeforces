#include <bits/stdc++.h>
using namespace std;
long long int n, a, r, m;
bool booly;
long long int arr[100005];
 
long long int f(long long int h){
	long long int toinc=0;
	long long int todec=0;
	for(int i=0; i<n; i++){
		if(arr[i]<h){
			toinc+=(h-arr[i]);
		}
		else{
			todec+=(arr[i]-h);
		}
	}
	if(booly==false){
		return toinc*a + todec*r;
	}
	long long int ans=0;
	ans=m*min(toinc, todec);
	if(toinc>todec){
		ans+=a*(toinc-todec);
	}
	else{
		ans+=r*(todec-toinc);
	}
	return ans;
}
 
int main() {
	cin>>n>>a>>r>>m;
	booly=false;
	if(m<a+r){
		booly=true;
	}
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	sort(arr, arr+n);
	long long int l=0;
	long long int h=arr[n-1];
	while(l<=h){
		long long int mid=(l+h)/2;
		long long int val1=f(mid-1);
		long long int val2=f(mid);
		long long int val3=f(mid+1);
		if(val1<val2 && val2<val3){
			h=mid-1;
			continue;
		}
		if(val1>val2 && val2>val3){
			l=mid+1;
			continue;
		}
		if(val1>val2 && val2<val3){
			cout<<val2;
			return 0;
		}
		if(val1==val2 || val2==val3){
			cout<<val2;
			return 0;
		}
	}
	return 0;
}