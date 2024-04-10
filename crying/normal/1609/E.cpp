#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=1e5+10,INF=1e9;
int n,q,pos;
char ch;
int a[MAXN],sum[MAXN][3],suf[MAXN];
struct Seg{
	int t1[MAXN<<2],t2[MAXN<<2],t3[MAXN<<2],t4[MAXN<<2],t5[MAXN<<2],t6[MAXN<<2];
	void pushup(int x){
		t1[x]=t1[lc(x)]+t1[rc(x)];
		t2[x]=t2[lc(x)]+t2[rc(x)];
		t3[x]=t3[lc(x)]+t3[rc(x)];
		t4[x]=min(t1[lc(x)]+t4[rc(x)],t4[lc(x)]+t2[rc(x)]);
		t5[x]=min(t2[lc(x)]+t5[rc(x)],t5[lc(x)]+t3[rc(x)]);
		t6[x]=min(t1[lc(x)]+t6[rc(x)],min(t4[lc(x)]+t5[rc(x)],t6[lc(x)]+t3[rc(x)]));
	}
	void build(int x,int l,int r){
		if(l==r){
			if(a[l]==0)t1[x]=1;
			else if(a[l]==1)t2[x]=1;
			else t3[x]=1;
			return;
		}
		int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);pushup(x);
	}
	void update(int x,int l,int r,int pos,int val){
		if(l==r){
			t1[x]=t2[x]=t3[x]=0;
			if(val==0)t1[x]=1;
			else if(val==1)t2[x]=1;
			else t3[x]=1;return;
		} 
		int mid=(l+r)>>1;
		if(pos<=mid)update(lc(x),l,mid,pos,val);
		else update(rc(x),mid+1,r,pos,val);
		pushup(x);
	}
}t;
void solve(){
	t.update(1,1,n,pos,ch-'a');
	printf("%d\n",t.t6[1]);	
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf(" %c",&ch);
		a[i]=ch-'a';
	}
	t.build(1,1,n);
	rep(i,1,q){
		scanf("%d %c",&pos,&ch);
		solve();
	}

	return 0;
}