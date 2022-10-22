/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100;
int n;
int a[N+1];
void mian(){
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	cout<<(sum+n-1)/n<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}