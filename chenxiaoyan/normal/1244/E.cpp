/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100000;
int n,m;
int a[N+1];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2,j=n-1;i<=j;i++,j--)
		if(m>=(i-1)*((a[i]-a[i-1])+(a[j+1]-a[j])))m-=(i-1)*((a[i]-a[i-1])+(a[j+1]-a[j]));
		else return cout<<a[j+1]-a[i-1]-m/(i-1),0;
	cout<<max(0ll,a[n/2+1]-a[n/2]-m/(n/2));
	return 0;
}
/*1
3 3
7 12 8
*/