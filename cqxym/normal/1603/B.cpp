#include<iostream>
using namespace std;
inline void Solve(){
	int x,y;
	cin>>x>>y;
	if(x==y){
		cout<<x<<endl;
	}else if(x>y){
		cout<<x+y<<endl;
	}else{
		int q=(y-2)/x;
		cout<<(q*x+y>>1)<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}