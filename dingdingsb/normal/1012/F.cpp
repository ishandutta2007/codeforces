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
const int N=22,inf=0x3f3f3f3f;
int n,p,f[1<<N],lst[1<<N],id[N],t[N];
struct node{
	int l,r,t,id;
	bool operator<(const node rhs)const{return l<rhs.l;}
}c[N];
void solve(int i,int S){
	for(;S;S^=(1<<lst[S]))
		id[c[lst[S]].id]=i,
		t[c[lst[S]].id]=f[S]-c[lst[S]].t;
}
void out(){
	puts("YES");
	for(int i=0;i<n;i++)
		writeln(id[i],t[i]);
}
signed main(){
	read(n,p);
	for(int i=0;i<n;i++)read(c[i].l,c[i].r,c[i].t),c[i].r+=c[i].l-1,c[i].id=i;
	sort(c,c+n);
	memset(f,0x3f,sizeof f);f[0]=1;
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++)if(i>>j&1){
			int v=f[i^(1<<j)];
			for(int k=0;k<n;k++){
				if(v>=c[k].l)chkmx(v,c[k].r+1);
				else if(v+c[j].t>=c[k].l&&((i>>k)&1))v=c[k].r+1;
			}
			if(v+c[j].t<c[j].l&&v+c[j].t<f[i])
				f[i]=v+c[lst[i]=j].t;
		}
	}
	if(p==1){
		if(f[(1<<n)-1]<inf)solve(1,(1<<n)-1),out();
		else puts("NO");
	}else{
		for(int i=0;i<(1<<n);i++)
			if(f[i]<inf&&f[((1<<n)-1)^i]<inf)
				return solve(1,i),solve(2,((1<<n)-1)^i),out(),0;
		puts("NO");
	}
	cerr<<"";
}