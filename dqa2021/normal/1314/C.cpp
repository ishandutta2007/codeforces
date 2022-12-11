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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
const ll INF=2e18;

int n,m; ll k;
char s[1010];

int ch[1000010][26],idtot=1;
int id[1000010],fat[1000010];

int p[1000010];

void ins(char *s,int len){
	int o=1;
	rep(i,1,len){
		const int c=s[i]-'a';
		if (!ch[o][c]) ch[o][c]=++idtot,fat[idtot]=o,id[idtot]=c;
		o=ch[o][c];
	}
}

void dfs(int x){
	per(i,0,25) if (ch[x][i]) dfs(ch[x][i]);
	if (x>1) p[++*p]=x;
}

int suf[1010];

ll dp[2][1010];

ll check(int o){
	static char t[1010]; int top=0;
	for (;o^1;o=fat[o]) t[++top]=id[o]+'a';
	reverse(t+1,t+top+1); t[top+1]=0;
	//printf("check %s\n",t+1);
	rep(i,1,n){
		int lcp=0;
		while (1+lcp<=top&&t[1+lcp]==s[i+lcp]) ++lcp;
		if (lcp==top) suf[i]=i+lcp;
		else if (t[1+lcp]>s[i+lcp]) suf[i]=-1;
		else suf[i]=i+lcp+1;
		//printf("  suf %d = %d\n",i,suf[i]);
	}
	auto F=dp[0],G=dp[1];
	rep(i,1,n) F[i]=0;
	F[n+1]=1;
	rep(_,1,m){
		swap(F,G);
		rep(i,1,n+1) F[i]=0;
		per(i,1,n) G[i]=min(INF,G[i]+G[i+1]);
		rep(i,1,n){
			if (~suf[i]) F[i]=G[suf[i]];
		}
	}
	//printf("  ans %lld\n",F[1]);
	return F[1];
}

void solve(){
	scanf("%d%d%lld%s",&n,&m,&k,s+1);
	rep(i,1,n) ins(s+i-1,n-i+1);
	dfs(1);
	
	//rep(i,1,*p) check(p[i]);
	//check(p[7]);
	//return;
	
	int l=1,r=*p,mid;
	while (l<r){
		mid=l+r>>1;
		if (check(p[mid])>=k) r=mid;
		else l=mid+1;
	}
	vector<char> t;
	for (int i=p[l];i^1;i=fat[i]) t.pb(id[i]+'a');
	reverse(all(t));
	for (char x: t) putchar(x);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}