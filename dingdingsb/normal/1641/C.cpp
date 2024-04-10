// : caigou
// : 2022-02-23 19:29

#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=2e5+100;
int n,q;
int L[N],R[N];set<int>now;
namespace SGT{
	set<int>rpos[N<<2];
	void add(int x,int l,int r,int pos,int val){
		rpos[x].insert(val);
		if(l==r)return;
		if(pos<=mid)add(lc,l,mid,pos,val);
		else add(rc,mid+1,r,pos,val);
	}
	int qry(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l&&r<=qr){
			auto it=rpos[x].lower_bound(val);
			if(it==rpos[x].end())return 0x3f3f3f3f;
			else return *it;
		}
		if(r<ql||qr<l)return 0x3f3f3f3f;
		return min(qry(lc,l,mid,ql,qr,val),qry(rc,mid+1,r,ql,qr,val));
	}
};
int st[N];//0 1 2
void upd(int x){
	if(x!=0&&x!=n+1&&st[x]!=1){
		if(SGT::qry(1,1,n,L[x]+1,x,x)<R[x])
			st[x]=1;
	}
}
void del(int x){
	st[x]=2;L[R[x]]=L[x];R[L[x]]=R[x];
	upd(L[x]);upd(R[x]);now.erase(x);
}
signed main(){
	read(n,q);
	for(int i=1;i<=n;i++)now.insert(i),L[i]=i-1,R[i]=i+1;
	while(q--){
		int op,l,r,x;read(op);
		if(!op){
			read(l,r,x);
			if(!x){
				auto it=now.lower_bound(l);
				while(it!=now.end()&&*it<=r)
					del(*it),it=now.lower_bound(l);
			}else{
				SGT::add(1,1,n,l,r);
				auto it=now.lower_bound(l);
				if(it!=now.end()&&r<R[*it])st[*it]=1;
			}
		}else{
			read(x);
			if(st[x]==0)puts("N/A");
			else if(st[x]==1)puts("YES");
			else puts("NO");
		}
	}
}