#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		cout<<"? 1 "<<i<<endl;
		cin>>a[i];
	}
	cout<<"? 2 3"<<endl;cin>>a[1];
	int H=(a[2]+a[3]-a[1])/2;
	cout<<"! "<<H;for(int i=2;i<=n;i++)cout<<' '<<a[i]-H;cout<<endl;
	return 0;
}