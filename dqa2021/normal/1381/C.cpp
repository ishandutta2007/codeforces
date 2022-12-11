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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,X,Y;
int b[100010],c[100010],C,ans[100010];
vector<int> e[100010];
bool mrk[100010];
void solve(){  //init
	n=read(),X=read(),Y=read();
	rep(i,1,n+1) c[i]=0,e[i].clear(),ans[i]=-1,mrk[i]=0;
	rep(i,1,n) b[i]=read(),c[b[i]]++,e[b[i]].pb(i);
	rep(i,1,n+1) if (!c[i]) C=i;
	priority_queue<P> que;
	rep(i,1,n+1) if (c[i]) que.push(P(c[i],i));
	rep(i,1,X){
		P v=que.top(); que.pop();
		--c[v.se],--v.fi;
		int t=e[v.se].back(); e[v.se].pop_back();
		ans[t]=b[t];
//		printf("test A %d\n",t);
		if (v.fi) que.push(v);
	}
	int S=n-Y,T=n-X,W=0;
	vector<int> V;
	rep(i,1,n+1){
		W=max(W,int(e[i].size()));
		for (int x: e[i]) V.pb(x);
	}
	rep(i,1,n+1){
		int tot=max(0,int(e[i].size())*2-T);
		if (tot>S) return puts("NO"),void();
		S-=tot;
		while (tot--){
			int t=e[i].back(); e[i].pop_back();
//			ans[t]=C;
			mrk[t]=1;
//			printf("test B %d\n",t);
		}
	}
	rep(i,1,n+1){
		while (e[i].size()&&S){
			int t=e[i].back(); e[i].pop_back();
			//ans[t]=C;
			mrk[t]=1; S--;
//			printf("test B %d\n",t);
		}
	}
	assert(!S);
	for (int i=0;i<int(V.size());++i){
		int j=(i-W+int(V.size()))%int(V.size());
		ans[V[i]]=mrk[V[j]]?C:b[V[j]];
	}
	puts("YES");
	rep(i,1,n) printf("%d ",ans[i]);
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}