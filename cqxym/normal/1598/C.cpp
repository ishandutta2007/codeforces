#include<iostream>
#include<map> 
using namespace std;
#define R register int
int a[200000];
inline void Solve(){
	int n,x;
	cin>>n;
	long long sum=0,ans=0;
	for(R i=0;i!=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum<<=1;
	if(sum%n!=0){
		cout<<0<<endl;
		return;
	}
	x=sum/n;
	map<int,int>Q;
	for(R i=0;i!=n;i++){
		ans+=Q[x-a[i]];
		Q[a[i]]++; 
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