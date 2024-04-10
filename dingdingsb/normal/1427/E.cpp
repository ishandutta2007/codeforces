#include<bits/stdc++.h>
#define pc putchar
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
vector<tuple<int,char,int>>ot;
int calc(int x){
	int mx=0;
	for(int i=0;i<32;i++)if(x>>i&1)mx=i;
	int y=x;while(mx--)ot.pb(mt(y,'+',y)),y*=2;
	int z=y^x;ot.pb(mt(y,'^',x));
	int r=y+z;ot.pb(mt(y,'+',z));
	int _2y=y+y;ot.pb(mt(y,'+',y));
	int p=r^_2y;ot.pb(mt(r,'^',_2y));
	int q=p^x;ot.pb(mt(p,'^',x));
	int kk=x/2;
	while(kk){
		if(kk&1){
			ot.pb(mt(y,'^',q));
			y^=q;
		}
		kk>>=1;
		ot.pb(mt(q,'+',q));
		q*=2;
	}
	assert(__builtin_popcount(y)==1);
	assert(y&x);
	ot.pb(mt(x,'^',y));
	return x^y;
}
signed main(){
	int x;read(x);
	while(x!=1)x=calc(x);
	write(ot.size());pc('\n');
	for(auto [x,op,y]:ot)write(x),pc(' '),pc(op),pc(' '),write(y),pc('\n');
}