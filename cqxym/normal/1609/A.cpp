#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
int a[15];
inline void Solve(){
	int n;
	cin>>n;
	long long s=1;
	for(R i=0;i!=n;i++){
		cin>>a[i];
		while((a[i]&1)==0){
			a[i]>>=1;
			s<<=1;
		}
	}
	sort(a,a+n);
	s*=a[n-1];
	for(R i=n-2;i!=-1;i--){
		s+=a[i];
	}
	cout<<s<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}