/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
int n;
bool ne[N+1];
bool Xor[N+1];
int cnt[N+2];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ne[i]=x<0;
		Xor[i]=Xor[i-1]^ne[i];
	}
	for(int i=n;~i;i--)cnt[i]=cnt[i+1]+Xor[i];
//	for(int i=1;i<=n;i++)cout<<Xor[i]<<" "<<cnt[i]<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++)ans+=Xor[i-1]?cnt[i]:(n-i+1)-cnt[i];
	cout<<n*(n+1)/2-ans<<" "<<ans;
	return 0;
}