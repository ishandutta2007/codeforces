#pragma GCC optimize(2)
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
const int N=3e3+100;
int r,c,n,k;
int x[N],y[N];vector<int>ps[N];
int L[N],R[N],pre[N],val[N],now;
int cnt[N],id[N];
int calc(int i){return (val[R[i]]-val[i])*pre[i];}
int arr1[20],len1,arr2[20],len2;
signed main(){
	read(r,c,n,k);
	for(int i=1;i<=n;i++)read(x[i],y[i]),ps[x[i]].pb(i);
	ll ans=0;
	for(int u=1;u<=r;u++){
		memset(cnt,0,sizeof cnt);
		cnt[0]=cnt[c+1]=1;
		for(int i=1;i<=n;i++)if(x[i]>=u)cnt[y[i]]++;
		for(int i=1;i<=c+1;i++)cnt[i]+=cnt[i-1];
		for(int i=1;i<=n;i++)if(x[i]>=u)val[id[i]=cnt[y[i]]--]=y[i];
		//id
		R[1]=2;val[1]=0;L[cnt[c+1]]=cnt[c];val[cnt[c+1]]=c+1;
		for(int i=2;i<cnt[c+1];i++)L[i]=i-1,R[i]=i+1;
		//pre
		for(int i=1;i<cnt[c+1];i++)
			if(i>=k)pre[i]=val[i-k+1];
			else pre[i]=0;
		now=0;
		for(int i=1;i<cnt[c+1];i++)now+=calc(i);
		int d=r;while(d>=u){
			ans+=now;
			for(auto x:ps[d]){
				int i=id[x];len1=len2=0;
				int cnt1=0,p=i;
				while(L[p]&&cnt1<k)cnt1++,p=L[p];
				while(p!=i)arr1[len1++]=p,p=R[p];
				int cnt2=0,q=i;
				while(R[q]!=cnt[c+1]&&cnt2<k)cnt2++,q=R[q],arr2[len2++]=q;
				now-=calc(L[i]);
				now-=calc(i);
				for(int i=0;i<len2;i++)now-=calc(arr2[i]),arr1[len1++]=arr2[i];
				for(int i=cnt1;i<len1;i++)pre[arr1[i]]=(i>=k-1)?val[arr1[i-k+1]]:0;
				for(int i=0;i<len2;i++)now+=calc(arr2[i]);
				L[R[i]]=L[i],R[L[i]]=R[i];
				now+=calc(L[i]);
			}d--;
		}
	}
	writeln(ans);
}