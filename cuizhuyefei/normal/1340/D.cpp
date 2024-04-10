#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 2e6+11;
int mx1,n;Vi e[N];Pii s[N];int mrk[N],len;set<int>Set[N];
void solve1(int u, int fa);
void solve2(int u, int fa, int cur);

void solve1(int u, int fa, int cur){
	s[++len]=mp(u,cur);
	for(int v:e[u])if(v!=fa){
		solve2(v,u,cur+1);cur++;s[++len]=mp(u,cur);
	}
}
void solve2(int u, int fa, int start){//start-->start-1
	int cnt=0;for(int v:e[u])if(v!=fa)cnt++;
	assert(start<=mx1);
	if(start>cnt){
		s[++len]=mp(u,start);int rec=len;solve1(u,fa,start-cnt-1);
	//	mrk[rec+1]+=start-cnt-1;mrk[len+1]-=start-cnt-1;
		return;
	}
	s[++len]=mp(u,start);int ori=start-1;
	for(int v:e[u])if(v!=fa){
		solve2(v,u,start+1);
		++start;s[++len]=mp(u,start);
		assert(start<=mx1);
		if(start>cnt)start=0,s[++len]=mp(u,0);
	}
	assert(start==ori);
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);
		e[u].pb(v);e[v].pb(u);
	}
	mx1=0;rep(i,1,n)umax(mx1,SZ(e[i]));
	solve1(1,0,0);
//	rep(i,1,len)mrk[i]+=mrk[i-1];
	printf("%d\n",len);
	int mx=0;
	rep(i,1,len)printf("%d %d\n",s[i].fi,s[i].se+mrk[i]),umax(mx,s[i].se+mrk[i]);
	/*rep(i,1,len){
		assert(!Set[s[i].fi].count(s[i].se+mrk[i]));
		Set[s[i].fi].insert(s[i].se+mrk[i]);
	}*/
	assert(mx==mx1);
	return 0;
}