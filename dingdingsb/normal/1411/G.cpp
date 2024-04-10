// Problem: CF1411G No Game No Life
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1411G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
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
    modint<mod>(int o=0){x=(o+mod)%mod;}
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
typedef modint<998244353> mint;
const int N=100000+100;
int n,m;vector<int>f[N],g[N];
int sg[N],cnt[N],deg[N];mint F[N],inv;
void XOR(mint *f,int n,mint op=1){
	for(int o=2,k=1;o<=n;o<<=1,k<<=1)
		for(int i=0;i<n;i+=o)
			for(int j=0;j<k;j++)
				f[i+j]+=f[i+j+k],
				f[i+j+k]=f[i+j]-f[i+j+k]-f[i+j+k],
				f[i+j]*=op,f[i+j+k]*=op;
}
signed main(){
	read(n,m);mint inv=mint(1)/(n+1);
	for(int i=1;i<=m;i++){int u,v;read(u,v);f[u].pb(v);g[v].pb(u),deg[u]++;}
	queue<int>q;for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:g[u])deg[v]--,deg[v]==0&&(q.push(v),1);
		for(auto v:f[u])cnt[sg[v]]++;
		while(cnt[sg[u]])sg[u]++;F[sg[u]]-=inv;
		for(auto v:f[u])cnt[sg[v]]--;
	}
	F[0]++;
	XOR(F,512,1);
	for(int i=0;i<512;i++)F[i]=1/F[i];
	XOR(F,512,mint(1)/2);
	mint ans=1-inv*F[0];
	write(ans.x);
}