#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
int a[100],b[100];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(R i=0;i!=n;i++){
		cin>>b[i];
	}
	sort(b,b+n);
	for(R i=0;i!=n;i++){
		if(a[i]!=b[i]&&a[i]!=b[i]-1){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}