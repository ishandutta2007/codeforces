#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
int a[50];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n<<1;i++){
		cin>>a[i];
	}
	sort(a,a+(n<<1));
	for(R i=0;i!=n;i++){
		cout<<a[i]<<' '<<a[i+n]<<' ';
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}