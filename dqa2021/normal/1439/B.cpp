#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<set>
#include<assert.h>
#include<cstdlib>
#define pb push_back
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef pair<int,int> P;
const int mod=1e6+3;

int n,m,k;
vector<int> e[100010];
int d[100010];
set<P> st[1<<20];
vector<int> work(int k){
	static int d[100010],que[100010],hd,tl;
	static int vis[100010],tim;
	for (int i=1;i<=n;i++) d[i]=::d[i];
	hd=tl=0; ++tim;
	
	for (int i=1;i<=n;i++) if (d[i]<k) vis[i]=tim,que[++tl]=i;
	while (hd<tl){
		int u=que[++hd];
		for (int x: e[u])
			if (vis[x]!=tim&&(--d[x])<k)
				que[++tl]=x,vis[x]=tim;
	}
	
	vector<int> S;
	for (int i=1;i<=n;i++) if (vis[i]^tim) S.pb(i);
	return S;
}
int c[100010];
bool check(int x){
	vector<int> S; S.reserve(k); S.pb(x);
	for (int y: e[x]) if (c[y]>=1) S.pb(y);
	//assert(S.size()==k);
	if (S.size()<k) return 0;
	if (S.size()!=k) printf("%d :: %d\n",k,int(S.size())),exit(1234);
	for (int x: S)
		for (int y: S)
			if (x<y){
				int h=(1LL*x*x*x+1LL*y*y*y)%mod;
				if (!st[h].count((P){x,y})) return 0;
			}
	return 1;
}
void init(){
	for (int i=1;i<=n;i++){
		for (int x: e[i]) if (x<i){
			int h=(1LL*i*i*i+1LL*x*x*x)%mod;
			st[h].clear();
		}
		e[i].clear(),d[i]=0;
	}
}
void solve(){
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read();
		if (u>v) swap(u,v);
		e[u].pb(v); e[v].pb(u);
		d[u]++,d[v]++;
		int h=(1LL*u*u*u+1LL*v*v*v)%mod;
		st[h].insert((P){u,v});
	}
	auto S=work(k);
	if (!S.empty()){
		printf("1 %d\n",int(S.size()));
		for (int x: S) printf("%d ",x);
		puts("");
		return;
	}
	S=work(k-1);
	if (S.empty()) return puts("-1"),void();
	static int que[100010],hd,tl; hd=tl=0;
	for (int i=1;i<=n;i++) c[i]=0,d[i]=0;
	for (int x: S) c[x]=1;
	for (int x: S){
		d[x]=0;
		for (int y: e[x]) if (c[y]>=1) d[x]++;
		if (d[x]<k-1) exit(2345);
		if (d[x]==k-1) que[++tl]=x,c[x]=2;
	}
	while (hd<tl){
		int u=que[++hd]; //d[u]=0;
		//for (int x: e[u]) if (c[x]>=1) d[u]++;
		//if (d[u]<k-1) continue;
		if (c[u]&&check(u)){
			puts("2");
			printf("%d",u);
			for (int x: e[u]) if (c[x]>=1) printf(" %d",x);
			puts("");
			return;
		}
		c[u]=0;
		for (int x: e[u]){
			if (!c[x]) continue;
			--d[x];
			if (d[x]<k-1){
				if (c[x]!=2) exit(3456);
				c[x]=0;
			}
			else if (d[x]<k){
				if (c[x]!=1) exit(4567);
				c[x]=2,que[++tl]=x;
			}
		}
	}
	puts("-1");
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}