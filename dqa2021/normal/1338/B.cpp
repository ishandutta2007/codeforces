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

int n;
vector<int> e[100010];
int tot[2]; int fat[100010],dep[100010];
void dfs(int x,int f,int d){
	dep[x]=d; fat[x]=f;
	for (int y: e[x]) if (y^f) dfs(y,x,d+1);
}
void solve(){
	n=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	int rt=-1;
	rep(i,1,n) if (e[i].size()>1) rt=i;
	dfs(rt,0,1);
	rep(i,1,n) if (e[i].size()==1) tot[dep[i]&1]++;
	printf("%d ",tot[0]&&tot[1]?3:1);
	set<int> S;
	int T=0;
	rep(i,1,n) if (e[i].size()==1) S.insert(fat[i]); else T++;
	printf("%d\n",T-1+int(S.size()));
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}