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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m;
char s[1010],t[1010];

void solve(){
	n=read(),m=min(read(),n);
	scanf("%s",s+1);
	while (m--){
		rep(i,1,n){
//			t[i]=s[i]=='1'||s[i-1]=='1'||s[i+1]=='1'?'1':'0';
			if (s[i]=='1') t[i]='1';
			else if (int(s[i-1]=='1')+int(s[i+1]=='1')==1) t[i]='1';
			else t[i]='0';
		}
		rep(i,1,n) s[i]=t[i];
	}
	puts(s+1);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}