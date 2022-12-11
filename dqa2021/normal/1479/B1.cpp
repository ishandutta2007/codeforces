#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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

int n,a[100010];
bool check(int l,int r,int b){
	rep(i,l,r) if (a[i-1]^a[i+1]&&a[i]^b) return 1;
	return 0;
}
void solve(){
	n=read();
	rep(i,1,n) a[i]=read();
	int ans=0;
	int C=-1;
	for (int l=1,r;l<=n;l=r+1){
		for (r=l;r<n&&a[r+1]==a[r];++r);
		ans++;
		if (l==r) continue;
		if (~C&&a[C]==a[l]){
			ans+=check(C+1,l-1,a[l]);
		}
		else ++ans;
		C=r;
	}
	printf("%d\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}