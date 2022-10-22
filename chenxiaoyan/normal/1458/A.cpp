/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,m;
int a[N+1],b[N+1];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=m;i++)scanf("%lld",b+i);
	sort(a+1,a+n+1);
	int ans=a[2]-a[1];
	if(n==1)ans=-1;
	for(int i=3;i<=n;i++)ans=gcd(ans,a[i]-a[1]);
	for(int i=1;i<=m;i++)printf("%lld ",ans==-1?a[1]+b[i]:gcd(a[1]+b[i],ans));
	return 0;
}