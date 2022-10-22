#include<bits/stdc++.h>
#define mp make_pair
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
#define lowbit(x) ((x)&-(x))
const int N=1e5+100;
int n,fa[N],sz[N];
bool chk(int x){while(x)if(x%10!=7&&x%10!=4)return 0;else x/=10;return 1;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	sz[y]+=sz[x];fa[x]=y;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1,u,v,w;i<n;i++)
		read(u,v,w),(!chk(w))&&(merge(u,v),1);
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans+=1ll*(n-sz[find(i)])*(n-sz[find(i)]-1);
	write(ans);
}