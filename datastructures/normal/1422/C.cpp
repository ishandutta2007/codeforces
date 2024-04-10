#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 1000000007
using namespace std;
char s[100005];
int n,sum[100005],ans;
inline int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1); 
	for (int i=0;i<=100000;i++)
		sum[i]=(sum[i-1]+Qpow(10,i-1)*i%mod)%mod;
	for (int i=1;i<=n;i++)
		ans=(ans+(s[i]-'0')*(sum[n-i]+Qpow(10,n-i)*((i-1)*i/2%mod)%mod)%mod)%mod;
	cout<<ans<<endl;
	return 0;
}