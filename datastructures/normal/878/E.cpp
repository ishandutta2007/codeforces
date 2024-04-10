#include <iostream>
#include <cstdio>
#define ll long long
#define mod 1000000007
#define maxn 1000000000
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=1ll*t*t%mod;
	if (p&1)t=1ll*t*a%mod;
	return t;
}
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int n,q,a[500005],l,r;
int pow_2[500005],invpow_2[500005],c[500005];
int pre[500005],f[500005][21],g[500005][21];
int getval(int l,int r){
	if (l>r)return 0;
	int val=c[r]-c[l-1];
	if (val<0)val+=mod;
	val=1ll*val*invpow_2[l-1]%mod;
	return val;
}
int getpre(int x){
	ll f=0;
	for (int i=x;i>=1;i--){
		f=2*f+a[i];
		if (f<=0)return i;
		if (f>=maxn)return 0;
	}
	return 0;
}
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)a[i]=read();
	pow_2[0]=1;
	for (int i=1;i<=n;i++)pow_2[i]=pow_2[i-1]*2%mod;
	invpow_2[0]=1;
	for (int i=1;i<=n;i++)invpow_2[i]=1ll*invpow_2[i-1]*(mod+1)/2%mod;
	for (int i=1;i<=n;i++)c[i]=(c[i-1]+1ll*a[i]*pow_2[i]%mod+mod)%mod;
	for (int i=1;i<=n;i++)pre[i]=getpre(i);
	for (int i=1;i<=n+1;i++){
		f[i][0]=pre[i-1];
		if (pre[i-1]>0){
			g[i][0]=getval(pre[i-1],i-1);
			for (int j=1;j<=20;j++){
				f[i][j]=f[f[i][j-1]][j-1];
				g[i][j]=g[i][j-1];
				upd(g[i][j],g[f[i][j-1]][j-1]);
			}
		}
	}
	while(q--){
		l=read(),r=read();
		int x=r+1,ans=0;
		for (int i=20;i>=0;i--)
			if (f[x][i]>l)upd(ans,g[x][i]),x=f[x][i];
		upd(ans,getval(l+1,x-1));
		if (a[l]<0)upd(ans,a[l]+mod);
		else upd(ans,a[l]);
		printf("%d\n",ans);
	}
}