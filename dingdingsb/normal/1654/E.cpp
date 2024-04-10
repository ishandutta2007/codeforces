// Problem: E. Arithmetic Operations
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.ml/contest/1654/problem/E
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
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
const int N=1e5+1e2,B=80;
unordered_map<int,int>kk;
int n,a[N],ans=0;
int buc[2*N];
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int j=-B;j<=B;j++){
		kk.clear();
		for(int i=1;i<=n;i++)
			kk[a[i]-j*i]++;
		for(auto tmp:kk)
			chkmx(ans,tmp.se);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=i+N/B&&j<=n;j++)
			if((a[j]-a[i])%(j-i)==0){
				buc[(a[j]-a[i])/(j-i)+N]++;
				chkmx(ans,buc[(a[j]-a[i])/(j-i)+N]+1);
			}
		for(int j=i+1;j<=i+N/B&&j<=n;j++)
			if((a[j]-a[i])%(j-i)==0)
				buc[(a[j]-a[i])/(j-i)+N]--;
	}
	writeln(n-ans);
}