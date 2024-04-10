#include <bits/stdc++.h>

using namespace std;

long long int pow(int a, long long int b, int mod){
	long long int y=1;
	long long int z=a%mod;
	while(b>0){
		if(b%2==1){
			y=(y*z)%mod;
			b--;
		}
		b=b/2;
		z=(z*z)%mod;
	}
	return y;
}

int main(){
	long long int product=1;
	long long int m,n;
	int x;
	cin >> x >> n;
	int t=1e9+7;
	vector<long long int> prime;
	for(int i=2; i<=sqrt(x); i++){
		if(x%i==0) prime.push_back(i);
		while(x%i==0) x=x/i;
	}
	if(x!=1) prime.push_back(x);
	for(int i=0; i<prime.size(); i++){
		m=n;
		while(m>0){
			product=(product*pow(prime.at(i),m/(prime.at(i)),t))%t;
			m=m/prime.at(i);
		}
	}
	cout << product << endl;
	return 0;
}