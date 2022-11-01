#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
int a[200000];
inline void Solve(){
	int n,minI=1;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(R i=2;i!=n;i++){
		if(a[i]-a[i-1]<a[minI]-a[minI-1]){
			minI=i;
		}
	}
	cout<<a[minI-1];
	for(R i=minI+1;i!=n;i++){
		cout<<' '<<a[i];
	}
	for(R i=0;i!=minI-1;i++){
		cout<<' '<<a[i];
	}
	cout<<' '<<a[minI]<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}