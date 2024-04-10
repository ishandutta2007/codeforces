#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7; 
int n,K;
string s;
ll inv[100004],cnt[100004];
void init(){
	cnt[0]=1;
	inv[1]=1;
	for (int i=2;i<=n;i++)	
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	inv[0]=1;
	for(int i=1;i<=n;i++)inv[i]=inv[i-1]*inv[i]%MOD,cnt[i]=cnt[i-1]*i%MOD;
}
ll C(ll a,ll b){
	if(a<b)return 0;
	return cnt[a]*inv[b]%MOD*inv[a-b]%MOD;
}
ll ans=0,d[100004];
int main(){
	cin>>n>>K>>s;
	init();
	ll cur=1;
	for(int i=n-1;i;i--)d[i]=(d[i+1]+cur*C(i-1,K-1))%MOD,cur=cur*10%MOD;
    cur=1;
	for(int i=n;i>=K+1;i--)d[i]=(d[i]+cur*C(i-1,K))%MOD,cur=cur*10%MOD;
	for(int i=n;i;i--)ans=(ans+d[i]*(s[i-1]-'0'))%MOD;
	cout<<ans;
}