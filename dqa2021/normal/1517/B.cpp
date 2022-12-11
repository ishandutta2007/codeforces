#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
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
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m;
int b[110][110],c[110][110];

P w[10010]; int q;

void solve(){
	n=read(),m=read(),q=0;
	rep(i,1,n) rep(j,1,m){
		b[i][j]=read();
		c[i][j]=0;
		w[++q]=P(b[i][j],i);
	}
	sort(w+1,w+q+1);
	rep(i,1,m){
		c[w[i].se][i]=w[i].fi;
	}
	rep(i,1,n){
		multiset<int> st;
		rep(j,1,m) st.insert(b[i][j]);
		rep(j,1,m) if (c[i][j]) st.erase(st.find(c[i][j]));
		rep(j,1,m) if (!c[i][j]) c[i][j]=*st.begin(),st.erase(st.begin());
		rep(j,1,m) printf("%d%c",c[i][j]," \n"[j==m]);
	}
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}