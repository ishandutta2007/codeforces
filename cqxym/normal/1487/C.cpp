#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n,b;
	cin>>n;
	for(R i=0;i!=n;i++){
		for(R j=i+1;j!=n;j++){
			b=j-i<<1;
			if(b==n){
				cout<<"0 ";
			}else if(b<n){
				cout<<"1 ";
			}else{
				cout<<"-1 ";
			}
		}
	}
	puts("");
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}