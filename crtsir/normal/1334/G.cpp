#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,ggg=3,invggg=(mod+1)/ggg;
const int maxn=262144;
int tmp[maxn],F[maxn],G[maxn];
int mypow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		y>>=1;x=1ll*x*x%mod;
	}return ret;
}
int revs[maxn];
void initrev(int Len){
	for(int i=1;i<Len;++i){
		revs[i]=revs[i>>1]>>1;
		if(i&1)revs[i]|=(Len>>1);
	}
}
void DFT(int *f,int n,int rev){
	int g0=rev==1?ggg:invggg;
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
string s,t;
int p[26],ans[200003];
int main(){
	initrev(maxn);
	for(int i=0;i<26;i++)
		cin>>p[i],p[i]--;
	cin>>s>>t;
	reverse(s.begin(),s.end());
	for(int i=0;i<26;i++){
		memset(F,0,sizeof(F));
		memset(G,0,sizeof(G));
		for(int j=0;j<s.size();j++)
			if(s[j]==char('a'+i))
				F[j]=1;
		for(int j=0;j<t.size();j++)
			if(t[j]==char('a'+i)||t[j]==char('a'+p[i]))
				G[j]=1;
		DFT(F,maxn,1);
		DFT(G,maxn,1);
		for(int j=0;j<maxn;j++)
			F[j]=1ll*F[j]*G[j]%mod;
		DFT(F,maxn,-1);
		for(int j=s.size()-1;j<t.size();j++)
			ans[j]+=F[j];
	}
	for(int i=s.size()-1;i<t.size();i++)
		if(ans[i]==s.size())
			cout<<1;
		else
			cout<<0;
}