#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	
	int n;
	cin>>n;
	int b[n];
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	int a[n];
	a[0]=b[0];
	int maxi=a[0];
	for(int i=1; i<n; i++){
		a[i]=maxi+b[i];
		maxi=max(maxi, a[i]);
	}
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}