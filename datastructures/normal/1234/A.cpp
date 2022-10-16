#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[105],sum;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for (int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
		cout<<sum/n+(sum%n!=0)<<endl;
	}
	return 0;
}