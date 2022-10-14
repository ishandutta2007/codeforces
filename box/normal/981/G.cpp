// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
using ll=long long;
const int MOD = 998244353;
int segt[1000006],lazadd[1000006],lazmul[1000006];
void tagadd(int idx,int l,int r,int v){
	(lazadd[idx]+=v)%=MOD;
	(segt[idx]+=1ll*(r-l)*v%MOD)%=MOD;
}
void tagmul(int idx,int l,int r,int v){
	lazadd[idx]=1ll*lazadd[idx]*v%MOD;
	lazmul[idx]=1ll*lazmul[idx]*v%MOD;
	segt[idx]=1ll*segt[idx]*v%MOD;
}
#define lson idx*2,l,(l+r)/2
#define rson idx*2+1,(l+r)/2,r
void pd(int idx,int l,int r){
	if(r-l==1)return;
	if(lazmul[idx]!=1){
		tagmul(lson,lazmul[idx]);
		tagmul(rson,lazmul[idx]);
		lazmul[idx]=1;
	}
	if(lazadd[idx]!=0){
		tagadd(lson,lazadd[idx]);
		tagadd(rson,lazadd[idx]);
		lazadd[idx]=0;
	}
}
void imul(int idx,int l,int r,int L,int R,int v){
	if(L<=l&&r<=R)return tagmul(idx,l,r,v);
	if(R<=l||r<=L)return;
	pd(idx,l,r);
	imul(lson,L,R,v);
	imul(rson,L,R,v);
	segt[idx]=(segt[idx*2]+segt[idx*2+1])%MOD;
}
void iadd(int idx,int l,int r,int L,int R,int v){
	if(L<=l&&r<=R)return tagadd(idx,l,r,v);
	if(R<=l||r<=L)return;
	pd(idx,l,r);
	iadd(lson,L,R,v);
	iadd(rson,L,R,v);
	segt[idx]=(segt[idx*2]+segt[idx*2+1])%MOD;
}
int isum(int idx,int l,int r,int L,int R){
	if(L<=l&&r<=R)return segt[idx];
	if(R<=l||r<=L)return 0;
	pd(idx,l,r);
	return (isum(lson,L,R)+isum(rson,L,R))%MOD;
}
#undef lson
#undef rson
struct ItvTree{
	struct itv{
		int l;
		mutable int r;
		int v;
		const bool operator<(const itv& o)const {
			if(l!=o.l)return l<o.l;
			return v<o.v;
		}
	};
	set<itv>res;
	int n;
	ItvTree(){}
	ItvTree(int N):n(N){
		res.insert({0,n,0});
	}
	set<itv>::iterator split(int L){
		auto pos=res.lower_bound({L,-1,-1});
		if(pos!=res.end()&&pos->l==L)return pos;
		pos--;
		int pr=pos->r;
		pos->r=L-1;
		return res.insert({L,pr,pos->v}).first;
	}
	void fix1(int L,int R){
		auto l=split(L),r=split(R+1);
		while(l!=r){
			if(l->v)imul(1,0,n,l->l,l->r+1,2);
			else iadd(1,0,n,l->l,l->r+1,1);
			l=res.erase(l);
		}
		res.insert({L,R,1});
	}
}vals[200005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,q;cin>>n>>q;
    rep1(i,n)vals[i]=ItvTree(n);
    rep(i,q){
    	int t,l,r;cin>>t>>l>>r;l--;r--;
    	if(t==1){
			int x;cin>>x;
			vals[x].fix1(l,r);
		}else{
			cout<<isum(1,0,n,l,r+1)<<'\n';
		}
	}
}