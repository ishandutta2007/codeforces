#include<bits/stdc++.h>
#define N 1000005
#define mod 998244353
#define int long long
using namespace std;

int a[N],b[N],n,m,g=3,ln,lim=1,l[N],r[N],inv,x,y,f[N],jc[N],c[N],d[N],iv[N],invl;

int qpw(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}	
	return ans;
}

void ntt(int *a,int tp){
	for(int i=0;i<lim;i++)
		if(i<r[i])swap(a[i],a[r[i]]);
	for(int i=1;i<lim;i<<=1){
		int omg=qpw(~tp?g:inv,mod/(i<<1));
		for(int j=0,w=1;j<lim;j+=i<<1,w=1)
			for(int k=0;k<i;k++,w=w*omg%mod)
				x=a[j+k],y=w*a[i+j+k]%mod,a[j+k]=(x+y)%mod,a[i+j+k]=(x-y+mod)%mod;
	}
	if(tp==-1)
		for(int i=0;i<lim;i++)
			a[i]=a[i]*invl%mod;
}

signed main(){
	scanf("%lld%lld",&n,&m),inv=qpw(g,mod-2),jc[0]=iv[0]=1;
	for(int i=0;i<=n;i++)
		scanf("%d",&f[i]);
	while(lim<=n*2)lim<<=1,ln++;
	for(int i=0;i<lim;i++)
		r[i]=(r[i>>1]>>1)|((i&1)<<ln-1);
	for(int i=1;i<=n;i++)
		jc[i]=jc[i-1]*i%mod,iv[i]=qpw(jc[i],mod-2);
	for(int i=0;i<=n;i++)
		a[i]=jc[n-i]*f[n-i]%mod,b[i]=iv[i];
	invl=qpw(lim,mod-2);
	ntt(a,1),ntt(b,1);
	for(int i=0;i<lim;i++)
		a[i]=a[i]*b[i]%mod;
	ntt(a,-1);
	for(int i=0;i<=n;i++)
		c[i]=a[i]*qpw(qpw(n-i+1,m),mod-2)%mod,
		d[i]=iv[i]*((i&1)?-1:1);
	ntt(c,1),ntt(d,1);
	for(int i=0;i<lim;i++)
		c[i]=c[i]*d[i]%mod;
	ntt(c,-1);
	for(int i=0;i<=n;i++)
		printf("%lld ",c[n-i]*iv[i]%mod);
	return 0;
}