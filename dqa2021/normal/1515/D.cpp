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

int n,L,R,w[200010];
int a[200010],b[200010];

void solve(){
	n=read(),L=read(),R=read();
	rep(i,1,n) w[i]=read();
	if (L<R) swap(L,R),reverse(w+1,w+n+1);
	rep(i,1,n) a[i]=b[i]=0;
	rep(i,1,L) ++a[w[i]];
	rep(i,L+1,n) ++b[w[i]];
	int W=0;
	priority_queue<P> que;
	rep(i,1,n) que.push(P(a[i]-b[i],i));
	while (L>R){
//		printf("L %d R %d\n",L,R);
		int t=que.top().se; que.pop();
		--a[t],++b[t]; L--,R++;
		++W;
		que.push(P(a[t]-b[t],t));
	}
	W+=n>>1;
	rep(i,1,n) W-=min(a[i],b[i]);
	printf("%d\n",W);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}