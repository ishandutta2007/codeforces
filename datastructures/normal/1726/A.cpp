#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int mx=0,mn=1000000000;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]),mn=min(mn,a[i]);
		int x=max(mx-a[1],a[n]-mn);
		for (int i=1;i<n;i++)x=max(x,a[i]-a[i+1]);
		cout<<x<<endl;
	}
	return 0;
}