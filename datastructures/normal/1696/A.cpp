#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[1000005],z;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>z;
		for (int i=1;i<=n;i++)cin>>a[i];
		int mx=0;
		for (int i=1;i<=n;i++)mx=max(mx,(a[i]|z));
		cout<<mx<<endl;
	}
	return 0;
}