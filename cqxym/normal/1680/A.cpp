#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int l1,r1,l2,r2,l,r;
	cin>>l1>>r1>>l2>>r2;
	l=l1>l2?l1:l2;
	r=r1<r2?r1:r2;
	if(l>r){
		cout<<l1+l2<<endl;
	}else{
		cout<<l<<endl;
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