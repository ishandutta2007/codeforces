/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
const int N=500000;
int n;
int a[N+1];
int v1[N+1],v2[N+1];
int cnt[62];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++)v1[i]=v2[i]=0;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)for(int j=0;j<62;j++)cnt[j]+=a[i]>>j&1;
	for(int i=1;i<=n;i++)for(int j=0;j<62;j++)
		if(a[i]&1ll<<j){
			(v1[i]+=(1ll<<j)%mod*cnt[j])%=mod;
			(v2[i]+=(1ll<<j)%mod*n)%=mod;
		}
		else{
			(v2[i]+=(1ll<<j)%mod*cnt[j])%=mod;
		}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=v1[i]*v2[i]%mod;
	cout<<ans%mod<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}