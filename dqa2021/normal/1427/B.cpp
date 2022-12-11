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
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int n,k;
char s[100010];
void solve(){
	scanf("%d%d%s",&n,&k,s+1);
	int Wtot=0;
	rep(i,1,n) Wtot+=s[i]=='W';
	k=min(k,n-Wtot);
	if (!Wtot){
		printf("%d\n",k?k*2-1:0);
		return;
	}
	vector<int> S;
	for (int i=1,j=0;i<=n;i++){
		if (s[i]=='L') continue;
		if (j&&j!=i-1){
			S.pb(i-j-1);
		}
		j=i;
	}
	sort(S.begin(),S.end());
	int ans=(k+Wtot)*2-int(S.size())-1;
	//reverse(S.begin(),S.end());
	for (int x: S){
		if (x>k) break;
		k-=x; ans++;
	}
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) solve();
}