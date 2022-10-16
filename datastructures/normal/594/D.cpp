#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 1000000007
#define int long long
using namespace std;
int n,a[200005];
int m;
struct node{
	int l,r,id;
}d[1000005];
bool cmp(node a,node b){
	return a.l>b.l;
}
int ans[200005];
int lst[1000005];
int isp[1000005],p[1000005],tot,c[1000005];
int fac[1000005],invfac[1000005],inv[1000005];
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
struct BIT{
	int tree[1000005],maxn;
	BIT(){
		maxn=1000000;
		for (int i=0;i<=maxn;i++)tree[i]=1;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]=tree[pos]*val%mod,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=1;
		while(pos)ans=ans*tree[pos]%mod,pos-=lowbit(pos);
		return ans;
	}
}bit;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	isp[0]=isp[1]=1;
	for (int i=2;i<=1000000;i++){
		if (isp[i]==0)c[i]=i,p[++tot]=i;
		for (int j=1;j<=tot&&p[j]<=1000000/i;j++){
			isp[i*p[j]]=1;
			c[i*p[j]]=p[j];
			if (i%p[j]==0)break;
		}
	}
	fac[0]=1;
	for (int i=1;i<=1000000;i++)fac[i]=fac[i-1]*i%mod;
	invfac[1000000]=Qpow(fac[1000000],mod-2);
	for (int i=999999;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int i=1;i<=1000000;i++)inv[i]=invfac[i]*fac[i-1]%mod;
	cin>>m;
	for (int i=1;i<=m;i++)scanf("%lld%lld",&d[i].l,&d[i].r),d[i].id=i;
	sort(d+1,d+1+m,cmp);
	int j=1;
	for (int i=1;i<=1000000;i++)lst[i]=n+1;
	for (int i=n;i>=1;i--){
		bit.add(i,a[i]);
		int x=a[i];
		while(x>1){
			int w=c[x];
			bit.add(i,(w-1)*inv[w]%mod);
			bit.add(lst[w],w*inv[w-1]%mod);
			lst[w]=i;
			while(x>1&&x%w==0)x/=w;
		}
		while(j<=m&&d[j].l==i)ans[d[j].id]=bit.ask(d[j].r),j++;
	}
	for (int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}