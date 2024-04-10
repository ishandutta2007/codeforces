#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

namespace{
	const int mod=998244353;
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1) res=(ll)res*x%mod;
		return res;
	}
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
}

const int N=5005;
int f[N][N],fac[N],rev[N],ans[N],n;

int main(){
	read(n);

	fac[0]=1;
	rep(i,1,n){
		fac[i]=mul(fac[i-1],i);
	}
	rev[n]=power(fac[n],mod-2);
	per(i,n,1){
		rev[i-1]=mul(rev[i],i);
	}
	f[1][1]=1;
	rep(i,1,n) rep(j,1,i){
		add(f[i+1][j],mul(f[i][j],j));
		add(f[i+1][j+1],mul(f[i][j],i+1-j));
		add(ans[j],mul(f[i][j],rev[i]));
	}
	rep(i,1,n){
		ans[i]=mul(ans[i],fac[n]);
		printf("%d%c",ans[i]," \n"[i==n]);
	}
	
	return 0;
}