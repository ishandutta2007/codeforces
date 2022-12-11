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
const int mod=1e9+7;
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

int n;

struct P{
	int x,y;
}p[1000100];
//P operator+(const P &x,const P &y){return (P){x.x+y.x,x.y+y.y};}
//P operator-(const P &x,const P &y){return (P){x.x-y.x,x.y-y.y};}
ll cross(const P &x,const P &y){return 1LL*x.x*y.y-1LL*x.y*y.x;}

int A[1000100],B[1000100],C[1000100],D[1000100];
ll E[1000100];

int getsum(int l,int r,int *s){
	return upd(s[r]-s[l-1]);
}

void solve(){
	n=read();
	per(i,1,n) p[i]=(P){read(),read()};
	rep(i,n+1,n+n+5) p[i]=p[i-n];
	rep(i,1,n+n+4){
		A[i]=upd(cross(p[i],p[i+1])%mod);
		B[i]=1LL*A[i]*i%mod;
		add(A[i],A[i-1]);
		add(B[i],B[i-1]);
		C[i]=upd(p[i].x);
		add(C[i],C[i-1]);
		D[i]=upd(p[i].y);
		add(D[i],D[i-1]);
		
		E[i]=ull(E[i-1])+ull(cross(p[i],p[i+1]));
	}
	int ans=0;
	rep(i,1,n){
		static int j=2;  // first that back <= front
		assert(j>i);
		while (ll(ull(E[i+n-1])-ull(E[j-1]))+cross(p[i],p[j])>
			ll(ull(E[j-1])-ull(E[i-1]))+cross(p[j],p[i])) ++j;
			
		//printf("i %d j %d\n",i,j);
			
		iadd(ans,upd((getsum(j,i+n-1,B)-1LL*getsum(j,i+n-1,A)*(j-1))%mod));
		iadd(ans,upd((1LL*p[i].x*getsum(j,i+n-1,D)-1LL*p[i].y*getsum(j,i+n-1,C))%mod));
		//printf("ans1 %d = %d\n",i,ans);
		
		iadd(ans,upd((1LL*getsum(i,j-2,A)*(j-1)-getsum(i,j-2,B))%mod));
		//ans+=getsum(i,j-1,C)*p[i].y-p[i].x*getsum(i,j-1,D);
		iadd(ans,upd((1LL*getsum(i+1,j-1,C)*p[i].y-1LL*getsum(i+1,j-1,D)*p[i].x)%mod));
		//printf("ans2 %d = %d\n",i,ans);
		
		//ans+=getsum(i,j-1,B)-getsum(i,j-1,A)*i+getsum(j,i+n-1,A)*(j-i-1)
		add(ans,upd((getsum(i,j-1,B)-1LL*getsum(i,j-1,A)*i+1LL*getsum(j,i+n-1,A)*(j-i-1))%mod));
		//ans+=p[i].x*getsum(i+1,j-1,D)-p[i].y*getsum(i+1,j-1,C)
		add(ans,upd((1LL*p[i].x*getsum(i+1,j-1,D)-1LL*p[i].y*getsum(i+1,j-1,C))%mod));
		//printf("ans3 %d = %d\n",i,ans);
		
		//ans+=getsum(i,j-1,A)*(i+n-j)+getsum(j,i+n-1,A)*(i+n-1)-getsum(j,i+n-1,B)
		add(ans,upd((1LL*getsum(i,j-1,A)*(i+n-j)+1LL*getsum(j,i+n-1,A)*(i+n-1)-getsum(j,i+n-1,B))%mod));
		//ans+=getsum(j,i+n-1,C)*p[i].y-getsum(j,i+n-1,D)*p[i].x
		add(ans,upd((1LL*getsum(j,i+n-1,C)*p[i].y-1LL*getsum(j,i+n-1,D)*p[i].x)%mod));
		//printf("ans4 %d = %d\n",i,ans);
		
		//printf("ans %d = %d\n",i,ans);
	}
	ans=1LL*ans*qpow(2,mod-2)%mod;
	iadd(ans,1LL*n*A[n]%mod);
	printf("%d\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}