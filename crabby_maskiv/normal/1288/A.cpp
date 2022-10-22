#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		int l=1;
		int ans=1e9;
		while(l<=n&&l<=m){
			ans=min(ans,(m+l-1)/l+l-1);
			l=m/(m/l)+1;
		}
		if(ans<=n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}