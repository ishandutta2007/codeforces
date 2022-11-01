#include<iostream>
#include<cmath>
using namespace std;
inline void Solve(){
	int n,t;
	cin>>n;
	t=sqrt(n-1<<1|1);
	cout<<(t-1>>1)<<endl;
}
int main(){
	int t;
	cin>>t;
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}