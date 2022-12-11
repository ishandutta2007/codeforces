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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m,X;
int h[100010],id[100010];
int tot[100010];

void solve(){
	n=read(),m=read(),X=read();
	rep(i,1,n) h[i]=read();
	priority_queue<P,vector<P>,greater<P> > que;
	rep(i,1,m) id[i]=i,que.push(P(h[i],i)),tot[i]=h[i];
	int p=m+1;
	while (p<=n){
		int t=que.top().se; que.pop();
		tot[t]+=h[p]; id[p]=t; p++;
		que.push(P(tot[t],t));
	}
	puts("YES");
	rep(i,1,n) printf("%d ",id[i]);
	puts("");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}