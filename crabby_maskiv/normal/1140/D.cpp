#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400005;
const int K=200000;
const ll inf=0x3f3f3f3fll;
int n,m;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	ll ans=0;
	cin>>n;
	for(i=2;i<n;i++)
		ans+=i*(i+1);
	cout<<ans;
	return 0;
}