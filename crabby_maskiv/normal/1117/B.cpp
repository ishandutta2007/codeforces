#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n;ll m,k;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(k==1){
		cout<<((m+1)/2)*a[n]+(m/2)*a[n-1];
		return 0;
	}
	cout<<(m/(k+1))*k*a[n]+(m/(k+1))*a[n-1]+(m%(k+1))*a[n];
	return 0;
}