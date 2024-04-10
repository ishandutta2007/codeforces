#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
ll n,m; 

int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	if(m*2>=n)
		cout<<0<<" ";
	else cout<<n-m*2<<" ";
	ll k;
	for(k=0;k<=n;k++)
		if(k*(k-1)/2>=m) break;
	cout<<n-k;
	return 0;
}