//
#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
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
typedef __int128 lll;
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
char s[50];int m;
int n;lll f;
lll mul(lll x,lll y){
	lll res=0;
	for(int i=0;i<n;i++)if(y>>i&1)
		res^=x<<i;
	for(int i=2*n;i>=n;i--)if(res>>i&1)
		res^=f<<(i-n);
	return res;
}
map<lll,int>vis;
signed main(){
	scanf("%s",s+1);int l=strlen(s+1);
	for(int i=1;i<=l;i++)if(s[i]=='1'){
		for(int j=i;j<=l;j++)if(s[j]=='1')
			f|=(lll)1<<(j-i),n=j-i;
		m=i;break;
	}
	if(!m)return writeln(-1),0;
	if(!n)return writeln(m,m+1),0;
	lll x=1;
	for(int i=0;i<(1<<17);i++,x=mul(x,2))vis[x]=i;
	lll y=x;
	for(int i=1;i<=(1<<17);i++,x=mul(x,y))if(vis.count(x))
		return writeln(m,m+((ll)i<<17)-vis[x]),0;
}