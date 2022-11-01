#include<iostream>
using namespace std;
#define R register int
int a[100001];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&(a[2]&1)==1){
		cout<<"-1\n";
		return;
	}
	bool tag=true;
	long long sum=0;
	for(R i=2;i!=n;i++){
		sum+=a[i]+1>>1;
		if(a[i]!=1){
			tag=false;
		}
	}
	if(tag==true){
		cout<<"-1\n";
	}else{
		cout<<sum<<endl;
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