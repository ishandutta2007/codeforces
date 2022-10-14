#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long double n,k;
	cin>>n>>k;
	lli lo=0;
	lli hi=n;
	while(lo!=hi){
		long double mid=floor((lo+hi)/2);
		if((n-mid)*(n-mid+1)/(long double)2-mid<=k){
			hi=(lli)mid;
		}
		else{
			lo=(lli)mid+1;
		}
	}
	printf("%lli\n",(lli)lo);
	return 0;
}