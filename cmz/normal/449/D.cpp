#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int mod=1e9+7;
int fac[maxn],ifac[maxn];
inline int power(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) res=1ll*res*a%mod;
	return res;
}
inline int lowbit(int x){return x&(-x);}
int n,a[maxn],f[maxn],g[30],Ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),f[a[i]]++;
	for (int i=0;i<20;++i)
		for (int j=0;j<maxn;++j) 
		if (j&(1<<i)) f[j^(1<<i)]+=f[j];
	for (int i=0;i<maxn;++i){
		int len=0,cur=i;
		while (cur){cur-=lowbit(cur);++len;}
		g[len]=(g[len]+power(2,f[i])-1)%mod;
	}
	for (int i=0;i<20;++i){
		int sgn=(i%2==0)?1:mod-1;
		Ans=(Ans+1ll*sgn*g[i])%mod;
	}
	printf("%d\n",Ans);
	return 0;
}