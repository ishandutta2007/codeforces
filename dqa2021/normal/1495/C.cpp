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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m;
char mp[512][512];
void solve(){
	n=read(),m=read();
	rep(i,1,n) scanf("%s",mp[i]+1);
	for (int i=1;i<=n;i+=3){
		rep(j,1,m) mp[i][j]='X';
		if (i+2>n) break;
		if (i+2==n){
			rep(j,1,m) if (mp[i+2][j]=='X') mp[i+1][j]='X';
		}
		else{
			bool f=0;
			rep(j,1,m){
				if (f) break;
				if (mp[i+1][j]=='X'){
					mp[i+2][j]='X'; f=1; break;
				}
			}
			rep(j,1,m){
				if (f) break;
				if (mp[i+2][j]=='X'){
					mp[i+1][j]='X'; f=1; break;
				}
			}
			if (!f) mp[i+1][1]=mp[i+2][1]='X';
		}
	}
	rep(i,1,n) puts(mp[i]+1);
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}