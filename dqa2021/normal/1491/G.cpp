#include<bits/stdc++.h>
#define pb emplace_back
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
typedef pair<int,int> P;
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

int n,p[200010],q[200010];
vector<P> S;

inline void ins(int x,int y){
	assert(x!=y);
	S.pb(x,y);
	swap(p[x],p[y]);
	swap(q[p[x]],q[p[y]]);
}

void work(vector<int> A,vector<int> B){
	ins(A.back(),B.back());
	rep(i,0,A.size()-2){
		ins(A[i],B.back());
	}
	rep(i,0,B.size()-2){
		ins(B[i],A.back());
	}
	ins(A.back(),B.back());
}

void solve(){
	n=read();
	rep(i,1,n) q[p[i]=read()]=i;
	static bool mrk[200010];
	vector<int> A,B;
	rep(i,1,n){
		if (mrk[i]) continue;
		vector<int> &C=A.empty()?A:B;
		for (int j=i;!mrk[j];mrk[j]=1,C.pb(j),j=p[j]);
		if (B.empty()) continue;
		work(A,B);
		A.clear(),B.clear();
	}
	if (A.size()>1){
		if (A.size()==2){
			int o=-1;
			rep(i,1,n) if (i^A[0]&&i^A[1]){o=i; break;}
			ins(A[0],o); ins(A[1],o); ins(A[0],o);
		}
		else{
			ins(A.back(),A[0]);
			ins(A[0],A[1]);
			swap(A[0],A[1]);
			int u=A[0],v=A[1],w=A[2];
			rep(i,3,A.size()-1){
				ins(v,w); w=A[i];
			}
			ins(w,u); ins(v,w);
		}
	}
	printf("%d\n",int(S.size()));
	for (const auto &[x,y]: S) printf("%d %d\n",x,y);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}