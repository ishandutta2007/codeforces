#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

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
#define F fflush(stdout)

int n;
char s[100010]; int m;
bool lk[100010];
bool llk[100010];
int c[100010];

void ask(const vector<P> &S){
	if (S.empty()) return;
	printf("Q %d",int(S.size()));
	for (const P &o: S) printf(" %d %d",o.fi,o.se);
	puts(""); F;
	scanf("%s",s+1); m=strlen(s+1);
	assert(s[1]!='-');
}

void solve(){  // init !!!
	memset(lk,0,sizeof lk);
	memset(llk,0,sizeof llk);
	
	n=read(); assert(n>0);
	vector<P> S,T;
	rep(i,1,n-1) (i&1?S:T).emplace_back(i,i+1);
	ask(S);
	{
	int p=1;
	rep(i,1,n-1) if (i&1) lk[i+1]=s[p++]-'0';
	}
	ask(T);
	{
	int p=1;
	rep(i,1,n-1) if (i&1^1) lk[i+1]=s[p++]-'0';
	}
	vector<int> W;
	rep(i,1,n) if (!lk[i]) W.pb(i);
	{
	S.clear();
	rep(i,0,W.size()-3) if (i%3==0) S.pb(W[i],W[i+2]);
	ask(S);
	int p=1;
	rep(i,0,W.size()-3) if (i%3==0) llk[i+2]=s[p++]-'0';
	}
	{
	S.clear();
	rep(i,0,W.size()-3) if (i%3==1) S.pb(W[i],W[i+2]);
	ask(S);
	int p=1;
	rep(i,0,W.size()-3) if (i%3==1) llk[i+2]=s[p++]-'0';
	}
	{
	S.clear();
	rep(i,0,W.size()-3) if (i%3==2) S.pb(W[i],W[i+2]);
	ask(S);
	int p=1;
	rep(i,0,W.size()-3) if (i%3==2) llk[i+2]=s[p++]-'0';
	}
	vector<int> A[3];
	int p=1; c[1]=0; A[c[1]].pb(1);
	rep(i,2,n){
		if (lk[i]){
			c[i]=c[i-1];
		}
		else{
			if (p==1) c[i]=1;
			else{
				if (llk[p]) c[i]=c[W[p-2]];
				else c[i]=3^c[W[p-1]]^c[W[p-2]];
			}
			++p;
		}
//		printf("test %d: c %d\n",i,c[i]);
		A[c[i]].pb(i);
	}
	printf("A %d %d %d\n",int(A[0].size()),int(A[1].size()),int(A[2].size()));
	rep(i,0,2){
		for (int x: A[i]) printf("%d ",x);
		puts("");
	}
	F;
	
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}