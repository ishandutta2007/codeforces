#include<iostream>
using namespace std;
#define R register int
inline bool Check(int x){
	for(R i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int a[100];
inline void Solve(){
	int n,sum=0;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(Check(sum)==false){
		cout<<n<<endl;
		for(R i=0;i!=n;i++){
			cout<<i+1<<' ';
		}
	}else{
		cout<<n-1<<endl;
		int p;
		for(R i=0;i!=n;i++){
			if(Check(sum-a[i])==false){
				p=i;
				break;
			}
		}
		for(R i=0;i!=n;i++){
			if(i!=p){
				cout<<i+1<<' ';
			}
		}
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}