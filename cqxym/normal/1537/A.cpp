#include<iostream>
using namespace std;
inline void Solve(){
	int n,a,sum=0;
	cin>>n;
	for(register int i=0;i!=n;i++){
		cin>>a;
		sum+=a; 
	}
	if(sum<n){
		puts("1");
	}else{
		printf("%d\n",sum-n);
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