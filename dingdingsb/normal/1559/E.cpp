// Problem: E. Mocha and Stars
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.ml/contest/1559/problem/E
// Memory Limit: 256 MB
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
typedef modint<998244353>mint;
const int N=1e5+100;
int n,m;
int l[N],r[N];
int pr[N],tot;bool npr[N];
int miu[N];
void init(){
	miu[1]=1;
	for(int i=2;i<N;i++){
		if(!npr[i])
			pr[++tot]=i,miu[i]=-1;
		for(int j=1;j<=tot&&i*pr[j]<N;j++){
			npr[i*pr[j]]=0;
			if(i%pr[j])miu[i*pr[j]]=-miu[i];
			else{
				miu[i*pr[j]]=0;
				break;
			}
		}
	}
}
mint dp[2][N],sum[2][N];mint f[N],h[N];
signed main(){
	init();
	read(n,m);
	for(int i=1;i<=n;i++)read(l[i],r[i]);
	mint ans=0;
	for(int k=1;k<=m;k++)if(miu[k]!=0){
		int now=0,lst=1;
		dp[now][0]=1;sum[now][0]=0;
		for(int j=1;j<=m/k+4;j++)
			sum[now][j]=1,dp[now][j]=0;
		for(int i=1;i<=n;i++){
			swap(now,lst);
			sum[now][0]=sum[now][1]=0;
			dp[now][0]=0;
			int st=((l[i]-1)/k+1);
			int ed=(r[i]/k);
			if(st>ed)goto loop;
			for(int j=1;j<=m/k;j++){
				dp[now][j]=0;
				int aa=max(0,j-st+1);
				int bb=max(0,j-ed);
				dp[now][j]=sum[lst][aa]-sum[lst][bb];
				/*for(int a=max(0,j-ed);a<=max(0,j-st);a++)
					dp[now][j]+=dp[lst][a];
				mint b=sum[lst][aa]-sum[lst][bb];
				if(dp[now][j].x!=b.x){
					printf("%d %d %d\n",k,i,j);
					//return 0;
				}*/
				sum[now][j+1]=sum[now][j]+dp[now][j];
			}
		}
		//ans+=mint(miu[k])*sum[now][m/k+1];
		//printf("%d\n",sum[now][m/k+1]);
		f[k]=sum[now][m/k+1];
		loop:;
	}
	for(int i=m-1;i;i--){
		h[i]=f[i];
		for(int j=2;i*j<=m;j++)
			h[i]-=h[i*j];
	}
	write(h[1].x);
}