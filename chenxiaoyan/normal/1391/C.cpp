/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n;
int main(){
	cin>>n;
	int ans1=1,ans2=1;
	for(int i=1;i<=n;i++)ans1=1ll*ans1*i%mod;
	for(int i=1;i<n;i++)(ans2<<=1)%=mod;
	cout<<((ans1-ans2)%mod+mod)%mod;
	return 0;
}