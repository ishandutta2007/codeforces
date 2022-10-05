#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef long long ll;
 
const int N=5005,mod=998244353;
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
	//	vi now=BM(x);
	//	for(auto k:now)
	//		printf("%d\n",k);
	//	cerr<<now.size()<<endl;
		return solve(BM(x),x,K);
	}
}
 
int main(){
	int n;
	while(cin>>n){
		cout<<LS::gao(
{
0,
0,
24,
4,
240,
204,
1316,
2988,
6720,
26200,
50248,
174280,
436904,
1140888,
3436404,
8348748,
24631232,
64575924,
174658944,
488230244,
282739095,
583167773,
599201163,
111178790,
470158977,
118436480,
744170002,
418128853,
620410921,
282515603,
777785540,
59207630,
823529776,
886871858,
80677633,
874800287,
754269413,
659807497,
302870971,
307001715
},
		n-1)<<endl;
	}
	return 0;
}