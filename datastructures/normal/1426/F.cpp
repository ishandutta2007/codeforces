#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std; 
inline int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2)t=t*a%mod;
	return t;
}
int n,pre[200005],nxt[200005];
char s[200005];
signed main(){
	cin>>n;
	scanf("%s",s+1);
	int num=0,cnt=0;
	for (int i=1;i<=n;i++){
		if (s[i]=='b'||s[i]=='?')pre[i]=num;
		if (s[i]=='?')num=num*3+Qpow(3,cnt),cnt++,num%=mod;
		if (s[i]=='a')num+=Qpow(3,cnt),num%=mod;
	}
	num=0,cnt=0;
	for (int i=n;i>=1;i--){
		if (s[i]=='b'||s[i]=='?')nxt[i]=num;
		if (s[i]=='?')num=num*3+Qpow(3,cnt),cnt++,num%=mod;
		if (s[i]=='c')num+=Qpow(3,cnt),num%=mod;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		ans+=pre[i]*nxt[i]%mod,ans%=mod;
	cout<<ans<<endl;
	return 0;
}