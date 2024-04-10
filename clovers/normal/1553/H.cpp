/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=550005;
const int M=N*22;
int n,m,k,a[N],vis[N];
struct Trie{
	int ls[M],rs[M],tot=0;
	void init(){for(int i=1;i<=tot;i++) ls[i]=rs[i]=0; tot=1;}
	void insert(int val){
		int x=1;
		for(int i=k-1;i>=0;i--){
			if(val>>i&1){if(!rs[x]) rs[x]=++tot; x=rs[x];}
			else{if(!ls[x]) ls[x]=++tot; x=ls[x];}
		}
	}
	int findmx(int val){
		int x=1,ret=0;
		assert(ls[x]||rs[x]);
		for(int i=k-1;i>=0;i--){
			if(val>>i&1){if(ls[x]) x=ls[x],ret+=(1<<i); else x=rs[x];}
			else{if(rs[x]) x=rs[x],ret+=(1<<i); else x=ls[x];}
		}
		return ret;
	}
	int findmi(int val){
		int x=1,ret=0;
		assert(ls[x]||rs[x]);
		for(int i=k-1;i>=0;i--){
			if(val>>i&1){if(!rs[x]) x=ls[x],ret+=(1<<i); else x=rs[x];}
			else{if(!ls[x]) x=rs[x],ret+=(1<<i); else x=ls[x];}
		}
		return ret;
	}
}T1,T2;

vector<int> ans[N<<1];
void solve(int x,int l,int r,int bit){
	ans[x].resize(1<<bit);
	for(int i=0;i<sz(ans[x]);i++) ans[x][i]=inf;
	if(bit==0) return;
	int mid=(l+r)>>1;
	solve(x<<1,l,mid,bit-1); solve(x<<1|1,mid+1,r,bit-1);
	for(int i=0;i<(1<<bit-1);i++){
		ans[x][i]=min(ans[x<<1][i],ans[x<<1|1][i]);
		ans[x][i+(1<<bit-1)]=min(ans[x<<1][i],ans[x<<1|1][i]);
	}
	T1.init(); T2.init(); int flag=0;
	for(int i=l;i<=mid;i++) if(vis[i]) T1.insert(i%(1<<bit-1)),flag|=1;
	for(int i=mid+1;i<=r;i++) if(vis[i]) T2.insert(i%(1<<bit-1)),flag|=2;
	if(flag==3) for(int i=0;i<(1<<bit-1);i++){
		checkmin(ans[x][i],T2.findmi(i)+(1<<bit-1)-T1.findmx(i));
		checkmin(ans[x][i+(1<<bit-1)],T1.findmi(i)+(1<<bit-1)-T2.findmx(i));
	}
	//out(l); out(r); out(bit); outln(flag);
	//for(auto &u : ans[x]) cout<<u<<" "; cout<<endl;
}

int main()
{
    n=read(); k=read(); m=(1<<k);
    for(int i=1;i<=n;i++) a[i]=read(),vis[a[i]]=1;
    solve(1,0,m-1,k);
 	for(int i=0;i<m;i++) printf("%d ",ans[1][i]); puts("");
    return 0;
}