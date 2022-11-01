#include<iostream>
using namespace std;
#define R register int
int a[100];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
		if((i&1)==0^a[i]>0){
			a[i]=-a[i];
		}
	}
	for(R i=0;i!=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}