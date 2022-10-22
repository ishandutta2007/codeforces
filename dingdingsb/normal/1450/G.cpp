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
const int N=5e3+5,M=27;
int n,a,b,id[N],tot,l[M],r[M],c[M],f[1<<20],cnt;
char s[N],ans[N];
signed main(){
	read(n,a,b);scanf("%s",s+1);
	memset(id,0xff,sizeof id);f[0]=1;
	for(int i=1;i<=n;i++){
		int k=s[i]-'a';
		if(id[k]==-1)l[id[k]=tot++]=i;
		r[id[k]]=i,c[id[k]]++;
	}
	for(int s=1;s<(1<<tot);s++){
		int L=n,R=0,m=0,t=0;bool flag=0;
		for(int i=0;i<tot;i++)if(s>>i&1){
			t|=1<<i;f[s]|=f[t]&&f[s^t];
			chkmn(L,l[i]);chkmx(R,r[i]),m+=c[i];
			flag|=f[s^(1<<i)];
		}
		f[s]|=(flag&&a*(R-L+1)<=b*m);
	}
	for(int i=0;i<tot;i++)
		if(f[((1<<tot)-1)^(1<<i)])
			ans[++cnt]=s[l[i]];
	sort(ans+1,ans+1+cnt);
	write(cnt);pc(' ');
	for(int i=1;i<=cnt;i++)pc(ans[i]),pc(' ');
	cerr<<"CF";
}