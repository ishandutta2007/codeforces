#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
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
int n,p[200005],sum[200005],ans;
struct Seg{
	int l,r;
}a[200005];
Seg seg_merge(Seg a,Seg b){
	Seg c;
	c.l=max(a.l,b.l);
	c.r=min(a.r,b.r);
	return c; 
}
int len(Seg a){
	if (a.l>a.r)return 0;
	return a.r-a.l+1;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)a[i].l=read();
	for (int i=1;i<=n;i++)a[i].r=read();
	p[1]=sum[1]=1;
	for (int i=2;i<=n;i++){
		int awalen=len(seg_merge(a[i],a[i-1]));
		p[i]=(mod+1-awalen*inv(len(a[i])*len(a[i-1])%mod)%mod)%mod;
		ans=(ans+p[i]*sum[i-2])%mod;
		sum[i]=(sum[i-1]+p[i])%mod;
		if (i==2){
			int qwqlen=len(seg_merge(a[i],a[i-1]));
			int qwqp=(mod+1-qwqlen*inv(len(a[i])*len(a[i-1])%mod)%mod)%mod;
			ans=(ans+qwqp)%mod;
		}
		if (i>=3){
			int qwqlen=len(seg_merge(a[i],seg_merge(a[i-1],a[i-2])));
			int qwqp=1;
			qwqp=(qwqp+2*mod-(mod+1-p[i-1]))%mod;
			qwqp=(qwqp+2*mod-(mod+1-p[i]))%mod;
			qwqp=(qwqp+qwqlen*inv(len(a[i])*len(a[i-1])%mod*len(a[i-2])%mod))%mod;
			ans=(ans+qwqp)%mod;
		}
	}
	ans=ans*2%mod;
	for (int i=1;i<=n;i++)ans=(ans+p[i])%mod;
	cout<<ans<<endl;
	return 0;
}