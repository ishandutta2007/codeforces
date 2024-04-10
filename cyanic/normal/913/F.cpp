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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

namespace{
	const int mod=998244353;
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
	void sub(int &x,int y){
		x=(x-y<0?x-y+mod:x-y);
	}
}

const int N=2005;
int f[N][N],g[N],h[N],P[N],Q[N];
int n,a,b,p,q;

int S(int i,int j){
	return ((ll)j*(i-j)+(ll)j*(j-1)/2)%mod;
}

int main(){
	read(n),read(a),read(b);
	p=mul(a,power(b,mod-2));
	q=fix(mod+1-p);
	P[0]=Q[0]=1;
	rep(i,1,n){
		P[i]=mul(P[i-1],p);
		Q[i]=mul(Q[i-1],q);
	}
	f[0][0]=1;
	rep(i,0,n-1)rep(j,0,i){
		add(f[i+1][j],mul(f[i][j],P[j]));
		add(f[i+1][j+1],mul(f[i][j],Q[i-j]));
	}
	g[1]=1;
	rep(i,2,n){
		g[i]=1;
		rep(j,1,i-1) sub(g[i],mul(g[j],f[i][j]));
	}
	rep(i,2,n){
		rep(j,1,i-1){
			int prob=mul(g[j],f[i][j]);
			add(h[i],mul(prob,fix(h[j]+h[i-j])+S(i,j)));
		}
		int owo=g[i];
		add(h[i],mul(owo,S(i,i)));
		h[i]=mul(h[i],power(fix(mod+1-owo),mod-2));
	}
	cout<<h[n]<<endl;
	return 0;
}