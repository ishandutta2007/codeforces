#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
ll a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		ll x=0,s=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			s+=a[i];
			x^=a[i];
		}
		cout<<2<<endl<<x<<" "<<s+x<<endl;
	}
	return 0;
}