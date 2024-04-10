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
	mint operator-(){return 0-*this;}bool operator==(const mint b)const{return x==b.x;}
};
mt19937 rnd(random_device{}());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e5+10;
int n,m,a[N];char s[N];ll dp[N][8];
int trans(int st,int i,int c){
	array<int,3>lst,now;
	lst[0]=i-2+(st&1);
	lst[1]=i-1+(st>>1&1);
	lst[2]=i-1+(st>>2&1);
	now[0]=max(lst[1],lst[0]+(c==a[i]));
	now[1]=max(max(lst[2],now[0]),lst[1]+(c==a[i+1]));
	now[2]=max(now[1],lst[2]+(c==a[i+2]));
	if(now[0]<i-1||now[1]<i||now[2]<i)return -1;
	return (now[0]-(i-1))|((now[1]-i)<<1)|((now[2]-i)<<2);
}
signed main(){
	read(n,m);scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'a'+1;
	for(int i=1;i<=m;i++)dp[1][1|((i==a[1])<<1)|((i==a[1]||i==a[2])<<2)]++;
	for(int i=1;i<n;i++)for(int j=0;j<8;j++)if(dp[i][j])
		for(int c=1,v;c<=m;c++)if(~(v=trans(j,i,c)))
			dp[i+1][v]+=dp[i][j];
	writeln(dp[n][0]+dp[n][1]+dp[n][4]+dp[n][5]);
	cerr<<""<<endl;
}