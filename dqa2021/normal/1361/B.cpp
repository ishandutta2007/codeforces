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
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,p;
int w[1000010];
void solve(){
	n=read(),p=read();
	rep(i,1,n) w[i]=read();
	if (p==1) return printf("%d\n",n&1),void();
	sort(w+1,w+n+1);
	while (n){
		while (n>=2&&w[n]==w[n-1]) n-=2;
		if (!n) break;
		ll tot=1;
		int C=n-1;
		bool f=1;
		while (C&&tot){
			rep(i,w[C]+1,w[C+1]){
				tot*=p;
				if (tot>n){
					f=0; break;
				}
			}
			if (!f) break;
			tot--; C--;
		}
		if (f&&!tot){
			//printf("jump to %d\n",C);
			n=C; continue;
		}
		//printf("end at %d\n",n);
		int ans=qpow(p,w[n]);
		rep(i,1,n-1) iadd(ans,qpow(p,w[i]));
		printf("%d\n",ans);
		return;
	}
	puts("0");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}