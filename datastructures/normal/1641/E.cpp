#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
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
	t=1ll*t*t%mod;
	if (p&1)t=1ll*t*a%mod;
	return t;
}
int f[1000005],g[1000005],h[1000005];
int tr[1000005];
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
void ntt(int *f,int n,int fg){//fg=0:dft fg=1:idft
	for (int i=0;i<n;i++){
		if (i&1)tr[i]=tr[i/2]/2+n/2;
		else tr[i]=tr[i/2]/2;
	}
	for (int i=0;i<n;i++)
		if (i<tr[i])swap(f[i],f[tr[i]]);
	for (int len=2;len<=n;len*=2){
		int w1;
		if (fg==0)w1=Qpow(3,(mod-1)/len);
		if (fg==1)w1=Qpow(3,(mod-1)-(mod-1)/len);
		for (int i=0;i<n;i+=len){
			int w=1;
			for (int j=i;j<i+len/2;j++){
				int qwq=1ll*w*f[j+len/2]%mod;
				f[j+len/2]=f[j]+mod-qwq;
				if (f[j+len/2]>=mod)f[j+len/2]-=mod;
				f[j]=f[j]+qwq;
				if (f[j]>=mod)f[j]-=mod;
				w=1ll*w*w1%mod;
			}
		}
	}
	return;
}
void mul(int l1,int l2,int *f,int *g,int *h){
	int n=1;
	while(n<=(l1+l2))n*=2;
	if (n<=200){
		for (int i=0;i<=l1+l2;i++)h[i]=0;
		for (int i=0;i<=l1;i++)
			for (int j=0;j<=l2;j++)
				upd(h[i+j],1ll*f[i]*g[j]%mod);
		for (int i=0;i<n;i++)f[i]=g[i]=0;
		return;
	}
	ntt(f,n,0);
	ntt(g,n,0);
	for (int i=0;i<n;i++)h[i]=1ll*f[i]*g[i]%mod;
	ntt(h,n,1);
	int invn=Qpow(n,mod-2);
	for (int i=0;i<n;i++)h[i]=1ll*h[i]*invn%mod;
	for (int i=0;i<n;i++)f[i]=g[i]=0;
	return;
}
int t,n,m,x,s[300005],a[300005],pre[300005],suf[300005];
int val1[300005],val2[300005],val3[300005],val4[300005];
void work(int l,int r){
	if (l==r)return;
	if (l>2*n||r<n)return;
	int mid=(l+r)/2;
	for (int i=l;i<=mid;i++)f[i-l]=(s[i]==1)*pre[i-1];
	for (int i=mid+1;i<=r;i++)g[i-(mid+1)]=suf[i];
	mul(mid-l,r-(mid+1),f,g,h);
	for (int i=0;i<=r-l;i++)
		if ((i+l+mid+1)%2==0)upd(val1[(i+l+mid+1)/2],h[i]);
	for (int i=l;i<=mid;i++)f[i-l]=1ll*(s[i]==1)*pre[i-1]*i%mod;
	for (int i=mid+1;i<=r;i++)g[i-(mid+1)]=suf[i];
	mul(mid-l,r-(mid+1),f,g,h);
	for (int i=0;i<=r-l;i++)
		if ((i+l+mid+1)%2==0)upd(val2[(i+l+mid+1)/2],h[i]);
	for (int i=l;i<=mid;i++)f[i-l]=pre[i-1];
	for (int i=mid+1;i<=r;i++)g[i-(mid+1)]=1ll*(s[i]==1)*suf[i+1]*i%mod;
	mul(mid-l,r-(mid+1),f,g,h);
	for (int i=0;i<=r-l;i++)
		if ((i+l+mid+1)%2==0)upd(val3[(i+l+mid+1)/2],h[i]);
	for (int i=l;i<=mid;i++)f[i-l]=pre[i-1];
	for (int i=mid+1;i<=r;i++)g[i-(mid+1)]=(s[i]==1)*suf[i+1];
	mul(mid-l,r-(mid+1),f,g,h);
	for (int i=0;i<=r-l;i++)
		if ((i+l+mid+1)%2==0)upd(val4[(i+l+mid+1)/2],h[i]);
	work(l,mid);
	work(mid+1,r);
	return;
}
int main(){
	cin>>n>>m;
	for (int i=n+1;i<=2*n;i++)a[i]=read();
	for (int i=1;i<=m;i++){
		x=read();
		s[n+x]=1;
	}
	pre[0]=1;
	for (int i=1;i<=3*n;i++){
		pre[i]=pre[i-1];
		if (s[i]==1)pre[i]=pre[i]*2%mod;
	}
	suf[3*n+1]=1;
	for (int i=3*n;i>=1;i--){
		suf[i]=suf[i+1];
		if (s[i]==1)suf[i]=suf[i]*2%mod;
	}
	work(1,3*n);
	int ans=0;
	for (int i=n+1;i<=2*n;i++){
		int qwq=1ll*i*a[i]%mod;
		ans=(ans+1ll*qwq*val1[i])%mod;
		qwq=mod-a[i];
		ans=(ans+1ll*qwq*val2[i])%mod;
		qwq=a[i];
		ans=(ans+1ll*qwq*val3[i])%mod;
		qwq=mod-1ll*i*a[i]%mod;
		ans=(ans+1ll*qwq*val4[i])%mod;
	}
	int awa=1;
	for (int i=1;i<=m;i++)awa=awa*2%mod;
	awa--;
	cout<<1ll*ans*Qpow(awa,mod-2)%mod<<endl;
	return 0;
}