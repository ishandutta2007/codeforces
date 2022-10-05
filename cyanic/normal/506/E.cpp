#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef long long ll;
 
const int N=5005,mod=1e4+7;
namespace {
	inline int add(int x,int y){
		return x+y>=mod?x+y-mod:x+y;
	}
	inline void Add(int &x,int y){
		x=add(x,y);
	}
	inline int mnu(int x,int y){
		return x-y<0?x-y+mod:x-y;
	}
	inline int mul(int x,int y){
		return (ll)x*y%mod;
	}
	inline int power(int x,ll p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	#define inv(x) power(x,mod-2)
}
namespace LS{
	/*
	note:
	
	a[i]=\sum a[i-j-1]*r[j]
	a[0]..a[sz-1]
	*/
	int p[N],d[N],m;vi s[N];
	vi BM(vi a){
		int n=a.size();
		for(;m;)s[m--].clear();
		REP(i,n){
			d[i]=a[i];
			REP(j,s[m].size())
				d[i]=mnu(d[i],mul(a[i-j-1],s[m][j]));
			if(!d[i])continue;
			p[m]=i;
			if(!m){s[++m].resize(i+1);continue;}
			int id=m-1;
			REP(j,m-1)
				id=(p[j]-s[j].size()>p[id]-s[id].size()?j:id);
			int coef=mul(d[i],inv(d[p[id]]));
			s[++m].resize(i-p[id]-1);
			s[m].pb(coef);
			REP(j,s[id].size())
				s[m].pb(mul(mod-coef,s[id][j]));
			REP(j,s[m-1].size())
				if(j<s[m].size())s[m][j]=add(s[m][j],s[m-1][j]);
				else s[m].pb(s[m-1][j]);
		}
		return s[m];
	}
	const ll Mod=(ll)mod*mod*8;
	#define fix(x) (x>=Mod?x-=Mod:0);
	int A[N],B[N],bin[N],res[N],n;
	inline void Mul(int *x,int *y){
		static ll t[N<<1];
		rep(k,0,n*2-2)t[k]=0;
		REP(i,n)REP(j,n)
			t[i+j]+=(ll)x[i]*y[j],fix(t[i+j]);
		per(i,n*2-2,n){
			t[i]%=mod;
			REP(j,n)t[i-j-1]+=t[i]*A[j],fix(t[i-j-1]);
			t[i]=0;
		}
		REP(i,n)x[i]=t[i]%mod;
	}
	int solve(vi a,vi b,ll K){
		n=a.size();
		if(K<=n-1)return b[K];
		if(n==1)return mul(b[0],power(a[0],K));
		REP(i,n){
			bin[i]=res[i]=0;
			A[i]=a[i],B[i]=b[i];
		}
		bin[1]=res[0]=1;
		for(K-=n-1;K;K>>=1,Mul(bin,bin))
			if(K&1)Mul(res,bin);
		rep(i,n,n*2-2){
			B[i]=0;
			REP(j,n)B[i]=add(B[i],mul(B[i-j-1],A[j]));
		}
		int s=0;
		REP(i,n)s=add(s,mul(B[n-1+i],res[i]));
		return s;
	}
	int gao(vi x,ll K){
		return solve(BM(x),x,K);
	}
}
const int M=205;
int dp[M*4][M][M],done[M*4];
int len,n,m;
char s[M];
vi ans;
 
int main(){
	scanf("%s%d",s+1,&n);
	len=strlen(s+1),m=len*8+5;
	dp[0][1][len]=1;
	rep(i,1,len*4+5){
		done[i]=(ll)done[i-1]*26%mod;
		rep(l,1,len)rep(r,l,len)
			if(s[l]==s[r]){
				if(l+1>r-1)Add(done[i],dp[i-1][l][r]);
				else Add(dp[i][l+1][r-1],dp[i-1][l][r]);
				Add(dp[i][l][r],mul(dp[i-1][l][r],25));
			}
			else{
				Add(dp[i][l+1][r],dp[i-1][l][r]);
				Add(dp[i][l][r-1],dp[i-1][l][r]);
				Add(dp[i][l][r],mul(dp[i-1][l][r],24));
			}
	}
	ans.resize(m+1);
	rep(i,1,m)
		if(i&1){
			ans[i]=mul(done[i/2],26);
			rep(j,1,len)
				Add(ans[i],dp[i/2][j][j]);
		}
		else ans[i]=done[i/2];
	cout<<LS::gao(ans,n+len)<<endl;
	return 0;
}