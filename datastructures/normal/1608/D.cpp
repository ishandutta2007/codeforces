#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <set>
#define mod 998244353
#define int long long
using namespace std;
int n,cnt[9],fac[1000005],invfac[1000005];
char s[5];
int ans,x,y;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int inv(int x){
	return Qpow(x,mod-2);
}
int C(int n,int m){
	if (m<0||m>n)return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
signed main(){
	cin>>n;
	fac[0]=1;
	for (int i=1;i<=1000000;i++)fac[i]=fac[i-1]*i%mod;
	invfac[1000000]=inv(fac[1000000]);
	for (int i=999999;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		if (s[1]=='W'&&s[2]=='W')cnt[0]++,y-=2;
		if (s[1]=='W'&&s[2]=='B')cnt[1]++;
		if (s[1]=='B'&&s[2]=='W')cnt[2]++;
		if (s[1]=='B'&&s[2]=='B')cnt[3]++,y+=2;
		if (s[1]=='W'&&s[2]=='?')cnt[4]++,x++,y--;
		if (s[1]=='B'&&s[2]=='?')cnt[5]++,x++,y++;
		if (s[1]=='?'&&s[2]=='W')cnt[6]++,x++,y--;
		if (s[1]=='?'&&s[2]=='B')cnt[7]++,x++,y++;
		if (s[1]=='?'&&s[2]=='?')cnt[8]++,x+=2;
	}
	ans=C(x,(x+y)/2);
	if (cnt[0]+cnt[3]==0)ans=(ans+mod-Qpow(2,cnt[8]))%mod;
	if (cnt[0]+cnt[2]+cnt[3]+cnt[5]+cnt[6]==0)ans++;
	if (cnt[0]+cnt[1]+cnt[3]+cnt[4]+cnt[7]==0)ans++;
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}