/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;
const int N=200000;
int n;
int a[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int mn=inf;
	for(int i=1;i<n;i++)mn=min(mn,a[i+1]-a[i]);
	int cnt=0;
	for(int i=1;i<n;i++)cnt+=a[i+1]-a[i]==mn;
	cout<<mn<<" "<<cnt;
	return 0;
}