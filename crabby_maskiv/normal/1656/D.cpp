#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		ll n;cin>>n;
		ll x=1,y=n;
		while(y%2==0){
			y/=2;
			x*=2;
		}
		if(y==1) cout<<-1<<endl;
		else if(2*x<=y) cout<<x*2<<endl;
		else cout<<y<<endl;
	}
	return 0;
}