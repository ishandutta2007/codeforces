#include <iostream>
#include <cstdio>
#include <algorithm> 
#define mod 1000000007
#define int long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,a[1000005],pw[1000005],c[2000005],ans;
signed main(){
	pw[0]=1;
	for (int i=1;i<=1000000;i++)pw[i]=pw[i-1]*2%mod;
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=read(),c[a[i]]++;
	for (int i=0;i<20;i++)
		for (int j=0;j<(1<<20);j++)
			if ((j&(1<<i))==0)c[j]+=c[j^(1<<i)];
	for (int i=0;i<(1<<20);i++){
		int cnt=0;
		for (int j=0;j<20;j++)
			if (i&(1<<j))cnt++;
		if (cnt&1)ans=(ans+mod-pw[c[i]])%mod;
		else ans=(ans+pw[c[i]])%mod;
	}
	cout<<ans<<endl;
	return 0;
}