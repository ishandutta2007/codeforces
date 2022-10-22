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
int T,n[63],m[63];
ll dp[63][2][2][2];
void input(int*arr){
	ll x;read(x);int l=0;
	while(x)arr[l++]=x&1,x>>=1;
}
ll dfs(int pos,int lim,int jin,int mod2){
	if(pos==-1)
		return !lim&&!jin&&!mod2;
	ll&res=dp[pos][lim][jin][mod2];
	if(res!=-1)return res;
	res=0;
	for(int i=0;i<=(lim?m[pos]:1);i++)
		for(int j=0;j<2;j++)
			if((j+i+n[pos])/2==jin)
				res+=dfs(pos-1,lim&&(i==m[pos]),j,mod2^(i^((j+i+n[pos])&1)));
	return res;
}
signed main(){
	read(T);while(T--){
		memset(n,0,sizeof n);memset(m,0,sizeof m);
		memset(dp,0xff,sizeof dp);
		input(n);input(m);
		writeln(dfs(62,1,0,1));
	}
}