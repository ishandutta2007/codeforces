#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	long long a,b,s=0,sum=0;
	cin>>a>>b;
	if(a>b){
		b=a-b;
	}else{
		b-=a;
	}
	while(sum<b||(sum-b&1)==1){
		s++;
		sum+=s;
	}
	cout<<s<<endl;
}
int main(){
	int n;
	cin>>n;
	for(R i=0;i<n;i++){
		Solve();
	}
	return 0;
}