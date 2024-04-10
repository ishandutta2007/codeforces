/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int mod=1000000007;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
int inv(int x){return qpow(x,mod-2);}
const int N=100000,A_I=100000;
int n;
int a[N+1];
int lwb[A_I+1];
vector<int> dsr[A_I+1];
int main(){
//	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),mx=max(mx,a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=mx;i++){
		lwb[i]=lwb[i-1]-1;
		while(lwb[i]+1<=n&&a[lwb[i]+1]<i)lwb[i]++;
		lwb[i]++;
	}
	for(int i=1;i<=mx;i++)for(int j=i;j<=mx;j+=i)dsr[j].pb(i);
	int ans=0;
	for(int i=1;i<=mx;i++){
		int prod=1;
		for(int j=0;j<dsr[i].size();j++){
			int l=lwb[dsr[i][j]],r=j+1==dsr[i].size()?n:lwb[dsr[i][j+1]]-1;
			prod=1ll*prod*qpow(j+1,r-l+1)%mod;
			if(j+1==dsr[i].size())(ans+=(prod-1ll*prod*inv(qpow(j+1,r-l+1))%mod*qpow(j,r-l+1)%mod)%mod)%=mod;
		}
//		cout<<ans<<"!\n";
	}
	cout<<(ans+mod)%mod<<"\n";
	return 0;
}