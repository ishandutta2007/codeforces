// Problem: CF1097G Vladislav and a Great Legend
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1097G
// Memory Limit: 500 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
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
typedef modint<1000000007>mint;
const int N=1e5+10,K=210;
int n,k;vector<int>e[N];int sz[N];
mint dp[N][K],f[K],ans[K],S[K][K];
void dfs(int u,int fa){
	sz[u]=1;dp[u][0]=1;
	for(auto v:e[u])if(v!=fa){
		dfs(v,u);
		memcpy(f,dp[u],sizeof f);
		for(int i=1;i<=k;i++)
			dp[u][i]+=dp[v][i]+dp[v][i-1];
		dp[u][0]+=dp[v][0];
		for(int i=0;i<=k&&i<=sz[u];i++)
			for(int j=0;j<=k-i&&j<=sz[v];j++){
				mint val=f[i]*dp[v][j];
				dp[u][i+j]+=val;
				ans[i+j]+=val;
				dp[u][i+j+1]+=val;
				ans[i+j+1]+=val;
			}
		sz[u]+=sz[v];
	}
}
signed main(){
	read(n,k);
	for(int i=1,x,y;i<n;i++)
		read(x,y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	S[1][1]=1;
	for(int i=2;i<=k;i++)
		for(int j=1;j<=k;j++)
			S[i][j]=S[i-1][j-1]+j*S[i-1][j];
	mint fac=1,Ans=0;
	for(int i=1;i<=k;i++,fac*=i)
		Ans+=ans[i]*fac*S[k][i];
	write(Ans.x);
}