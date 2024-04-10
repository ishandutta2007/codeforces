// Problem: CF149D Coloring Brackets
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF149D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
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
const int N=7e2+10;
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
const int mod=1e9+7;
using mint=modint<mod>;
int n,l[N];stack<int>st;
char s[N];
mint dp[N][N][3][3];
signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='(')st.push(i);
		else l[i]=st.top(),st.pop();
	assert(st.size()==0);
	for(int i=1;i<=n;i++)
		if(s[i]==')'&&l[i]==i-1)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)if(j+k&&(!j||!k))
					dp[i-1][i][j][k]=1;
	for(int len=4;len<=n;len+=2)
		for(int i=1,j=len;j<=n;i++,j++)if(s[j]==')')
			if(l[j]>i){
				for(int a=0;a<3;a++)
					for(int b=0;b<3;b++)
						for(int c=0;c<3;c++)
							for(int d=0;d<3;d++)
								if(!b||!c||b!=c)
									dp[i][j][a][d]+=dp[i][l[j]-1][a][b]*dp[l[j]][j][c][d];
			}else if(l[j]==i){
				for(int a=0;a<3;a++)
					for(int b=0;b<3;b++)
						for(int c=0;c<3;c++)
							for(int d=0;d<3;d++)
								if(!a||!b||a!=b)
									if(!c||!d||c!=d)
										if(a+d&&(!a||!d))
											dp[i][j][a][d]+=dp[i+1][j-1][b][c];
			}
	mint ans=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ans+=dp[1][n][i][j];
	write(ans.x);
}