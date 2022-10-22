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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
#define lowbit(x) ((x)&-(x))
#define lc (x<<1)
#define rc (x<<1|1)
const int N=2.5e3+100;
int n,m,k,a[N][N];char s[N];ll ans;
int sum(int x1,int x2,int y1,int y2,int dir){
	if(dir)swap(x1,y1),swap(x2,y2);
	return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
}
void solve(int x1,int x2,int y1,int y2,int dir){
	if(x1>x2||y1>y2)return;
	if(y2-y1>x2-x1)swap(x1,y1),swap(x2,y2),dir^=1;
	int mid=(x1+x2)>>1;
	static int L[10],R[10];
	for(int i=y1;i<=y2;i++){
		for(int j=0;j<=k;j++)L[j]=x1,R[j]=x2;
		for(int j=i;j<=y2;j++){
			for(int w=0;w<=k;w++){
				while(sum(L[w],mid,i,j,dir)>w)L[w]++;
				while(sum(mid+1,R[w],i,j,dir)>w)R[w]--;
			}
			for(int w=0;w<=k;w++)
				ans+=((w?L[w-1]:mid+1)-L[w])*(R[k-w]-(k-w?R[k-w-1]:mid-1));
		}
	}
	solve(x1,mid-1,y1,y2,dir);
	solve(mid+1,x2,y1,y2,dir);
}
signed main(){
	read(n,m,k);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+s[j]-'0';
	}
	solve(1,n,1,m,0);
	writeln(ans);
	return 0;
    cerr<<""<<endl;
}