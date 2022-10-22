// Problem: You
// Contest: Codeforces
// URL: https://m1.codeforces.ml/contest/1554/problem/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
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
typedef modint<998244353>mint;
const int N=100000+100;
int t,n,k;mint h[N],f[N];int dp[N];bool flag;
vector<int>e[N];
void dfs(int u,int fa){
	for(auto v:e[u])if(v!=fa)
		dfs(v,u);
	if(dp[u]%k!=0){
		if(fa)dp[u]++;
		if(dp[u]%k!=0)flag=false;
	}else dp[fa]++;
}
signed main(){
	read(t);
	while(t--){
		read(n);for(int i=1;i<=n;i++)e[i].clear(),h[i]=f[i]=0;
		f[1]=mint(2)^n-1;
		for(int i=1;i<n;i++){
			int u,v;read(u,v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(k=2;k<n;k++)if((n-1)%k==0){
			for(int i=1;i<=n;i++)dp[i]=0;
			flag=1;dfs(1,0);f[k]=flag;
		}
		for(int i=n-1;i;i--){
			h[i]=f[i];
			for(int j=2;i*j<n;j++)
				h[i]-=h[i*j];
		}
		for(int i=1;i<=n;i++)write(h[i].x),putchar(' ');
		putchar('\n');
	}
	return 0;
	cout<<"ccfn***";
}