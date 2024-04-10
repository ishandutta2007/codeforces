// Problem: C. Alice and the Cake
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}mint&operator/=(mint a){return*this*=(a^=mod-2);}
	friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}
	friend mint operator^(mint a, int b){return a^=b;}mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define int ll
const int N=2e5+100;
int t,n,a[N];
map<int,int>cnt;
signed main(){
	read(t);
	while(t--){
		read(n);cnt.clear();int sum=0;
		for(int i=1;i<=n;i++)read(a[i]),sum+=a[i],cnt[a[i]]++;
		int p1=1,p2=0;
		while(sum>1){
			int sm=min(p1,cnt[sum]);
			p1-=sm,cnt[sum]-=sm;
			int lg=min(p2,cnt[sum+1]);
			p2-=lg,cnt[sum+1]-=lg;
			if(sum&1)tie(p1,p2)=mp(p1,p1+p2+p2);
			else tie(p1,p2)=mp(p1+p1+p2,p2);
			sum/=2;
		}
		int c=min(p2,cnt[2]);
		if(p1+2*(p2-c)==cnt[1])puts("YES");
		else puts("NO");
	}
}