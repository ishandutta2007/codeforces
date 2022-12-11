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
const int INF=1e8;

int n,m,k;
int a[3510],b[3510];
int ok[3510];

bool check(int w){
	rep(i,1,n-m+1) ok[i]=max(a[i],a[i+m-1])>=w,ok[i]+=ok[i-1];
	int t=n-m-k;
	rep(i,0,n-m-t){
		if (ok[i+t+1]-ok[i]==t+1) return 1;
	}
	return 0;
}

void solve(){
	n=read(),m=n-read()+1,k=min(read(),n-m);
	rep(i,1,n) a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	int l=1,r=n,mid;
	while (l<r){
		mid=l+r+1>>1;
		if (check(b[mid])) l=mid;
		else r=mid-1;
	}
	printf("%d\n",b[l]);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}