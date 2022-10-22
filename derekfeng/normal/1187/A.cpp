#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while (t--){
		long long n,s,t;cin>>n>>s>>t;
		long long b=s+t-n;
		long long o=max(s,t)-b;
		cout<<o+1<<"\n";
	}
}