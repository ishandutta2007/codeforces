#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
ll mx;
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		ll x;cin>>x;
		cout<<mx+x<<" ";
		if(x>0) mx+=x;
	}
	return 0;
}