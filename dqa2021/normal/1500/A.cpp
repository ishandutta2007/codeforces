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
typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m=2500000;
P a[200010];
P b[5000010];
vector<int> c[2500010];
void check(int s,int x,int y){
	if (b[s].fi) printf("YES\n%d %d %d %d\n",b[s].fi,b[s].se,x,y),exit(0);
	else b[s]=P(x,y);
}
void solve(){
	n=read();
	rep(i,1,n) a[i]=P(read(),i),c[a[i].fi].pb(i);
	rep(i,1,m){
		if (c[i].size()<=3) continue;
		printf("YES\n");
		rep(T,1,4) printf("%d%c",c[i].back()," \n"[T==4]),c[i].pop_back();
		//puts("");
		return;
	}
	int A=-1,B=-1;
	rep(i,1,m){
		if (c[i].size()<=1) continue;
		if (~A) B=i;
		else A=i;
	}
	if (~B){
		printf("YES\n");
		printf("%d %d ",c[A].back(),c[B].back());
		c[A].pop_back(),c[B].pop_back();
		printf("%d %d\n",c[A].back(),c[B].back());
		return;
	}
	if (~A){
		int top=n; n=0;
		rep(i,1,top)
			if (i==c[a[i].fi].back()) a[++n]=a[i];
			else b[a[i].fi<<1]=P(c[a[i].fi].back(),i);
	}
	rep(i,1,n)
		rep(j,i+1,n){
			check(a[i].fi+a[j].fi,a[i].se,a[j].se);
		}
	puts("NO");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}