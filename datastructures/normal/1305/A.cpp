#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[10005],b[10005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		for (int i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for (int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
		for (int i=1;i<=n;i++)cout<<b[i]<<' ';cout<<endl;
	}
	return 0;
}