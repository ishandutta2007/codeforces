/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200000,M=1000;
int n,m;
int a[N+1];
int b[M];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[a[i]%m]++;
	for(int i=0;i<m;i++)if(b[i]>1)return puts("0"),0;
	int ans=1;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)(ans*=abs(a[i]-a[j])%m)%=m;
	cout<<ans;
	return 0;
}