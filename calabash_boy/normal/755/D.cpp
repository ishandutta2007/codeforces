#include<iostream>
using namespace std;
int main(){
	int n,k;
	long long ans=1;
	int temp=1;
	long long newans=1;
	cin>>n>>k;
	if (2*k>n){
		k=n-k;
	}
	for (int i=1;i<=n;i++){
		temp+=k;
		if (temp>n){
			temp-=n;
			newans+=2;
			ans--;
		}
		ans+=newans;
		if (i==n){
			ans--;
		}
		cout<<ans<<' ';
	}
	return 0;
}