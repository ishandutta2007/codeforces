#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
int n,m;
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		if(n%m) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}