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
#define dec asfjhadsjhfkja
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
typedef double db;
const db eps=1e-8;
const int N=2e5+10;
int n,m,q,p[N],l[N],x[N],tot;db res;
priority_queue<pair<db,int>>add;//
priority_queue<pair<db,int>>dec;//1
db val(int id){return 1.*p[id]*x[id]/(x[id]+l[id]);}
db addval(int id){
	if(x[id]==l[id])return -1e18;
	return p[id]*(1.*(x[id]+1)/(x[id]+1+l[id])-1.*x[id]/(x[id]+l[id]));
}
db decval(int id){
	if(x[id]==0)return -1e18;
	return p[id]*(1.*(x[id]-1)/(x[id]-1+l[id])-1.*x[id]/(x[id]+l[id]));
}
void pop(){
	while(add.size()&&abs(addval(add.top().se)-add.top().fi)>eps)add.pop();
	while(dec.size()&&abs(decval(dec.top().se)-dec.top().fi)>eps)dec.pop();
}
void ins(int i){
	add.push(mp(addval(i),i));
	dec.push(mp(decval(i),i));
}
void adjust(){
	pop();
	while(tot<m&&add.top().fi>eps){
		tot++;res+=add.top().fi;x[add.top().se]++;
		ins(add.top().se);
		pop();
	}
	while(1){
		if(add.top().fi+dec.top().fi>eps){
			int a=add.top().se,b=dec.top().se;
			res-=val(a);res-=val(b);
			x[a]++;x[b]--;
			res+=val(a);res+=val(b);
			ins(a);ins(b);
			pop();
		}else break;
	}
}
signed main(){
	read(n,m,q);
	for(int i=1;i<=n;i++)read(p[i]);
	for(int i=1;i<=n;i++)read(l[i]);
	for(int i=1;i<=n;i++)ins(i);
	adjust();
	while(q--){
		int op,r;read(op,r);
		tot-=x[r];res-=val(r);
		if(op==1)l[r]++;else l[r]--;
		chkmn(x[r],l[r]);
		tot+=x[r];res+=val(r);ins(r);
		adjust();
		printf("%.10lf\n",res);
	}
}