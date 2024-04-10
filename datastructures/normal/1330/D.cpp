#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int t,d,mod,num[35],f[35];
signed main(){
	cin>>t;
	while(t--){
		cin>>d>>mod;
		memset(num,0,sizeof(num));
		memset(f,0,sizeof(f));
		for (int i=0;i<=30;i++){
			if ((1ll<<(i+1))>d)num[i]=max(0ll,d-(1ll<<i)+1);
			else num[i]=(1ll<<i);
			num[i]%=mod; 
		}
		int ans=0;
		for (int i=0;i<=30;i++){
			f[i]=num[i];
			for (int j=0;j<i;j++)
				f[i]=(f[i]+num[i]*f[j])%mod;
			ans=(ans+f[i])%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}