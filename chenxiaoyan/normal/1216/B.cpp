/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int N=1000;
int n;
pair<int,int> a[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].X,a[i].Y=i;
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)ans+=a[i].X*(i-1)+1;
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)cout<<a[i].Y<<" ";
	return 0;
}