#include<bits/stdc++.h>
using namespace std;
long long n;
vector<long long>pm;
int main(){
	cin>>n;
	for(long long i=2;i<=sqrt(n);i++){
		if(n%i==0)
			pm.push_back(i);
		while(n%i==0)n/=i;
	}
	if(pm.size()==0){
		cout<<n;
		return 0;
	}
	if(n!=pm.back()&&n!=1)pm.push_back(n);
	if(pm.size()<2)
		cout<<pm[0];
	else
		cout<<1;
}