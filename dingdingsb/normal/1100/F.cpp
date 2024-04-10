#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
const int max_wei=30;
const int maxn=500000+10;
struct Prefix_Linear_Basis{
	ll p[max_wei+1];int pos[max_wei+1];
	inline void init(){memset(p,0,sizeof p);memset(pos,0,sizeof pos);}
	inline void insert(Prefix_Linear_Basis A,int w,ll val){
		*this=A;
		for(int i=max_wei;i>=0;i--)if(val>>i&1){
			if(!p[i]){p[i]=val,pos[i]=w;return;}
			else if(pos[i]<w){swap(pos[i],w);swap(p[i],val);}
			val^=p[i];
		}
	}
	inline ll Query(int l){
		//l
		ll ans=0;
		for(int i=max_wei;i>=0;i--)
			if(p[i]&&pos[i]>=l)ans=max(ans,ans^p[i]);
		return ans; 
	}
}a[maxn];
int n,q,x,l,r;
signed main(){
	read(n);a[0].init();
	for(int i=1;i<=n;i++)
		read(x),a[i].insert(a[i-1],i,x);
	read(q);
	while(q--){
		read(l,r);
		write(a[r].Query(l));
		putchar('\n');
	}
}