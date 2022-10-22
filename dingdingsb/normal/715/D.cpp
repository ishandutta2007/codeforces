// : caigou
// : 2022-03-03 13:14

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
const int N=60;
const int UP=50;
vector<pair<pair<int,int>,pair<int,int>>>ans;
ll n;int num[N];
signed main(){
	read(n);int now=1;
	while(n)num[now++]=n%6,n/=6;
	ans.pb(mp(mp(1,2),mp(2,2)));
	ans.pb(mp(mp(2,1),mp(2,2)));
	for(int i=2;i<UP;i+=2){
		//(i,i)
		#define three1 ans.pb(mp(mp(i-1,i+1),mp(i,i+1)))
		#define one1 ans.pb(mp(mp(i-1,i+2),mp(i,i+2)))
		#define three2 ans.pb(mp(mp(i+1,i-1),mp(i+1,i)))
		#define one2 ans.pb(mp(mp(i+2,i-1),mp(i+2,i)))
		//num[(UP-i)/2]
		int x=num[(UP-i)/2];
		if(x==0)three1,three2,one1,one2;
		if(x==1)three1,three2,one1;
		if(x==2)three1,three2;
		if(x==3)three1,one1,one2;
		if(x==4)three2,one2;
		if(x==5)three1;
		if(i!=UP-2){
			ans.pb(mp(mp(i,i+2),mp(i,i+3)));
			ans.pb(mp(mp(i+1,i+2),mp(i+1,i+3)));
			ans.pb(mp(mp(i+2,i),mp(i+3,i)));
			ans.pb(mp(mp(i+2,i+1),mp(i+3,i+1)));
		}
		if(i!=2){
			ans.pb(mp(mp(i-1,i+2),mp(i-2,i+2)));
			ans.pb(mp(mp(i+2,i-1),mp(i+2,i-2)));
			if(i!=UP-2){
				ans.pb(mp(mp(i-1,i+3),mp(i-2,i+3)));
				ans.pb(mp(mp(i+3,i-1),mp(i+3,i-2)));
			}
		}
	}
	writeln(UP,UP);
	writeln(ans.size());
	for(auto kk:ans){
		if(kk.fi.fi>kk.se.fi||kk.fi.se>kk.se.se)swap(kk.fi,kk.se);
		writeln(kk.fi.fi,kk.fi.se,kk.se.fi,kk.se.se);
	}
	return 0;
	cout<<"luogu tdxy"<<endl;
	cout<<"";
}