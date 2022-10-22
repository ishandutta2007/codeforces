/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
int a[N+1];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	a[0]=-1;
	for(int i=1;i<=n;i++)if(a[i]>a[i-1]+1)a[i]--;
	for(int i=1;i<=n;i++)ans+=a[i]!=a[i-1];
	cout<<ans<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}