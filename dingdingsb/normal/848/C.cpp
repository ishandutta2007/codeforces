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
const int N=1e5+100;
int n,m,q;ll ans[N];
int a[N];set<int>pos[N];
class CDQ{
	private:
	class Tree{
		private:
		ll tree[N];
		public:
		void add(int x,int y){for(;x;x-=lowbit(x))tree[x]+=y;}
		ll qry(int x){ll res=0;for(;x<=n;x+=lowbit(x))res+=tree[x];return res;}
	}T;
	vector<tuple<int,int,int,int>>qs;
	// 0 a b val
	// 1 <=a >=b id
	void cdq(int l,int r){
		if(l>=r)return;
		cdq(l,mid);cdq(mid+1,r);
		vector<tuple<int,int,int>>L,R;
		for(int i=l;i<=mid;i++)if(!get<0>(qs[i]))L.eb(get<1>(qs[i]),get<2>(qs[i]),get<3>(qs[i]));
		for(int i=mid+1;i<=r;i++)if(get<0>(qs[i]))R.eb(get<1>(qs[i]),get<2>(qs[i]),get<3>(qs[i]));
		sort(L.begin(),L.end());sort(R.begin(),R.end());
		int i=0,j=0;
		for(;i<(int)R.size();i++){
			while(j<(int)L.size()&&get<0>(L[j])<=get<0>(R[i]))
				T.add(get<1>(L[j]),get<2>(L[j])),j++;
			ans[get<2>(R[i])]+=T.qry(get<1>(R[i]));
		}
		while(j--)T.add(get<1>(L[j]),-get<2>(L[j]));
	}
	public:
	void add(int op,int x,int y,int val){qs.eb(op,x,y,val);}
	void work(){cdq(0,(int)qs.size()-1);}
}WYH;
void add(int pre,int i,int op){
	if(pre==0||i==n+1)return;
	WYH.add(0,i,pre,op*(i-pre));
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]),pos[a[i]].insert(i),pos[i].insert(0),pos[i].insert(n+1);
	for(int i=1;i<=n;i++)add(*prev(pos[a[i]].find(i)),i,1);
	for(int i=1;i<=m;i++){
		int op,x,y;read(op,x,y);
		if(op==1){
			auto it=pos[a[x]].find(x);
			add(*prev(it),x,-1);
			add(x,*next(it),-1);
			add(*prev(it),*next(it),1);
			pos[a[x]].erase(x);
			it=pos[a[x]=y].insert(x).fi;
			add(*prev(it),*next(it),-1);
			add(*prev(it),x,1);
			add(x,*next(it),1);
		}else{
			q++;
			WYH.add(1,y,x,q);
		}
	}
	WYH.work();
	for(int i=1;i<=q;i++)writeln(ans[i]);
}