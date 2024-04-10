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
#define F fflush(stdout)

int n;
bool ban[1010],ok[1010];
int ask(const vector<int> &S){
	printf("%d",int(S.size()));
	for (int x: S) printf(" %d",x);
	puts(""); F;
	return read();
}
void solve(){
	n=read();
	if (n<=3) puts("0"),F,exit(0);
	int k=2;
	rep(i,3,n) if (n-(n+i-1)/i-i+1>n-(n+k-1)/k-k+1) k=i;
	rep(i,1,n) if ((i-1)%k==0) ban[i]=1;
	while (1){
		vector<int> S;
		rep(i,1,n) if (!ban[i]&&!ok[i]&&int(S.size())<k) ok[i]=1,S.pb(i);
		if (int(S.size())<k) break;
		int T=ask(S);
		for (int i=0;i<k;i++){
			int j=T+i;
			if (j>n) j-=n;
			if (!ban[j]) ok[j]=0;
		}
	}
	puts("0"),F,exit(0);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}