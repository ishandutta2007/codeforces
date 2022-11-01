#include<iostream>
using namespace std;
#define R register int
int a[101],ans[101];
inline int Query(int n){
	cout<<'?';
	for(R i=1;i<=n;i++){
		cout<<' '<<a[i];
	}
	cout<<endl;
	cin>>n;
	return n;
}
int main(){
	int n;
	cin>>n;
	for(R i=1;i!=n;i++){
		a[i]=1;
	}
	ans[n]=1;
	for(R i=2;i<=n;i++){
		a[n]=i;
		if(Query(n)==0){
			ans[n]=n+2-i;
			break;
		}
	}
	for(R i=1;i!=n;i++){
		a[i]=ans[n];
	}
	for(R i=1;i<=n;i++){
		if(ans[n]!=i){
			a[n]=i;
			ans[Query(n)]=i;
		}
	}
	cout<<'!';
	for(R i=1;i<=n;i++){
		cout<<' '<<ans[i];
	}
	cout<<endl;
	return 0;
}