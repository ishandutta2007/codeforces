#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,INF=1e9;
struct SegmentTree{
	ll tree[MAXN<<2],lc[MAXN<<2],rc[MAXN<<2];
	void pushup(int x){
		tree[x]=max(tree[lc[x]],tree[rc[x]]);
	}
	void build(int x,int l,int r){
		if(l==r){
			return;
		}
		int mid=(l+r)>>1;lc[x]=x*2;rc[x]=lc[x]+1;
		build(lc[x],l,mid);build(rc[x],mid+1,r);
		pushup(x);
	}
	void update(int x,int l,int r,int pos,int val){
		if(l==r){
			tree[x]=val;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)update(lc[x],l,mid,pos,val);
		else update(rc[x],mid+1,r,pos,val);
		pushup(x);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(ql>qr)return 0;
		if(ql<=l && qr>=r)return tree[x];
		int mid=(l+r)>>1,ans=0; 
		if(ql<=mid)ans=max(ans,query(lc[x],l,mid,ql,qr));
		if(qr>mid)ans=max(ans,query(rc[x],mid+1,r,ql,qr));
		pushup(x);
		return ans;
	}
}tree,tree2;
ll n,m,op[MAXN],x[MAXN],h[MAXN],d[MAXN],tot;
vector<pi>tmp;
set<pi>s1,s2; //s1s2 
int main(){
	cin>>n>>m;
	rep(i,1,m){
		cin>>op[i];
		if(op[i]==1){
			cin>>x[i];
			cin>>h[x[i]];
			h[x[i]]-=i;
			d[++tot]=h[x[i]];
		}else{
			cin>>x[i];
		}
	}
	sort(d+1,d+1+tot);
	tot=unique(d+1,d+1+tot)-d-1; //
	rep(i,1,n){
		h[i]=lower_bound(d+1,d+1+tot,h[i])-d;
	} 
	tree.build(1,1,n);
	tree2.build(1,1,tot); 
	rep(i,1,m){
		if(op[i]==1){
			s1.is(mp(x[i],x[i]));
			s2.is(mp(h[x[i]],x[i]));
		//	printf("%d%d\n",x[i],h[x[i]]);
			//f[x]
			// 
			tmp.clear(); 
			set<pi>::iterator it=s2.begin();
			while(1){
				pi t=*it;
				if(t.fr>=h[x[i]])break;
				ll pos=t.se;
				tmp.pb(mp(pos,tree.query(1,1,n,pos,pos))); 
				tree.update(1,1,n,pos,0);
				tree2.update(1,1,tot,h[pos],0);
				it++;
			}
			ll fx=tree.query(1,1,n,x[i]+1,n)+1;
		//	printf("fx:%lld\n",fx);
			tree.update(1,1,n,x[i],fx); //fx
			tree2.update(1,1,tot,h[x[i]],fx);
			// 
			int sz=tmp.size();
			//f 
			per(j,sz-1,0){
				pi info=tmp[j];
				ll pos=info.fr;
				ll val=tree.query(1,1,n,pos+1,n)+1;
			//	printf("pos:%lld val:%lld\n",pos,val);
				tree.update(1,1,n,pos,val);
				tree2.update(1,1,tot,h[pos],val);
			}
		}else{
			tmp.clear();
			set<pi>::iterator it=s1.begin(); 
			rep(j,1,x[i]-1){
			//	printf("iterator to:%d\n",(*it).fr);
				it++;
			}
			ll pos=(*it).fr;ll flag=pos;
		//	printf("%d\n",pos);
			tree.update(1,1,n,pos,0);
			tree2.update(1,1,tot,h[pos],0);
			it=s1.begin();
			rep(j,1,x[i]-1){
				pi t=*it;
				ll pos=t.fr;
				tmp.pb(mp(pos,pos));
				tree.update(1,1,n,pos,0);
				tree2.update(1,1,tot,h[pos],0);
				it++;
			}
			s1.erase(mp(pos,pos));
			s2.erase(mp(h[pos],pos));
			int sz=tmp.size();
			per(j,sz-1,0){
				ll pos=tmp[j].fr;
				ll val=tree2.query(1,1,tot,h[pos]+1,tot)+1;
				tree.update(1,1,n,tmp[j].fr,val);
				tree2.update(1,1,tot,h[tmp[j].fr],val);
			}
		}
		printf("%d\n",tree.query(1,1,n,1,n));
	}
	return 0;
}