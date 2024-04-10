#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

class segtree
{
public:
	int seg[(1<<21)];
	int lazy[(1<<21)];
	int s;
	void init(int sz){
		s = 1;
		while(sz+5 > s) s <<= 1;
		fill(seg,seg+2*s,0);
		fill(lazy,lazy+2*s,0);
	}
	void lazy_evaluate(int k)
	{
		if(k*2+2>=s*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2]+=lazy[k];
		seg[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	int update(int beg,int end,int idx,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx]+=num;
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return seg[idx]=max(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	int update(int beg,int end,int num){
		return update(beg,end,0,0,s-1,num);
	}
	int query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return -1000000007;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return max(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
	int query(int beg,int end){
		return query(beg,end,0,0,s-1);
	}
}kaede;

int q,n;
int m,lim,c;
vector<int>za;
vector<P>query[1000005];
int t[500005],a[500005],b[500005];
typedef pair<P,int> Q;

signed main(){
	q=1;
	while(q--){
		scanf("%d%d%d",&m,&lim,&n);
		c=lim;
		za.clear();
		za.pb(0); za.pb(m-1);
		rep(i,n){
			scanf("%d%d",&t[i],&b[i]);
			a[i]=lim;
			za.pb(t[i]); za.pb(t[i]-1);
		}
		SORT(za); ERASE(za);
		rep(i,za.size()) query[i].clear();
		rep(i,n){
			t[i] = POSL(za,t[i]);
			query[t[i]].pb(P(b[i],a[i]));
		}
		kaede.init(za.size());
		for(int i=0;i<za.size();i++){
			int val = c - (za[i]);
			kaede.update(i,i,val);
		}
		priority_queue<Q,vector<Q>,greater<Q>>que;
		long long ans = 0;
		bool fail = 0;
		for(int i=0;i<za.size();i++){
			rep(j,query[i].size()){
				que.push(Q(query[i][j],i));
			}
			int val = kaede.query(i,i); 
			if(val > 0) continue;
			int need = 1-val;
			while(!que.empty() && need > 0){
				Q p = que.top(); que.pop();
				long long cost = p.fi.fi;
				int zan = p.fi.sc;
				int beg = p.sc;
				int rem = kaede.query(beg,za.size()-1);
				rem = lim-rem;
				rem = min(rem,zan);
				if(need <= rem){
					kaede.update(beg,za.size()-1,need);
					ans += 1LL*need*cost; 
					if(zan-need > 0) que.push(Q(P(cost,zan-need),beg));
					need = 0;
				}
				else{
					kaede.update(beg,za.size()-1,rem);
					ans += 1LL*rem*cost; need -= rem;
				}
			}
			if(need > 0){
				fail = 1;
				break;
			}
		}
		if(fail) puts("-1");
		else printf("%lld\n",ans);
	}
}