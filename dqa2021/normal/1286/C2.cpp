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

int n;
char s[110];
int c[26][110];

void get(int l,int r,char &a,char &b){
	a=b=0;
	rep(e,0,25){
		int tot=c[e][l]-c[e][l-1];
		rep(i,l+1,r-1) tot-=s[i]-'a'==e;
		if (tot==2) a=b=e+'a';
		else if (tot==1) (a?b:a)=e+'a';
	}
}

void solve(){
	n=read();
	if (n==1){
		printf("? 1 1\n"); fflush(stdout);
		char s[3]; scanf("%s",s+1);
		printf("! %c\n",s[1]); fflush(stdout);
		return;
	}
	
	{
	int m=n>>1;
	printf("? 1 %d\n",m); fflush(stdout);
	static vector<char> S[10010],T[10010];
	int slim=m*(m+1)/2,tlim=m*(m-1)/2;
	rep(i,1,slim){
		static char s[110];
		scanf("%s",s+1);
		for (int j=1;s[j];++j) S[i].pb(s[j]);
		sort(all(S[i]));
	}
	if (m>1){
		printf("? 1 %d\n",m-1); fflush(stdout);
		rep(i,1,tlim){
			static char s[110];
			scanf("%s",s+1);
			for (int j=1;s[j];++j) T[i].pb(s[j]);
			sort(all(T[i]));
		}
	}
	multiset<vector<char> > st;
	rep(i,1,slim) st.insert(S[i]);
	rep(i,1,tlim) st.erase(st.find(T[i]));
	slim=0;
	for (const auto &w: st) S[++slim]=w;
	sort(S+1,S+slim+1,[&](const vector<char> &x,const vector<char> &y){
			return x.size()<y.size();
		});
	static int c[26];
	rep(i,1,m){
		memset(c,0,sizeof c);
		rep(j,1,i) ++c[S[i][j-1]-'a'];
		rep(j,1,i-1) --c[S[i-1][j-1]-'a'];
		s[m-i+1]=max_element(c,c+26)-c+'a';
	}
	}
	
	printf("? 1 %d\n",n); fflush(stdout);
	int lim=n*(n+1)/2;
	rep(i,1,lim){
		static char s[110];
		scanf("%s",s+1);
		const int L=strlen(s+1);
		rep(j,1,L) ++c[s[j]-'a'][L];
	}
	per(t,1,n+1>>1){
		char a,b;
		get(t,n-t+1,a,b);
		if (t==n-t+1) s[t]=a;
		else{
			if (s[t]!=a) swap(a,b);
			assert(s[t]==a);
			s[n-t+1]=b;
		}
	}
	printf("! %s\n",s+1); fflush(stdout);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}