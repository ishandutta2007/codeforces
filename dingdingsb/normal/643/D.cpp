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
const int N=3e5+100;
int n,m;
int f[N],deg[N];
ll sum[N],t[N];
//t[i]
ll calcself(int i){return t[i]-t[i]/(deg[i]+2)*(deg[i]+1);}
//t[i]
ll calcson(int i){return t[i]/(deg[i]+2);}
multiset<ll>s[N];//
multiset<ll>S;//
void add(int i){
	if(!s[i].size())return;
	S.insert(*s[i].begin()+calcson(i));
	S.insert(*s[i].rbegin()+calcson(i));
}
void del(int i){
	if(!s[i].size())return;
	S.erase(S.find(*s[i].begin()+calcson(i)));
	S.erase(S.find(*s[i].rbegin()+calcson(i)));
}
void mdf(int x,int y){
	//f[x]y
	//needsum
	//fneeds
	set<int>need={x,f[x],f[f[x]],y,f[y]},fneed;
	fneed=need;for(auto i:need)fneed.insert(f[i]);
	for(auto i:fneed)del(i);
	for(auto i:need)s[f[i]].erase(s[f[i]].find(sum[i]));
	for(auto i:need){
		sum[i]-=calcself(i);
		for(auto j:need)if(f[j]==i)sum[i]-=calcson(j);
	}
	deg[f[x]]--,deg[f[x]=y]++;
	for(auto i:need){
		sum[i]+=calcself(i);
		for(auto j:need)if(f[j]==i)sum[i]+=calcson(j);
	}
	for(auto i:need)s[f[i]].insert(sum[i]);
	for(auto i:fneed)add(i);
}
signed main(){
	//freopen("1.in","r",stdin);
	read(n,m);
	for(int i=1;i<=n;i++)read(t[i]);
	for(int i=1;i<=n;i++)read(f[i]),deg[f[i]]++;
	for(int i=1;i<=n;i++)sum[i]+=calcself(i),sum[f[i]]+=calcson(i);
	for(int i=1;i<=n;i++)s[f[i]].insert(sum[i]);
	for(int i=1;i<=n;i++)add(i);
	while(m--){
		int op;read(op);
		if(op==1){
			int i,j;read(i,j);
			mdf(i,j);
		}else if(op==2){
			int i;read(i);
			writeln(sum[i]+calcson(f[i]));
		}else writeln(*S.begin(),*S.rbegin());
	}
}