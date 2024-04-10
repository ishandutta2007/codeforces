#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
int a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		ll sum=0;
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>a[i];sum+=a[i];
		}
		cout<<min(ll(m),sum)<<endl;
	}
	return 0;
}