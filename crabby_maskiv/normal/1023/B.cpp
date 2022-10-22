#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353;

int main(){
//	freopen("07.in","r",stdin);
//	freopen("test.out","w",stdout);
	int i,j;
	ll n,m;
	cin>>n>>m;
	if(n+n-1<m){
		cout<<0;
		return 0;
	}
	if(n+1>=m){
		if(m&1) cout<<m/2;
		else cout<<m/2-1;
	}
	else{
		cout<<(n+n-m+1)/2;
	}
	return 0;
}