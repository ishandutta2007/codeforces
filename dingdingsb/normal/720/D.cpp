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
const int mod=1e9+7;
const int N=1e6+10;
struct Seg_Tree{
	struct node{
		int l,r;
		int tag;//
		int sum; 
	}T[N*4];
	#define lson x<<1
	#define rson x<<1|1
	void build(int x,int l,int r){
		T[x].l=l,T[x].r=r;
		if(l==r)return;
		int mid=l+r>>1;
		build(lson,l,mid);
		build(rson,mid+1,r);
	}
	void pushup(int x){
		T[x].sum=(T[lson].sum+T[rson].sum)%mod;
	}
	void pushdown(int x){
		if(T[x].tag){
			T[lson].tag=T[rson].tag=1;
			T[lson].sum=T[rson].sum=0;
			T[x].tag=0;
		}
	}
	void upd(int x,int pos,int val){
		if(T[x].l==T[x].r){
			T[x].sum=val;
			return;
		}
		pushdown(x);
		int mid=T[x].l+T[x].r>>1;
		if(pos<=mid)upd(lson,pos,val);
		if( mid<pos)upd(rson,pos,val);
		pushup(x); 
	}
	void zero(int x,int l,int r){
		if(l<=T[x].l&&T[x].r<=r){
			T[x].tag=1;T[x].sum=0;
			return;
		}
		pushdown(x);
		int mid=T[x].l+T[x].r>>1;
		if(l<=mid)zero(lson,l,r);
		if(mid<r)zero(rson,l,r);
		pushup(x);
	}
	int qry(int x,int l,int r){
		if(l<=T[x].l&&T[x].r<=r)return T[x].sum;
		pushdown(x);
		int tmp=0,mid=T[x].l+T[x].r>>1;
		if(l<=mid)(tmp+=qry(lson,l,r))%=mod;
		if(mid<r)(tmp+=qry(rson,l,r))%=mod;
		return tmp;
	}
}seg;
int n,m,T;
vector<pair<int,int>>add[1000010],del[1000010];
set<pair<int,int>>s;
signed main(){
	read(n,m,T);
	while(T--){
		int X1,Y1,X2,Y2;
		read(X1,Y1,X2,Y2);
		add[X1].push_back(make_pair(Y1,Y2));
		del[X2+1].push_back(make_pair(Y1,Y2));
	}
	s.insert({0,0});
	for(auto Seg:add[1])
		s.insert(Seg);
	seg.build(1,1,m);
	seg.upd(1,1,1);
	for(int i=2;i<=n;i++){
		sort(add[i].begin(),add[i].end());
		reverse(add[i].begin(),add[i].end());
		for(auto Seg:add[i]){
			int x=Seg.first,y=Seg.second;
			if (y==m) continue;
			auto it=s.lower_bound(make_pair(y+2,0));it--;
			int ans=0;
			auto pr=*it;
			if(pr.second<=y)ans=seg.qry(1,pr.second+1,y+1);
			seg.upd(1,y+1,ans);
		}
		for(auto Seg:del[i])
			s.erase(Seg);
		for(auto Seg:add[i])
			s.insert(Seg),
			seg.zero(1,Seg.first,Seg.second);
	}
	auto it=s.end();it--;
	printf("%d",seg.qry(1,(*it).second+1,m));
}