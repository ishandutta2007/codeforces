#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,t;
	cin>>n>>k>>t;
	if (t<=k){
		cout<<t<<endl;
		return 0;
	}
	if (t<=n){
		cout<<k<<endl;
		return 0;
	}
	cout<<k-t+n<<endl;
	return 0;
}