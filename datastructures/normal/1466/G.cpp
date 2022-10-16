#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define mod 1000000007
#define base 31
#define ull unsigned long long
using namespace std;
ull base_pow[2000005];
struct StringStructures{
	int n;
	string s;
	vector<ull> hs;
	void init(string t){
		s=t;
		n=t.size();
		hs.clear();
		ull nowval=0;
		for (int i=0;i<n;i++){
			nowval=nowval*base+t[i]-'a'+1;
			hs.push_back(nowval);
		}
		return;
	}
	ull getval(int l,int r){
		if (l>r)return 0;
		if (l==0)return hs[r];
		return hs[r]-hs[l-1]*base_pow[r-l+1];
	}
	ull preval(int len){
		return getval(0,len-1);
	}
	ull sufval(int len){
		return getval(n-len,n-1);
	}
}c[25],d;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=1ll*t*t%mod;
	if (p&1)t=1ll*t*a%mod;
	return t;
}
int inv(int x){
	return Qpow(x,mod-2);
}
int n,tot,q,k,val[100005][26];
string s0,t,r;
int getval(int l,int r,int c){
	int ans=val[r][c]-val[l-1][c];
	if (ans<0)ans+=mod;
	return 1ll*ans*Qpow(2,r)%mod;
}
int main(){
	ios::sync_with_stdio(false);
	base_pow[0]=1;
	for (int i=1;i<=2000000;i++)base_pow[i]=base_pow[i-1]*base;
	cin>>n>>q;
	cin>>s0>>t;
	c[tot].init(s0);
	while(tot<n&&c[tot].n<1000000){
		s0=s0+t[tot]+s0;
		++tot;
		c[tot].init(s0);
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<26;j++)val[i][j]=val[i-1][j];
		val[i][t[i-1]-'a']=(val[i][t[i-1]-'a']+Qpow((mod+1)/2,i))%mod;
	}
	while(q--){
		cin>>k>>r;
		d.init(r);
		int w=0;
		while(w<=tot&&c[w].n<r.size())w++;
		if (w>tot||w>k){
			puts("0");
			continue;
		}
		int ans=0;
		for (int i=0;i+r.size()-1<=c[w].n;i++)
			if (d.getval(0,r.size()-1)==c[w].getval(i,i+r.size()-1))ans++;
		ans=1ll*ans*Qpow(2,k-w)%mod;
		for (int i=0;i<r.size();i++)
			if (c[w].sufval(i)==d.preval(i)&&c[w].preval(r.size()-1-i)==d.sufval(r.size()-1-i))ans=(ans+getval(w+1,k,r[i]-'a'))%mod;
		printf("%d\n",ans);
	}
}