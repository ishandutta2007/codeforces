#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;

int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		ll x,y;cin>>x>>y;
		if(x>=y){
			cout<<"YES"<<endl;
			continue;
		}
		if(x==1) cout<<"NO"<<endl;
		else if(x==2||x==3){
			if(y==2||y==3) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	return 0;
}