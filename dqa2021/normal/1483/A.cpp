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
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()

int n,m;
vector<int> S[100010];
int c[100010];
void solve(){
	n=read(),m=read();
	rep(i,1,n) c[i]=0;
	rep(i,1,m){
		int t=read();
		S[i].resize(t);
		rep(j,0,t-1) S[i][j]=read();
		++c[S[i][0]];
	}
	int p=max_element(c+1,c+n+1)-c;
	if (c[p]<=(m+1>>1)){
		puts("YES");
		rep(i,1,m) printf("%d ",S[i][0]);
		puts("");
		return;
	}
	int tot=c[p]-(m+1>>1);
	rep(i,1,m){
		if (tot&&S[i][0]==p&&S[i].size()>1) --tot;
	}
	if (tot) return puts("NO"),void();
	puts("YES");
	tot=c[p]-(m+1>>1);
	rep(i,1,m){
		if (tot&&S[i][0]==p&&S[i].size()>1) --tot,printf("%d ",S[i][1]);
		else printf("%d ",S[i][0]);
	}
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}