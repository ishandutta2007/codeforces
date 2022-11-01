#include<iostream>
using namespace std;
#define R register int
int a[100];
inline void Solve(){
	int n,l,ct0,ct1,ans=0;
	cin>>n>>l;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	for(R i=0;i!=l;i++){
		ct0=ct1=0;
		for(R j=0;j!=n;j++){
			if((a[j]>>i&1)==0){
				ct0++;
			}else{
				ct1++;
			}
		}
		if(ct0<ct1){
			ans|=1<<i;
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}