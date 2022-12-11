#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int C[5010][5010];
void init(int x){
	rep(i,0,x){
		C[i][0]=1;
		rep(j,1,i)
			C[i][j]=upd(C[i-1][j]+C[i-1][j-1]-mod);
	}
}

int n,m;
int a[1<<11],b[1<<11],c[1<<11],d[1<<11];

int work1(int l){
	int r=m-l;
	//a[n+1]=0;
	per(i,2,n){
		a[i]=1LL*C[n-i+l][l]*C[i-1+l-1][l-1]%mod;
		//add(a[i],a[i+1]);
	}
	b[0]=0;
	rep(i,1,n-1){
		b[i]=1LL*C[i-1+r][r]*C[n-i+r-1][r-1]%mod;
		add(b[i],b[i-1]);
	}
	int z=0;
	rep(i,2,n) add(z,1LL*b[i-1]*a[i]%mod);
	return z;
}

int work2(int l){
	int r=n-l;
	rep(i,0,m-1){
		c[i]=C[l-1+i][i];
	}
	rep(i,1,m-1) add(c[i],c[i-1]);
	rep(i,2,m+1){
		d[i]=C[r-1+m-i+1][m-i+1];
	}
	per(i,2,m) add(d[i],d[i+1]);
	rep(i,2,m-1){
		a[i]=1LL*c[i-2]*C[l-1+m-i+1][m-i+1]%mod;
	}
	rep(i,2,m-1){
		b[i]=1LL*d[i+2]*C[r-1+i][i]%mod;
	}
	rep(i,3,m-1) add(a[i],a[i-1]);
	int z=0;
	rep(i,2,m-1) add(z,1LL*a[i]*b[i]%mod);
	return z;
}

void solve(){
	n=read(),m=read();
	init(max(n,m)+20<<1);
	int ans=0;
	rep(i,1,m-1) add(ans,work1(i));
	rep(i,1,n-1) add(ans,work2(i));
	ans=(ans<<1)%mod;
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}