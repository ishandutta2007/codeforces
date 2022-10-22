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
mt19937 rnd(random_device{}());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e5+10;
int n,m,h,t,tim,w[N],W[N];
vector<int>e[N],ans;
signed main(){
	read(n,m,h,t);
	for(int i=1,u,v;i<=m;i++)read(u,v),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;i++)if((int)e[i].size()>h){
		for(auto j:e[i])w[j]=i;
		for(auto j:e[i]){
			tim++;
			int p=e[i].size()-1-h,q=0;ans.clear();
			for(auto k:e[j]){
				if(k!=i){
					if(p&&w[k]==i)p--,q++,ans.pb(k),W[k]=tim;
					else if(w[k]!=i)q++,ans.pb(k),W[k]=tim;
				}
				if(q==t)break;
			}
			if(q==t){
				puts("YES");
				writeln(i,j);
				int p=0;
				for(auto k:e[i])if(k!=j&&W[k]!=tim){
					p++;write(k),pc(' ');
					if(p==h)break;
				}
				pc('\n');
				for(auto k:ans)write(k),pc(' ');
				return 0;
			}
		}
	}
	puts("NO");
	cerr<<""<<endl;
	
}