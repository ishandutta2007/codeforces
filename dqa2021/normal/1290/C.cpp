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

int n,m;
vector<int> e[300010];
char str[300010];

int f[300010],w[300010],s[2][300010],t[300010];
int find(int x){
	if (!f[x]) return x;
	int t=f[x]; f[x]=find(f[x]);
	w[x]^=w[t]; return f[x];
}

int ans;

int getval(int x){
	if (!~t[x]) return min(s[0][x],s[1][x]);
	return s[t[x]^1][x];
}

void merge(int x,int y,int q){
	f[y]=x,w[y]=q,s[0][x]+=s[q][y],s[1][x]+=s[q^1][y];
	if (~t[y]) t[x]=t[y]^q;
	//printf("  merge %d <- %d o %d q %d  s %d %d\n",x,y,o,q,s[0][x],s[1][x]);
}

void work(int o,vector<int> E){
	if (E.empty()) return;
	if (E.size()==1){
		int x=E[0];
		//printf("set %d to %d\n",x,o^1);
		int y=find(x);
		ans-=getval(y);
		t[y]=o^1^w[x];
		ans+=getval(y);
		return;
	}
	int x=E[0],y=E[1];
	int a=find(x),b=find(y);
	if (a==b) return;
	//printf("link %d -%d- %d\n",x,o^1,y);
	ans-=getval(a),ans-=getval(b);
	merge(a,b,w[y]^o^1^w[x]);
	ans+=getval(a);
}

void solve(){
	n=read(),m=read();
	scanf("%s",str+1);
	rep(i,1,m){
		int t=read();
		while (t--) e[read()].pb(i);
	}
	rep(i,1,m) s[0][i]=1;
	memset(t,-1,sizeof t);
	rep(i,1,n){
		work(str[i]-'0',e[i]);
		printf("%d\n",ans);
		//rep(j,1,m) printf("%d: f %d w %d s %d %d t %d\n",j,f[j],w[j],s[0][j],s[1][j],t[j]);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}