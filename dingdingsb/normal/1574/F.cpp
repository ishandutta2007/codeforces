// Problem: CF1574F Occurrences
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1574F
// Memory Limit: 500 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=o;}
    modint<mod> &operator = (int o){return x=o,*this;}
    modint<mod> &operator +=(modint<mod> o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint<mod> &operator -=(modint<mod> o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint<mod> &operator *=(modint<mod> o){return x=1ll*x*o.x%mod,*this;}
    modint<mod> &operator ^=(int b){
        modint<mod> a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint<mod> &operator /=(modint<mod> o){return *this *=o^=mod-2;}
    modint<mod> &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint<mod> &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint<mod> &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint<mod> &operator /=(int o){return *this *= ((modint<mod>(o))^=mod-2);}
    template<class I>friend modint<mod> operator +(modint<mod> a,I b){return a+=b;}
    template<class I>friend modint<mod> operator -(modint<mod> a,I b){return a-=b;}
    template<class I>friend modint<mod> operator *(modint<mod> a,I b){return a*=b;}
    template<class I>friend modint<mod> operator /(modint<mod> a,I b){return a/=b;}
    friend modint<mod> operator ^(modint<mod> a,int b){return a^=b;}
    friend bool operator ==(modint<mod> a,int b){return a.x==b;}
    friend bool operator !=(modint<mod> a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint<mod> operator - () {return x?mod-x:0;}
    modint<mod> &operator++(int){return *this+=1;}
};
using mint=modint<998244353>;
const int N=3e5+100,M=550;
int n,m,k;
vector<int>a[N];
set<int>pre[N],nxt[N];
//
//1
bool vis[N];
vector<int>lens,wyhmy;
int cnt[M];
mint f[N];
int dfs(int u){
	if(vis[u])return -1;vis[u]=1;
	if(pre[u].size()>1)return -1;
	if(nxt[u].size()>1)return -1;
	if(nxt[u].size()==0)return 1;
	int v=*nxt[u].begin();
	int res=dfs(v);
	if(res==-1)return -1;
	return res+1;
}
signed main(){
	read(n,m,k);
	for(int i=1;i<=n;i++){
		int c,x;read(c);
		for(int j=1;j<=c;j++)read(x),a[i].pb(x);
		for(int j=1;j<a[i].size();j++)
			pre[a[i][j]].insert(a[i][j-1]);
		for(int j=0;j+1<a[i].size();j++)
			nxt[a[i][j]].insert(a[i][j+1]);
	}
	for(int i=1;i<=k;i++)
		if(pre[i].size()==0){
			int kk=dfs(i);
			if(kk!=-1)lens.pb(kk);
		}
	for(auto x:lens)
		if(x<M)cnt[x]++;
		else wyhmy.pb(x);
	f[0]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<M&&j<=i;j++)
			f[i]+=cnt[j]*f[i-j];
		for(auto x:wyhmy)if(x<=i)
			f[i]+=f[i-x];
	}
	write(f[m].x);
}