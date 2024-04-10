#include<bits/stdc++.h>

using namespace std;

const int maxn=5005;
const long long mdn=998244353;

long long ksm(long long bse,int ex){
	if(!ex)return 1;
	long long ans=ksm(bse,ex>>1);ans=(ans*ans)%mdn;
	if(ex&1)ans=(ans*bse)%mdn;
	return ans;
}

long long dp[maxn][maxn];
int cnt[maxn];
int pfx[maxn];
int a[maxn];
long long sfx[maxn][maxn];
int n;
long long inv[maxn];

int main(){
	for(int i=1;i<maxn;i++)inv[i]=ksm(i,mdn-2);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	for(int i=1;i<=n;i++)pfx[i]=pfx[i-1]+cnt[i];
	for(int i=n;i>=1;i--){
		int lst=pfx[i-1];
		for(int j=lst;j>=0;j--){
			if(n-j-1>0&&cnt[i])dp[i][j]=(((sfx[i+1][j+1]+max(0,cnt[i]-1))%mdn)*inv[n-j-1])%mdn;
			//cout<<i<<j<<":"<<dp[i][j]<<endl;
		}
		for(int j=0;j<=n;j++) sfx[i][j]=(sfx[i+1][j]+(dp[i][j]*cnt[i])%mdn) %mdn; 
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[a[i]][0];
		ans%=mdn;
	} 
	cout<<(ans*ksm(n,mdn-2))%mdn;
	return 0;
}