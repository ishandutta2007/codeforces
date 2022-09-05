#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 1005;
int n,head[N],to[N<<2],nxt[N<<2],edgenum,dep[N],rt,dy[1<<16|3],cnt[1<<16|3],size[N];
void add(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
void dfs(int u, int fa, int Dep){
	dep[u]=Dep;L(i,u)if(to[i]!=fa)dfs(to[i],u,Dep+1);
}
struct Bitset{
	ui v[(N>>5)+2];
	inline void set(int x){v[x>>5]|=1u<<(x&31);}
	inline void reset(int x){v[x>>5]&=~(1u<<(x&31));}
	inline int query(int x){return (v[x>>5]>>(x&31))&1;}
}p[N],cer,lj[N];
Vi solve(const Bitset &a, const Bitset &b){
	Vi r;
	rep(i,0,N>>5){
		int x=a.v[i]&b.v[i]&65535;
		while(x){int bit=x&-x;x-=bit;r.pb((i<<5)+dy[bit]);}
		x=(a.v[i]&b.v[i])>>16;//WA
		while(x){int bit=x&-x;x-=bit;r.pb((i<<5)+(1<<4)+dy[bit]);}
		if(SZ(r)>2){r.clear();return r;}
	}
	return r;
}
/*inline bool notfull(const Bitset &a){
	rep(i,0,(n>>5)-1)if(a.v[i]!=-1u)return 1;u
	if(cnt[a.v[n>>5]>>16]+cnt[a.v[n>>5]&65535]!=(n&31))return 1;
	return 0;
}*/
inline bool same(const Bitset &a, const Bitset &b){
	rep(i,0,n>>5)if(a.v[i]!=b.v[i])return 0;
	return 1;
}
set<Pii>Set;
int main() {//freopen("1.in","r",stdin);
	rep(i,1,16)dy[1<<i]=i;
	rep(i,1,1<<16)cnt[i]=cnt[i>>1]+(i&1);
	read(n);
	rep(i,1,n){int l,x;read(l);size[i]=l;while(l--)read(x),p[i].set(x);}
	rep(i,1,n)rep(j,i+1,n){
		Vi t=solve(p[i],p[j]);
		if(SZ(t)==2){
			if(t[0]>t[1])swap(t[0],t[1]);if(Set.count(Pii(t[0],t[1])))continue;//WA
			add(t[0],t[1]),add(t[1],t[0]),printf("%d %d\n",t[0],t[1]);
			Set.insert(Pii(t[0],t[1]));
		}
	}
	int cnt=0;rep(i,1,n)cnt+=head[i]>0;
	if(n==2)return 0;
	if(!cnt){
		rep(i,2,n)printf("%d %d\n",1,i);
		return 0;
	}
	if(cnt==2){
		Vi t;rep(i,1,n)if(head[i])t.pb(i);
		static bool ok[N];ok[t[0]]=ok[t[1]]=1;int q=0;
		rep(i,1,n)if(!ok[i]){
			int j;for(j=1;j<=n;j++)if(size[j]<n&&p[j].query(i))break;
			rep(k,1,n)if(!ok[k]&&p[j].query(k))ok[k]=1,printf("%d %d\n",k,t[q]);
			q++;
		}
		return 0;
	}
	rep(i,1,n)if(head[i])rt=i;dfs(rt,0,0);
	rep(i,1,n)if(head[i])cer.set(i);
	rep(i,1,n)if(head[i]){L(e,i)lj[i].set(to[e]);lj[i].set(i);}
	rep(i,1,n)if(!head[i]){
		/*rep(j,1,n)if(p[j].query(i)){
			Vi t=solve(cer,p[j]);if(SZ(t)!=2)continue;
			int x=dep[t[0]]>dep[t[1]]?t[0]:t[1];
			printf("%d %d\n",i,x);
			break;
		}*/
		int q=0;rep(j,1,n)if(p[j].query(i)&&(!q||size[j]<size[q]))q=j;
		Bitset inner=p[q];
		rep(j,1,n)if(!head[j]&&inner.query(j))inner.reset(j);
		int x=0;rep(j,1,n)if(head[j]&&same(lj[j],inner)){x=j;break;}
		printf("%d %d\n",i,x);
	}
	return 0;
}