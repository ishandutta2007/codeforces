#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
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
const int MAXN=3e5+10;
ll n,m,b[MAXN*2],tot,f[MAXN],pre[MAXN];
ll u,ans,tag[MAXN];
bool operator>(const pi& p1,const pi& p2){
	if(p1.fr!=p2.fr)return p1.fr>p2.fr;
	return p1.se>p2.se;
}
bool operator<(const pi& p1,const pi& p2){
	if(p1>p2)return 0;
	return 1;
}
struct Node{
	ll R,l,r;
}line[MAXN];
vector<Node>t[MAXN];
void solve(int u){
	if(u==0)return;
	tag[u]=1;
	solve(pre[u]);
}
struct SegmentTree{
	pi tree[MAXN<<3],tag[MAXN<<3];
	void pushup(int x){
		tree[x]=Max(tree[lc(x)],tree[rc(x)]);
	}
	void pushdown(int x){
		tree[lc(x)]=Max(tree[lc(x)],tag[x]);
		tree[rc(x)]=Max(tree[rc(x)],tag[x]);
		tag[lc(x)]=Max(tag[lc(x)],tag[x]);
		tag[rc(x)]=Max(tag[rc(x)],tag[x]);
		tag[x]=mp(0,0);
	}
	void modify(int x,int l,int r,int ql,int qr,int val,int idx){
		if(ql<=l && qr>=r){
			pi tmp=mp(val,idx);
			tree[x]=Max(tree[x],tmp);
			tag[x]=Max(tag[x],tmp);
			return;
		}
		pushdown(x);
		int mid=(l+r)>>1;
		if(ql<=mid)modify(lc(x),l,mid,ql,qr,val,idx);
		if(qr>mid)modify(rc(x),mid+1,r,ql,qr,val,idx);
		pushup(x);
	}
	pi query(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r){
			return tree[x];
		}
		pushdown(x);
		int mid=(l+r)>>1;pi ans=mp(0,0);
		if(ql<=mid){
			pi tmp=query(lc(x),l,mid,ql,qr);
			ans=Max(ans,tmp);
		}
		if(qr>mid){
			pi tmp=query(rc(x),mid+1,r,ql,qr);
			ans=Max(ans,tmp);
		}
		pushup(x);
		return ans;
	}
}tree;
int main(){
	cin>>n>>m;
	rep(i,1,m){
		cin>>line[i].R>>line[i].l>>line[i].r;
		b[++tot]=line[i].l;
		b[++tot]=line[i].r;
	}
	sort(b+1,b+1+tot);
	tot=unique(b+1,b+1+tot)-b-1;
	rep(i,1,m){
		line[i].l=lower_bound(b+1,b+1+tot,line[i].l)-b;
		line[i].r=lower_bound(b+1,b+1+tot,line[i].r)-b;
	}
	rep(i,1,m){
		t[line[i].R].pb(line[i]); 
	}
	rep(i,1,n){
		f[i]=1;
		ll sz=t[i].size();
		rep(j,0,sz-1){
			ll L=t[i][j].l,R=t[i][j].r;
			pi tmp=tree.query(1,1,tot,L,R);
			if(tmp.fr!=0){
				if(f[i]<tmp.fr+1){
					f[i]=tmp.fr+1;
					pre[i]=tmp.se;
				}
			}
		}
		rep(j,0,sz-1){
			ll L=t[i][j].l,R=t[i][j].r;
			tree.modify(1,1,tot,L,R,f[i],i);
		}
	}
	rep(i,1,n){
		if(ans<f[i]){
			ans=f[i];
			u=i;
		}
	}
	printf("%lld\n",n-ans);
	solve(u);
	rep(i,1,n){
		if(!tag[i]){
			printf("%lld ",i);
		}
	}
	return 0;
}