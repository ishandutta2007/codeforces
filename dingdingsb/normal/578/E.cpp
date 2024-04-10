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
const int N=1e5+100;
int n,cnt,a[N];char s[N];
vector<int>id[2];vector<int>pos[N];
vector<int>ids[2][2];
void work(){
	for(int i=1;i<=cnt;i++)
		ids[a[pos[i].front()]][a[pos[i].back()]].pb(i);
}
void pr(vector<int>p){for(auto x:p)write(x),pc(' ');}
void adjust(){
	int id01=0,id10=0;
	for(int i=1;i<=cnt;i++)if(a[pos[i].front()]==0&&a[pos[i].back()]==1)id01=i;
	for(int i=1;i<=cnt;i++)if(a[pos[i].front()]==1&&a[pos[i].back()]==0)id10=i;
	if(!id01||!id10)return;
	if(pos[id01].back()<pos[id10].back())pos[id01].pb(pos[id10].back()),pos[id10].pop_back();
	else pos[id10].pb(pos[id01].back()),pos[id01].pop_back();
}
signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++){
		a[i]=s[i]=='R';
		if(!id[a[i]^1].size())id[a[i]^1].pb(++cnt);
		pos[id[a[i]^1].back()].pb(i);
		id[a[i]].pb(id[a[i]^1].back());
		id[a[i]^1].pop_back();
	}
	writeln(cnt-1);
	adjust();
	work();
	if(ids[0][0].size()>ids[1][1].size()){
		while(ids[1][1].size())
			pr(pos[ids[0][0].back()]),pr(pos[ids[1][1].back()]),
			ids[0][0].pop_back(),ids[1][1].pop_back();
		for(auto i:ids[0][1])pr(pos[i]);
		pr(pos[ids[0][0][0]]);
		for(auto i:ids[1][0])pr(pos[i]);
	}else if(ids[0][0].size()==ids[1][1].size()){
		if(!ids[0][0].size()){
			for(int i=1;i<=cnt;i++)pr(pos[i]);
			return 0;
		}
		while(ids[0][0].size()>1)
			pr(pos[ids[0][0].back()]),pr(pos[ids[1][1].back()]),
			ids[0][0].pop_back(),ids[1][1].pop_back();
		for(auto i:ids[0][1])pr(pos[i]);
		pr(pos[ids[0][0][0]]);
		for(auto i:ids[1][0])pr(pos[i]);
		pr(pos[ids[1][1][0]]);
	}else{
		while(ids[0][0].size())
			pr(pos[ids[1][1].back()]),pr(pos[ids[0][0].back()]),
			ids[1][1].pop_back(),ids[0][0].pop_back();
		for(auto i:ids[1][0])pr(pos[i]);
		pr(pos[ids[1][1][0]]);
		for(auto i:ids[0][1])pr(pos[i]);
	}
}