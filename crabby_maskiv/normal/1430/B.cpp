#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
int a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		ll sum=0;
		for(i=n;i>=n-m;i--) sum+=a[i];
		cout<<sum<<endl;
	}
	return 0;
}