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
	cout<<"YES"<<endl;
	for(ll k=n;k<=m;k+=2){
		cout<<k<<" "<<k+1<<endl;
	}
	return 0;
}