#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+5;
int n,m;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		int s=0;
		for(i=1;i<=n;i++){
			s+=a[i];
			if(s==m) break;
		}
		if(i==n){
			cout<<"NO"<<endl;
			continue;
		}
		else if(i<n) swap(a[i],a[i+1]);
		cout<<"YES"<<endl;
		for(i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}