#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

const int dzh=998244353,maxn=10000005;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int N,Q;int p[maxn],cnt;
int fac[10005],ifac[10005],inv[10005];
int pri[maxn],len;map<int,int> M;
int init(){
	int n=N;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0){
			pri[++len]=i;
			while(n%i==0) n/=i;
		}
	if(n!=1) pri[++len]=n;
}
int calc(int n){
	int ans=1,tot0=0;
	for(int i=1;i<=len;i++)
		if(n%pri[i]==0){
			int tot1=0;
			while(n%pri[i]==0)tot1++,tot0++,n/=pri[i];
			ans=1LL*ans*ifac[tot1]%dzh;
		}
	int tot1=0;
	if(n!=1) tot0++,tot1++;
	return 1LL*fac[tot0]*ifac[tot1]%dzh*ans%dzh;
}
void getP(int n){
	for(int i=1;i<=sqrt(n);i++)
		if(n%i==0){
			p[++cnt]=i;
			if(i*i!=n) p[++cnt]=n/i;
		}
}
signed main(){
	fac[1]=fac[0]=ifac[1]=ifac[0]=inv[1]=1;
	for(int i=2;i<=10000;i++){
		fac[i]=1LL*fac[i-1]*i%dzh;
		inv[i]=1LL*(dzh-dzh/i)*inv[dzh%i]%dzh;
		ifac[i]=1LL*ifac[i-1]*inv[i]%dzh;
	}
	scanf("%lld%lld",&N,&Q);
	init();
	getP(N);
	for(int i=1;i<=cnt;i++) M[p[i]]=calc(p[i]);
	while(Q--){
		int x,y,d;scanf("%lld%lld",&x,&y);d=gcd(x,y);
		printf("%lld\n",1ll*M[x/d]*M[y/d]%dzh);
	}
}