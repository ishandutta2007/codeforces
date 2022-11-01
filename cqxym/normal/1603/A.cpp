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
	while(n!=0){
		int p=0;
		for(R i=n;i!=0;i--){
			if(a[i]%(i+1)!=0){
				p=i;
				break;
			}
		}
		if(p==0){
			cout<<"NO"<<endl;
			return;
		}
		for(R i=p;i!=n;i++){
			a[i]=a[i+1];
		}
		n--;
	}
	cout<<"YES"<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}