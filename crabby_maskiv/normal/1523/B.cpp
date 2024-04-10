#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,k;
int a[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		cout<<n*3<<endl;
		for(i=1;i<=n;i+=2){
			cout<<1<<" "<<i<<" "<<i+1<<endl;
			cout<<2<<" "<<i<<" "<<i+1<<endl;
			cout<<1<<" "<<i<<" "<<i+1<<endl;
			cout<<1<<" "<<i<<" "<<i+1<<endl;
			cout<<2<<" "<<i<<" "<<i+1<<endl;
			cout<<1<<" "<<i<<" "<<i+1<<endl;
		}
	}
	return 0;
}