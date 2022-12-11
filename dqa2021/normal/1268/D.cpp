#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
typedef long long ll;
const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int n;
char mp[2010][2010];
int d[2010];
void rev(int x){
	//printf("test rev %d\n",x);
	d[x]=n-1-d[x];
	rep(i,1,n){
		if (x==i) continue;
		if (mp[i][x]=='1') --d[i];
		else ++d[i];
		swap(mp[i][x],mp[x][i]);
	}
}
bool check(){
	//puts("test");
	//rep(j,1,n) printf("%d ",d[j]); puts("");
	//rep(i,1,n) puts(mp[i]+1);
	static int c[2010];
	memset(c,0,n+1<<2);
	rep(i,1,n) ++c[d[i]];
	int tot=0,sum=0;
	rep(i,0,n){
		while (c[i]--){
			tot++,sum+=i;
			if (sum==tot*(tot-1)/2) return tot==n;
		}
	}
	assert(0);
	return 0;
}
int fac(int x){
	int res=1;
	rep(i,1,x) res*=i;
	return res;
}
void solve(){
	n=read();
	rep(i,1,n) scanf("%s",mp[i]+1);
	rep(i,1,n) rep(j,1,n) d[i]+=mp[i][j]=='1';
	if (n<=6){
		int ans=1e9,anstot=0;
		for (int i=0;i<(1<<n);i++){
			rep(j,1,n) if (i>>j-1&1) rev(j);
			if (check()){
				int _ans=__builtin_popcount(i);
				//printf("test _ans %d\n",_ans);
				if (_ans<ans) ans=_ans,anstot=1;
				else if (_ans==ans) anstot++;
			}
			rep(j,1,n) if (i>>j-1&1) rev(j);
		}
		if (ans==1e9) puts("-1");
		else printf("%d %d\n",ans,anstot*fac(ans));
		return;
	}
	if (check()) return puts("0 1"),void();
	int tot=0;
	rep(i,1,n){
		rev(i);
		if (check()) tot++;
		rev(i);
	}
	assert(tot);
	printf("1 %d\n",tot);
}
int main()
{
	for (int T=1;T--;) solve();
}