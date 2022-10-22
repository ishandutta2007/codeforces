#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];a[i]+=a[i-1];
	}
	for(i=1;i<=n;i++) cout<<(a[i]/m)-(a[i-1]/m)<<" ";
	return 0;
}