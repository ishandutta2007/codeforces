#include<iostream>
using namespace std;
#define R register int
int a[300000];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	if(a[0]<a[n-1]){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}