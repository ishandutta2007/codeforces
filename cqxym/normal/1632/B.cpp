#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n,m=1;
	cin>>n;
	while(m<<1<n){
		m<<=1;
	}
	for(R i=m-1;i!=-1;i--){
		cout<<i<<" ";
	}
	for(R i=m;i!=n;i++){
		cout<<i<<" ";
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