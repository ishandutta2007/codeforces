#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=505;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){x-=MOD,x+=((x>>31)&MOD); }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int fac[N],inv[N],ifac[N],comb[N][N];
struct II{
	II(){
		for(int i=0;i<N;++i){
			comb[i][0]=1;
			for(int j=1;j<=i;++j)
				mo(comb[i][j]=comb[i-1][j]+comb[i-1][j-1]);
		}
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__ii;
vector<int> shl(vector<int> a){
	a.insert(a.begin(),0);
	return a;
}
int f[N][N];
vector<int> solve4(int n){
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			for(int k=1;k<=j;++k)
				f[i][j]=(f[i][j]+1ll*f[i-1][j-k]*comb[j-1][k-1]%MOD*fac[k-1]%MOD*comb[j][k]%MOD*fac[k])%MOD;
	}
	vector<int> ret(n+1);
	for(int i=0;i<=n;++i) ret[i]=f[i][n];
//	printf("<%d>",n);
//	for(auto x:ret) printf("{%d}",x);
	return ret;
}
vector<int> solve3(int a,int b,int c){
//	printf("|%d %d %d|",a,b,c);
	if(a<b) swap(a,b);
	if(a==0) return solve4(c);
	vector<int> f=solve3(a-1,b,c);
	f.push_back(0);
	for(int i=(int)f.size()-1;i>=0;--i)
		f[i]=(1ll*f[i]*(a+c-1)+(i>0?f[i-1]:0))%MOD;
	return f;
}
vector<int> solve2(vector<int> p,vector<int> q){
	map<int,int> mp; int a=0,b=0,c=0;
	for(int i=0;i<p.size();++i){
		if(p[i]==0&&q[i]==0) ++c;
		else if(p[i]==0) ++a;
		else ++b;
		mp[p[i]]++; mp[q[i]]++;
	}
	for(auto x:mp) if(x.first!=0&&x.second>1) --a,--b,++c;
	return solve3(a,b,c);
}
vector<int> solve1(vector<int> p,vector<int> q){
//	for(auto x:p) printf("[%d]",x); puts("");
//	for(auto x:q) printf("<%d>",x); puts("");
	for(int i=0;i<p.size();++i){
		if(p[i]!=0&&q[i]!=0){
			if(p[i]==q[i]){
				p.erase(p.begin()+i);
				q.erase(q.begin()+i);
				return shl(solve1(p,q));
			}else{
				for(int j=0;j<p.size();++j)
					if(p[j]==q[i]) p[j]=p[i];
				p.erase(p.begin()+i);
				q.erase(q.begin()+i);
				return solve1(p,q);
			}
		}
	}
	return solve2(p,q);
}
int main(){
	int n; scanf("%d",&n);
	vector<int> p(n),q(n);
	for(int i=0;i<n;++i) scanf("%d",&p[i]);
	for(int i=0;i<n;++i) scanf("%d",&q[i]);
	vector<int> f=solve1(p,q);
	for(int i=n;i>=1;--i){
		if(i>=f.size()) printf("0 ");
		else printf("%d ",f[i]);
	}
	return 0;
}