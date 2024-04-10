#include<iostream>
using namespace std;
inline void Solve(){
	int n,k;
	cin>>n>>k;
	k--;
	if((n&1)==1){
		int t=n>>1;
		k=k/t*(t+1)+k%t;
	}
	k=(k+1)%n;
	cout<<(k==0?n:k)<<endl;
}
int main(){
	int t;
	cin>>t;
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}