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
const int mod=1e9+7;
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define int ll
const int N=1e5+10,inf=2e9+10;
int n,a[N],suf[N],pw[N],L[N],fa[N],f[N],ans[N],ps[N],s[N],m;
vector<pair<int,int>>qry[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[y]=x;
	if((L[x]>30&&s[x]>0)||s[x]+(s[y]<<L[x])>=inf)
		s[x]=inf;
	else s[x]+=s[y]<<L[x];
	f[x]+=f[y]*pw[L[x]];
	f[x]%=mod;
	L[x]+=L[y];
}
int calc(int l,int r){return (suf[l]-suf[r+1]*pw[r-l+1])%mod;}
signed main(){
	read(n,m);pw[0]=1;for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<=n;i++)read(a[i]),f[i]=s[i]=a[i];
	for(int i=n;i;i--)suf[i]=(suf[i+1]*2+a[i])%mod;
	iota(fa+1,fa+1+n,1);fill(L+1,L+1+n,1);
	for(int i=1;i<=m;i++){
		int l,r;read(l,r);
		qry[r].eb(l,i);
	}
	for(int i=1;i<=n;i++){
		while(find(i)>1&&s[find(i)]>=0)merge(find(i)-1,i);
		ps[find(i)]=(ps[find(find(i)-1)]+f[find(i)])%mod;
		for(auto q:qry[i]){
			int l,id;tie(l,id)=q;
			ans[id]=(ps[find(i)]-ps[find(l)])*2+calc(l,find(l)+L[find(l)]-1);
			ans[id]=(ans[id]%mod+mod)%mod;
		}
	}
	for(int i=1;i<=m;i++)writeln(ans[i]);
}