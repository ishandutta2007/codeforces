// Problem: CF12D Ball
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF12D
// Memory Limit: 250 MB
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
const int N=5e5+100;
int n,a[N],b[N],c[N];tuple<int,int,int>p[N],A[N],B[N];
bool die[N];
void solve(int l1,int r1,int l2,int r2){
	if(l1>r1||l2>r2)return;//
	int acnt=0,bcnt=0;
	for(int i=l1;i<=r1;i++)A[++acnt]=mt(get<1>(p[i]),get<2>(p[i]),i);
	for(int i=l2;i<=r2;i++)B[++bcnt]=mt(get<1>(p[i]),get<2>(p[i]),i);
	sort(A+1,A+acnt+1);sort(B+1,B+bcnt+1);
	int mx=0;
	for(int i=acnt,j=bcnt+1;i;i--){
		while(j>1&&get<0>(B[j-1])>get<0>(A[i]))j--,chkmx(mx,get<1>(B[j]));
		if(mx>get<1>(A[i]))die[get<2>(A[i])]=1;
	}
}
void cdq(int l,int r){
	if(l==r)return;
	cdq(l,mid);cdq(mid+1,r);
	if(get<0>(p[mid])==get<0>(p[mid+1])){
		int L=mid,R=mid+1;
		while(L>l&&get<0>(p[L-1])==get<0>(p[mid]))L--;
		while(R<r&&get<0>(p[R+1])==get<0>(p[mid]))R++;
		solve(l,L-1,mid+1,r);
		solve(L,mid,R+1,r);
	}else solve(l,mid,mid+1,r);
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	for(int i=1;i<=n;i++)read(c[i]);
	for(int i=1;i<=n;i++)p[i]=mt(a[i],b[i],c[i]);
	sort(p+1,p+1+n);
	cdq(1,n);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=die[i];
	write(ans);
}