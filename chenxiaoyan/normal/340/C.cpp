/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x,int y){return y?gcd(y,x%y):x;}
const int N=100000;
int n;
int a[N+1];
int lss[N+1],le[N+1],grt[N+1],ge[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,ie;i<=n;i=ie+1){
		ie=i;while(ie+1<=n&&a[ie+1]==a[i])ie++;
		for(int j=i;j<=ie;j++)lss[j]=i-1,le[j]=ie,grt[j]=n-ie,ge[j]=n-i+1;
	}
//	for(int i=1;i<=n;i++)printf("%lld %lld %lld %lld\n",lss[i],le[i],grt[i],ge[i]);
	int ans=0;
	for(int i=1;i<=n;i++)ans+=(lss[i]+le[i])*a[i]-(ge[i]-1+grt[i])*a[i];
	cout<<ans/gcd(ans,n)<<" "<<n/gcd(ans,n);
	return 0;
}
/*1
3
2 3 5
*/