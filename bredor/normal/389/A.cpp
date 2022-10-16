#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<math.h>
using namespace std;

long gcd(long a, long b){
	if (a*b == 0)return (a + b);
	if (a > b)return gcd(a%b, b);
	if (a < b)return gcd(a, b%a);
}

int main(){

	 long a,b,n;

	 cin>>n;

	 vector<long>v;
	 v.resize(n);
	 for(long i = 0; i<n; ++i)cin>>v[i];

	 long GCD = v[0];
	 for(long i = 1; i<n; ++i)GCD = gcd(GCD, v[i]);

	 cout<<n*GCD;

	return 0;
}