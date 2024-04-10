#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define poly vector<int>
const int o=3e5,MOD=998244353;
inline int fix(int x){return x+(x>>31&MOD);}
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int n,a[o],fac[o],w[o],bt,rev[o],s[o],cnt,Ans;
inline void init(){
	bt=18;
	w[1<<(bt-1)]=1;
	for(int i=(1<<(bt-1)),j=qp(3,(MOD-1)/(1<<bt));i<(1<<bt);++i) w[i+1]=w[i]*1ll*j%MOD;
	for(int i=(1<<(bt-1));--i;) w[i]=w[i<<1];
}
inline void ntt(poly&a,int n,bool inv){
	for(int i=1;i<n;++i) if(rev[i]<i) swap(a[rev[i]],a[i]);
	for(int md=1;md<n;md<<=1) for(int i=0;i<n;i+=md<<1) for(int j=0,x,y;j<md;++j)
		x=a[i+j],y=a[i+j+md]*1ll*w[j+md]%MOD,a[i+j]=fix(x+y-MOD),a[i+j+md]=fix(x-y);
	if(inv) for(int i=1,j=n-1;i<j;swap(a[i++],a[j--]));
}
poly mul(poly a,poly b){
	for(bt=1;(1ull<<bt)<a.size()+b.size()-1;++bt);
	if((1<<bt)<32){
		poly res(a.size()+b.size()-1);
		for(int i=a.size();i--;) for(int j=b.size();j--;) res[i+j]=(res[i+j]+a[i]*1ll*b[j])%MOD;
		return res;
	}
	a.resize(1<<bt);b.resize(1<<bt);
	for(int i=1;i<(1<<bt);++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bt-1));
	ntt(a,1<<bt,0);ntt(b,1<<bt,0);
	for(int i=0;i<(1<<bt);++i) a[i]=a[i]*1ll*b[i]%MOD;
	ntt(a,1<<bt,1);
	for(int i=0,j=qp(1<<bt,MOD-2);i<(1<<bt);++i) a[i]=a[i]*1ll*j%MOD;
	for(;a.size()>1ull&&!a.back();a.pop_back());
	return a;
}
struct dp{
	poly f[2][2];bool flg;
	dp(int len){
		for(int i=0;i<2;++i) for(int j=0;j<2;++j) f[i][j]=poly(1,0);
		if(len<2) flg=1,f[0][0][0]=1;
		else flg=0,f[1][1][0]=2;
	}
	dp(const dp&a,const dp&b){
		flg=0;
		for(int l1=0,coef,l,r;l1<2;++l1) for(int r1=0;r1<2;++r1) for(int l2=0;l2<2;++l2) for(int r2=0;r2<2;++r2){
			poly t=mul(a.f[l1][r1],b.f[l2][r2]);
			if(f[l1][r2].size()<t.size()) f[l1][r2].resize(t.size());
			for(int i=t.size();i--;) f[l1][r2][i]=fix(f[l1][r2][i]+t[i]-MOD);
			if(l2&&r1) coef=(MOD+1)/2;
			else if(l2||r1) coef=1;
			else coef=2;
			l=(l1||a.flg);r=(r2||b.flg);
			if(f[l][r].size()<=t.size()) f[l][r].resize(t.size()+1);
			for(int i=t.size();i--;) f[l][r][i+1]=(f[l][r][i+1]+t[i]*1ll*coef)%MOD;
		}
	}
};
dp calc(int l,int r){
	if(l==r) return dp(s[l]);
	int md=l+r>>1;
	return dp(calc(l,md),calc(md+1,r));
}
int main(){
	scanf("%d",&n);init();
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;i+=a[i]){
		s[++cnt]=a[i];
		if(i+a[i]-1>n){printf("0");return 0;}
		for(int j=i;j<i+a[i];++j) if(a[j]^a[i]){printf("0");return 0;}
	}
	dp ans=calc(1,cnt);
	for(int i=fac[0]=1;i<=cnt;++i) fac[i]=fac[i-1]*1ll*i%MOD;
	for(int i=0;i<2;++i) for(int j=0;j<2;++j)
		for(int k=ans.f[i][j].size();k--;) Ans=(Ans+ans.f[i][j][k]*1ll*fac[cnt-k]%MOD*((k&1)?(MOD-1):1))%MOD;
	printf("%d",Ans);
	return 0;
}