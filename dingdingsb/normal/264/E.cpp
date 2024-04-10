#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10;
int n,m;
#define Range1 1,-m-10,20
#define Range2 1,1,n
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define pb push_back
struct SGT{
	#define mid ((l+r)>>1)
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mx v[x]
	signed v[N<<3];
	void up(int x){mx=max(v[lc],v[rc]);}
	void upd(int x,int l,int r,int pos,int val){return l==r?void(mx=val):((pos<=mid?upd(lc,l,mid,pos,val):upd(rc,mid+1,r,pos,val)),up(x));}
	int qry(int x,int l,int r,int mn){return mn<=l?mx:r<mn?0:max(qry(lc,l,mid,mn),qry(rc,mid+1,r,mn));}
}A,B;
int dp[N],ht[N];
//BA 
set<int>pos;
set<pair<int,int> >hei;
multiset<int>suf;
void add(int pos,int val){
	dp[pos]=val;
	::pos.insert(pos);
	hei.insert({ht[pos],pos});
	suf.insert(val);
	A.upd(Range1,ht[pos],val);
	B.upd(Range2,pos,val);
}
void del(int pos){
	::pos.erase(pos);
	hei.erase({ht[pos],pos});
	suf.erase(suf.lower_bound(dp[pos]));
	dp[pos]=0;
	A.upd(Range1,ht[pos],0);
	B.upd(Range2,pos,0);
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int op;scanf("%d",&op);
		if(op==1){
			int p,h;scanf("%d%d",&p,&h);
			ht[p]=h-=i;
			vector<int>num;
			for(auto [H,P]:hei){
				if(H>h)break;
				num.pb(P);
			}
			for(auto P:num)
				del(P);
			reverse(num.begin(),num.end());
			add(p,B.qry(Range2,p+1)+1);
			for(auto P:num)
				add(P,B.qry(Range2,P+1)+1);
		}else{
			int x;scanf("%d",&x);
			vector<int>num;
			for(auto P:pos){
				x--;
				if(!x){
					del(P);
					break;
				}
				num.pb(P);
			}
			for(auto P:num)
				del(P);
			reverse(num.begin(),num.end());
			for(auto P:num)
				add(P,A.qry(Range1,ht[P]+1)+1);
		}
		if(!suf.size())puts("0");else printf("%d\n",*suf.rbegin());
	}
}