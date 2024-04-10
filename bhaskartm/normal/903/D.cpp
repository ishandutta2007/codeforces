#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	int n;
	cin>>n;
	long double arr[n];
	map<long double, int>m;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		m[arr[i]]++;
	}
	long double pre[n+1];
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+arr[i-1];
	}
	long double sumi=0;
	for(int i=0; i<n-1; i++){
		m[arr[i]]--;
		long double sum=pre[n]-pre[i+1]-(n-i-1)*arr[i];
		sum-=(m[arr[i]+1]);
		sum+=(m[arr[i]-1]);
		sumi+=sum;
	}
	cout<<fixed<<setprecision(0)<<sumi;
	return 0;
}