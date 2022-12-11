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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n;
P w[200010];

void solve(){
	n=read();
	rep(i,1,n) w[i].fi=read();
	rep(i,1,n) w[i].se=read();
	sort(w+1,w+n+1);
	priority_queue<int> que;
	ll ans=0; int T=0; ll S=0; int p=1;
	while (p<=n||que.size()){
		while (p<=n&&w[p].fi<=T) S+=w[p].se,que.push(w[p++].se);
		if (que.empty()){T=w[p].fi; continue;}
		//printf("test T %d size %d\n",T,int(que.size()));
		S-=que.top(); que.pop();
		ans+=S; T++;
	}
	printf("%lld\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}