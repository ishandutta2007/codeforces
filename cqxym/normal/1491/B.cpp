#include<iostream>
using namespace std;
#define R register int
int a[100];
inline void Solve(){
	int n,u,v;
	cin>>n>>u>>v;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	bool tag=true;
	for(R i=1;i!=n;i++){
		if(a[i]!=a[0]){
			tag=false;
			break;
		}
	}
	if(tag==true){
		cout<<v+min(u,v)<<endl;
	}else{
		for(R i=1;i!=n;i++){
			if(a[i]<a[i-1]-1||a[i-1]<a[i]-1){
				cout<<0<<endl;
				return;
			}
		}
		cout<<min(u,v)<<endl;
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