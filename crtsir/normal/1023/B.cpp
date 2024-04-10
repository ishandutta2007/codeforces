#include<bits/stdc++.h>
using namespace std;
long long maxv,minv;
int main(){
	long long n,k;
	cin>>k>>n;
	if(k*2<=n){
		cout<<0;
		return 0;
	}
	k=min(k,n-1);
	maxv=k;minv=max(0ll,n-k);
	cout<<max(0ll,(maxv-minv+1)/2);
}