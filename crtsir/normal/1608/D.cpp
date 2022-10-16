#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,ggg=3,invggg=(mod+1)/ggg,maxn=262144;
int revs[maxn];
void initrev(int Len){
	for(int i=1;i<Len;++i){
		revs[i]=revs[i>>1]>>1;
		if(i&1)revs[i]|=(Len>>1);
	}
}
long long mypow(long long x,int y){
	long long ret=1;
	while(y){
		if(y&1)ret=ret*x%mod;
		y>>=1;x=x*x%mod;
	}return ret;
}
void DFT(int *f,int n,int rev){
	int g0=rev==1?ggg:invggg;
	initrev(n);
	for(register int i=0;i<n;++i)
		if(i<revs[i])
			f[i]^=f[revs[i]]^=f[i]^=f[revs[i]];
	for(register int h=2;h<=n;h<<=1){
		int gn=mypow(g0,(mod-1)/h);
		for(register int j=0;j<n;j+=h){
			int gk=1;
			for(register int k=j;k<j+(h>>1);++k){
				int e=f[k],o=1ll*gk*f[k+(h>>1)]%mod;
				f[k]=(e+o)%mod,f[k+(h>>1)]=(e+mod-o)%mod;
				gk=1ll*gk*gn%mod;
			}
		}
	}
	if(rev==-1){
		int invv=mypow(n,mod-2);
		for(register int i=0;i<n;++i)
			f[i]=1ll*f[i]*invv%mod;
	}
}
bool ok1=1,ok2=1;
int n,cnt[8];
int F[maxn],G[maxn],H[maxn],W[maxn],pw=1;
string s;
int check(string s1,string s2){
	for(int i=0;i<2;i++)
		if(s1[i]!=s2[i]&&s2[i]!='?')
			return 0;
	return 1;
}
int fac[200003],inv[200003];
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	cin>>n;
	fac[0]=1;
	for(int i=1;i<200003;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<200003;i++)inv[i]=mypow(fac[i],mod-2);
	for(int i=0;i<n;i++){
		cin>>s;
		if(!check("WB",s))ok1=0;
		if(!check("BW",s))ok2=0;
		int nw=0;
		if(check("BB",s))nw+=4;
		if(check("BW",s)||check("WB",s))nw+=2;
		if(check("WW",s))nw+=1;cnt[nw]++;
		pw=pw*(check("BW",s)+check("WB",s))%mod;
	}
	F[cnt[2]+2*cnt[4]+cnt[6]]=1; 
	DFT(F,maxn,1);
	for(int i=0;i<=cnt[3]+cnt[6]+2*cnt[7];i++)
		G[i]=C(cnt[3]+cnt[6]+2*cnt[7],i);
	DFT(G,maxn,1);
	for(int i=0;i<maxn;i++)
		F[i]=1ll*F[i]*G[i]%mod; 
	DFT(F,maxn,-1);
	int ans=(F[n]+ok1+ok2-pw)%mod;
	if(ans<0)ans+=mod;
	cout<<ans;
	//1: 
	//2:*(x^cnt[2])
	//3:*(x+1)^cnt[3]
	//4:*(x^(2cnt[4]))
	//5: 
	//6:*(x2+x)^cnt[6]
}