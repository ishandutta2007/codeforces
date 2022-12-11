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
typedef vector<int> V;

int n;
char s[64];

bool ask(const char *t){
	printf("? %s\n",t);
	fflush(stdout);
	int m=read();
	assert(~m);
	rep(i,1,m) read();
	return m;
}

void report(const char *t){
	printf("! %s\n",t);
	fflush(stdout);
	assert(read());
}

bool ask_and_mark(const char *t){
	printf("? %s\n",t);
	fflush(stdout);
	int m=read();
	assert(~m);
	rep(i,0,m-1){
		int p=read();
		for (int j=0;t[j];++j)
			s[p+j]=t[j];
	}
	return m>0;
}

void solve_big(){
	ask_and_mark("CC");
	ask_and_mark("HH");
	ask_and_mark("OO");
	ask_and_mark("CO");
	ask_and_mark("CH");
	int p=1;
	while (p<n&&s[p]=='?') ++p;
	if (p<n){
		rep(i,p+1,n-1){
			if (s[i]!='?') continue;
			if (s[i-1]=='C') assert(0);
			else s[i]=s[i-1]=='H'?'O':'H';
		}
	}
	const bool e=s[n]=='?';
	rep(i,1,p-1){
		s[i]=i&1?'H':'O';
	}
	if (e) for (char c: {'C','H','O'}) if (c!=s[n-1]) {s[n]=c; break;}
	if (ask(s+1)) return report(s+1);
	if (e) for (char c: {'O','H','C'}) if (c!=s[n-1]) {s[n]=c; break;}
	if (ask(s+1)) return report(s+1);
	
	rep(i,1,p-1){
		s[i]=i&1?'O':'H';
	}
	if (e) for (char c: {'C','H','O'}) if (c!=s[n-1]) {s[n]=c; break;}
	if (ask(s+1)) return report(s+1);
	if (e) for (char c: {'O','H','C'}) if (c!=s[n-1]) {s[n]=c; break;}
	return report(s+1);
}

void solve(){
	n=read();
	rep(i,1,n) s[i]='?';
	s[n+1]=0;
	if (n>=5) return solve_big();
	if (ask_and_mark("CC")|ask_and_mark("CH")|ask_and_mark("CO")|ask_and_mark("HO")){
		int cnt=0;
		for (char a: {'C','H','O'})
			for (char b: {'C','H','O'})
				for (char c: {'C','H','O'})
					for (char d: {'C','H','O'}){
						if (s[1]!='?'&&s[1]!=a) continue;
						if (s[2]!='?'&&s[2]!=b) continue;
						if (s[3]!='?'&&s[3]!=c) continue;
						if (s[4]!='?'&&s[4]!=d) continue;
						if (s[1]=='?'&&a=='C') continue;
						if (s[2]=='?'&&b=='C') continue;
						if (s[3]=='?'&&c=='C') continue;
						++cnt;
						static char t[8];
						t[1]=a,t[2]=b,t[3]=c,t[4]=d,t[5]=0;
						if (cnt==6||ask(t+1)) return report(t+1);
					}
		assert(0);
	}
	if (ask_and_mark("OO")){
		if (s[4]=='O') return report(s+1);
		if (s[3]=='?') s[3]='H';
		s[4]='H';
		if (ask(s+1)) return report(s+1);
		s[4]='C';
		return report(s+1);
	}
	s[2]=s[3]='H';
	ask_and_mark("HHH");
	if (s[1]=='?') s[1]='O';
	if (s[4]=='?') s[4]='C';
	return report(s+1);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}