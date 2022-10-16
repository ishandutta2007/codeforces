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
const int MAXN=1e5+10,LIM=1e5;
struct FenwickTree{
	int tree[MAXN];
	void Clear(){memset(tree,0,sizeof tree);}
	void Add(int x,int k){
		for(;x<=LIM;x+=lowbit(x))tree[x]+=k;
	}
	void Update(int L,int R,int k){
		if(L>R)return;
		Add(L,k);
		if(R<LIM)Add(R+1,-k);
	}
	int Query(int x){
		int sum=0;
		for(;x;x-=lowbit(x))sum+=tree[x];
		return sum;
	}
}tree;
struct Query{
	int L,R,idx;
	bool operator<(const Query& q2)const{return R<q2.R;}
}q[MAXN];
int n,m,a[MAXN],b[MAXN],c[MAXN],ans[MAXN],tot;
vector<int>pos[MAXN]; // 
int idx[MAXN]; //pos 
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){scanf("%d",&a[i]);c[i]=a[i];}
	rep(i,1,m){
		scanf("%d%d",&q[i].L,&q[i].R);
		q[i].idx=i;
	}
	sort(c+1,c+1+n),sort(q+1,q+1+m);
	tot=unique(c+1,c+1+n)-c-1;
	rep(i,1,n){b[i]=lower_bound(c+1,c+1+n,a[i])-c;}
	rep(i,1,n){if(!pos[b[i]].size())pos[b[i]].pb(0);}
	rep(i,1,n){
		idx[i]=pos[b[i]].size();
		pos[b[i]].pb(i);
	}
	tot=1;
	rep(i,1,n){
		int v1=a[i],v2=b[i],p=idx[i];
		if(p-1-v1>=0){
			tree.Update(pos[v2][p-1-v1]+1,pos[v2][p-v1],-1);
		}
		if(p-v1>=0){
			tree.Update(pos[v2][p-v1]+1,pos[v2][p-v1+1],1);
		}
		while(tot<=m && q[tot].R==i){
			ans[q[tot].idx]=tree.Query(q[tot].L);
			tot++;
		}
	}
	rep(i,1,m){
		printf("%d\n",ans[i]);
	}
	return 0;
}