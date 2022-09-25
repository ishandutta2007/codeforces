#include <bits/stdc++.h>

#define ll long long int
 
using namespace std;

int main(){
	int q;
	cin >> q;
	ll sum,n,k;
	for(int i=0; i<q; i++){
		cin >> n;
		sum=0;
		for(int j=0; j<n; j++){
			cin >> k;
			sum=sum+k;
		}
		if(sum%n==0) sum=sum/n;
		else sum=sum/n+1;
		cout << sum << endl;
	}
	return 0;
}