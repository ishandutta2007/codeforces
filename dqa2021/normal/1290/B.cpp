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

char s[200010];
int p[200010][26];

void solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n){
		memcpy(p[i],p[i-1],26<<2);
		++p[i][s[i]-'a'];
	}
	int q=read();
	while (q--){
		int l=read(),r=read();
		if (l==r||s[l]!=s[r]) puts("Yes");
		else{
			int t=0;
			rep(i,0,25) t+=p[r][i]-p[l-1][i]>0;
			puts(t>=3?"Yes":"No");
		}
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}