#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=153;
int n,m,u[N],v[N],d[N];
int f[N][N];
struct mat{
	bitset<N>h[N];
	bitset<N>s[N];
	void reset(){for(int i=1;i<=n;i++)h[i].reset(),s[i].reset();}
	bool ask(int i,int j){return h[i][j];}
	void set(int i,int j,int v=1){h[i][j]=v;s[j][i]=v;}
	void init(){for(int i=1;i<=n;i++)set(i,i);}
	friend mat operator*(mat a,mat b){
		mat res;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if((a.h[i]&b.s[j]).any())
					res.set(i,j);
		return res;
	}
	friend mat operator^(mat a,int b){
		mat res;res.init();
		while(b){
			if(b&1)res=res*a;
			a=a*a;b>>=1;
		}
		return res;
	}
}res,tmp;
vector<int>keys;
void Floyd(int t){
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)
		if(d[i]<=t)
			f[u[i]][v[i]]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chkmn(f[i][j],f[i][k]+f[k][j]);
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)if(res.ask(1,i))
		chkmn(ans,t+f[i][n]);
	if(ans==0x3f3f3f3f)puts("Impossible");
	else writeln(ans);
}
signed main(){
	read(n,m);
	for(int i=1;i<=m;i++)read(u[i],v[i],d[i]),keys.pb(d[i]);
	keys.pb(0);sort(keys.begin(),keys.end());keys.resize(unique(keys.begin(),keys.end())-keys.begin());
	res.set(1,1);
	for(int i=0;i+1<keys.size();i++){
		//[keys[i],keys[i+1])
		tmp.reset();
		for(int j=1;j<=m;j++)if(d[j]<=keys[i])
			tmp.set(u[j],v[j]);
		tmp.set(n,n);
		if((res*(tmp^(keys[i+1]-keys[i]))).ask(1,n)){
			Floyd(keys[i]);
			return 0;
		}
		tmp.set(n,n,0);
		res=res*(tmp^(keys[i+1]-keys[i]));
	}
	Floyd(keys.back());
}