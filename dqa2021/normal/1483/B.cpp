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
#define all(x) (x).begin(),(x).end()
#define gcd __gcd

int n,a[100010];
int L[100010],R[100010];
void solve(){
	n=read();
	rep(i,1,n) a[i]=read(),L[i]=i-1,R[i-1]=i;
	R[n]=1,L[1]=n;
	set<int> st;
	rep(i,1,n) if (gcd(a[i],a[i==1?n:i-1])==1) st.insert(i);
	int tot=n,p=1;
	vector<int> S;
	while (tot){
		if (st.empty()) break;
		auto it=st.upper_bound(p);
		if (it==st.end()) it=st.begin();
		S.pb(*it); int u=*it;
		st.erase(it);
		--tot;
		if (!tot) break;
		R[L[u]]=R[u],L[R[u]]=L[u];
		if (gcd(a[R[u]],a[L[u]])==1) st.insert(R[u]);
		else st.erase(R[u]);
		p=R[u];
//		printf("all: ");
//		for (auto x: st) printf("%d ",x);
//		puts("");
	}
//	puts("test");
	printf("%d ",S.size());
	for (int x: S) printf("%d ",x);
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}