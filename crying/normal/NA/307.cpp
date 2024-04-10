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
const int MAXN=2e3+10,MAXM=5e5+10;
int n,m,q,r[MAXM],L[MAXM],R[MAXM];
int sz[MAXN];
bitset<MAXN>a[MAXN];
struct cmp{
	bool operator()(const int& x,const int& y){
		if(sz[x]!=sz[y])return sz[x]<sz[y];
		return x<y;
	}
};
struct cmp2{
	bool operator()(const pi& x,const pi& y){
		if(x.se!=y.se)return x.se>y.se;
		return x.fr>y.fr;
	}
};
set<int,cmp>s;
set<int>s2;
int cnt=0;
bitset<MAXN>tmp;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,q){
		scanf("%d%d%d",&r[i],&L[i],&R[i]);
	}
	if(n<2 || m<2){
		rep(i,1,q)printf("-1\n");
		return 0;
	} 
	rep(i,1,n)s.is(i);
	rep(i,1,q){
		//r[i]
		auto it=s.find(r[i]);
		auto rit=it;rit++;
		if(it!=s.begin()){
			auto lit=it;lit--;
			int lnum=*lit; 
			s2.erase(lnum);
			if(rit!=s.end()){
				int rnum=*rit;
				if((a[lnum]&a[rnum])!=a[lnum])s2.is(lnum); 
			}
		}
		s.erase(it);
		s2.erase(r[i]);
		tmp.set();
		tmp>>=(MAXN-(R[i]-L[i]+1));
		tmp<<=L[i];
		a[r[i]]^=tmp;
		sz[r[i]]=a[r[i]].count();
		s.is(r[i]);
		it=s.find(r[i]);rit=it;rit++;
		if(it!=s.begin()){
			auto lit=it;lit--;
			int lnum=*lit;s2.erase(lnum);
			if((a[r[i]]&a[lnum])!=a[lnum])s2.is(lnum);
		}
		if(rit!=s.end()){
			int rnum=*rit;
			if((a[r[i]]&a[rnum])!=a[r[i]])s2.is(r[i]);
		}
		if(s2.begin()!=s2.end()){
			int xa=*s2.begin();
			auto it=s.find(xa);it++;
			int xb=*it;
			tmp=(a[xa]&a[xb]);
			int ya=(tmp^a[xa])._Find_first();
			int yb=(tmp^a[xb])._Find_first();
			if(xa>xb)swap(xa,xb);
			if(ya>yb)swap(ya,yb);
			printf("%d %d %d %d\n",xa,ya,xb,yb);
		}else puts("-1");
	}

	return 0;
}