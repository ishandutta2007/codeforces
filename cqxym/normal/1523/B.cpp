#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n,x;
	cin>>n;
	for(R i=n;i!=0;i--){
		cin>>x;
	}
	cout<<3*n<<endl;
	for(R i=1;i<n;i+=2){
		for(R j=0;j!=3;j++){
			cout<<"2 "<<i<<' '<<i+1<<endl<<"1 "<<i<<' '<<i+1<<endl;
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}