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
const ll MAXN=3e5+10,MAXM=1e6+10,INF=1e18;
struct Segment{
	ll l,r,w;
	bool operator<(const Segment& s2)const{
		return w<s2.w; 
	}
}line[MAXN];
struct SegmentTree{
	ll tree[MAXM<<2],tag[MAXM<<2];
	void pushup(int x){tree[x]=Min(tree[lc(x)],tree[rc(x)]);}
	void pushdown(int x){
		tree[lc(x)]+=tag[x];tree[rc(x)]+=tag[x];
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];
		tag[x]=0;
	}
	void update(int x,int l,int r,int ql,int qr,int val){
		if(ql>qr)return;
		if(ql<=l && qr>=r){
			tree[x]+=val;tag[x]+=val;
			return;
		}
		pushdown(x);
		int mid=(l+r)>>1;
		if(ql<=mid)update(lc(x),l,mid,ql,qr,val);
		if(qr>mid)update(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
	void query(int x,int l,int r,int ql,int qr,ll& val){
		if(ql<=l && qr>=r){
			val=Min(val,tree[x]);
			return;
		}
		pushdown(x);
		int mid=(l+r)>>1;
		if(ql<=mid)query(lc(x),l,mid,ql,qr,val);
		if(qr>mid)query(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
}tree; 
ll n,m,ans=INF;
int main(){
	cin>>n>>m;
	rep(i,1,n){
		cin>>line[i].l>>line[i].r>>line[i].w;
		if(line[i].r!=m)line[i].r--;
	}
	sort(line+1,line+1+n);
//	printf("\n");
	rep(i,1,n){
//		printf("%lld %lld %lld\n",line[i].l,line[i].r,line[i].w);
	}
	ll L=1,R=0;
	rep(i,1,n){
		tree.update(1,1,m,line[i].l,line[i].r,1);
		ll val=INF;
		tree.query(1,1,m,1,m,val);
		if(val!=0){
			ans=Min(ans,line[i].w-line[1].w);
			R=i;
			break;
		}
	} 
	ll tmp=INF;
	tree.query(1,1,m,1,1,tmp);
//	printf("TMP:%lld\n",tmp);
	while(L<n){
		tree.update(1,1,m,line[L].l,line[L].r,-1);
	//	printf("%d %d %d\n",line[L].l,line[L].r,-1);
		L++;
		if(L==2){
			ll tmp=INF;
			tree.query(1,1,m,1,m,tmp);
		//	printf("TMP:%lld\n",tmp);
		}
		while(R<L){
			R++;
			tree.update(1,1,m,line[R].l,line[R].r,1);
		}
		while(1){
			ll val=INF;
			tree.query(1,1,m,1,m,val);
			if(val!=0){
		//		printf("[%d,%d]\n",L,R);
				ans=Min(ans,line[R].w-line[L].w);
				break;
			} 
			if(R>=n)break;
			R++;
			if(R<=n){
				tree.update(1,1,m,line[R].l,line[R].r,1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 12
1 5 5
3 4 10
4 10 6
11 12 5
10 12 3

*/