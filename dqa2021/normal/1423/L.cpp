#include<cstdio>
#include<algorithm>
#include<cctype>
#include<bitset>
#include<cstring>
#include<vector>
#define pb push_back
#define forall(x,i) for (int i=0,_t=x.size();i<_t;i++)
#define all(x) x.begin(),x.end()
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef unsigned long long ull;
const int LMAX=12,RMAX=18;
typedef pair<ull,int> P;
#define fir first
#define sec second

int n,m,q;
int L,R;
struct Bitset{
	ull s[16];
	void clear(){for (int i=0;i<16;i++) s[i]=0;}
}S[1<<LMAX],T[1<<RMAX],msk[35],C;
bool operator<(const Bitset &x,const Bitset &y){
	for (int i=0;i<16;i++) if (x.s[i]^y.s[i]) return x.s[i]<y.s[i];
	return 0;
}
bool cmp1(int a,int b){
	Bitset &x=T[a],&y=T[b];
	for (int i=0;i<16;i++) if (x.s[i]^y.s[i]) return x.s[i]<y.s[i];
	return 0;
}

Bitset operator ^ (const Bitset &x,const Bitset &y){
	static Bitset z;
	*(z.s + 0) = *(x.s + 0) ^ *(y.s + 0);
	*(z.s + 1) = *(x.s + 1) ^ *(y.s + 1);
	*(z.s + 2) = *(x.s + 2) ^ *(y.s + 2);
	*(z.s + 3) = *(x.s + 3) ^ *(y.s + 3);
	*(z.s + 4) = *(x.s + 4) ^ *(y.s + 4);
	*(z.s + 5) = *(x.s + 5) ^ *(y.s + 5);
	*(z.s + 6) = *(x.s + 6) ^ *(y.s + 6);
	*(z.s + 7) = *(x.s + 7) ^ *(y.s + 7);
	*(z.s + 8) = *(x.s + 8) ^ *(y.s + 8);
	*(z.s + 9) = *(x.s + 9) ^ *(y.s + 9);
	*(z.s + 10) = *(x.s + 10) ^ *(y.s + 10);
	*(z.s + 11) = *(x.s + 11) ^ *(y.s + 11);
	*(z.s + 12) = *(x.s + 12) ^ *(y.s + 12);
	*(z.s + 13) = *(x.s + 13) ^ *(y.s + 13);
	*(z.s + 14) = *(x.s + 14) ^ *(y.s + 14);
	*(z.s + 15) = *(x.s + 15) ^ *(y.s + 15);
	return z;
}
void dfs1(int x,int O){
	if (x==L) return S[O]=C,void();
	dfs1(x+1,O);
	C = C ^ msk[x+1];
	dfs1(x+1,O|(1<<x));
	C = C ^ msk[x+1];
}
void dfs2(int x,int O){
	if (x==R) return T[O]=C,void();
	dfs2(x+1,O);
	C = C ^ msk[x+L+1];
	dfs2(x+1,O|(1<<x));
	C = C ^ msk[x+L+1];
}

int idtot=1;
vector<P> ch[(1<<RMAX) * 16 + 10];
vector<int> V;
int ans[(1<<RMAX) * 16 + 10];
void build(int x,int l,int r,int dep){
//	printf("build %d %d %d %d\n",x,l,r,dep);
	if (dep==16){
		ans[x]=1e9;
		for (int i=l;i<=r;i++)
			ans[x]=min(ans[x],__builtin_popcount(V[i]));
//		printf("ans %d = %d\n",x,ans[x]);
		return;
	}
	for (int i=l,j;i<=r;i=j+1){
		for (j=i;j+1<=r&&T[V[j+1]].s[dep]==T[V[j]].s[dep];j++);
		ch[x].pb((P){T[V[j]].s[dep],++idtot});
		build(idtot,i,j,dep+1);
	}
}
int work(int x,int dep){
//	if (!x) return 1e9;
	if (16==dep) return ans[x];
//	printf("work %d find %llu\n",x,C.s[dep]);
	int t=lower_bound(all(ch[x]),(P){C.s[dep],0})-ch[x].begin();
	if (t>=ch[x].size()||ch[x][t].fir!=C.s[dep]) return 1e9;
	return work(ch[x][t].sec,dep+1);
}
int main()
{
	n=read(),m=read(),q=read();
	R=min(RMAX,m); L=m-R;
	for (int i=1;i<=m;i++){
		int t=read();
		while (t--){
			int x=read(),u=x>>6,v=x&63;
			msk[i].s[u]|=1ULL<<v;
		}
	}
	dfs1(0,0); dfs2(0,0);
	V.resize(1<<R);
	for (int i=0;i<1<<R;i++) V[i]=i;
	sort(all(V),cmp1);
//	for (int i=0;i<1<<R;i++) printf("V %d = %d  %llu\n",i,V[i],T[V[i]].s[0]);
	build(1,0,V.size()-1,0);
	while (q--){
		C.clear();
		int t=read();
		while (t--){
			int x=read(),u=x>>6,v=x&63;
			C.s[u]|=1ULL<<v;
		}
		int res=1e9;
		for (int O=0;O<1<<L;O++){
			C = C ^ S[O];
			res=min(res,__builtin_popcount(O)+work(1,0));
			C = C ^ S[O];
		}
		if (res==1e9) puts("-1");
		else printf("%d\n",res);
	}
	return 0;
}