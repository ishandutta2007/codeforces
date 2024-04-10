#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
int a[100];
inline void Solve(){
	int n,ans=1;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(R i=1;i!=n;i++){
		if(a[i]!=a[i-1]){
			break;
		}
		ans++;
	}
	cout<<n-ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}