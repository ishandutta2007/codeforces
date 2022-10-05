#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005,M=N*200,inf=1e9+99;
int T[M],lc[M],rc[M],a[N],p[N],x[N];
int n,rt,sz;

void ins(int &o,int l,int r,int x,int y){
	if(!o)o=++sz;
	if(l==r){
		T[o]=max(T[o],y);
		return;
	}
	int m=(l+r)>>1;
	if(x<=m)ins(lc[o],l,m,x,y);
	else ins(rc[o],m+1,r,x,y);
	T[o]=max(T[lc[o]],T[rc[o]]);
}

int ask(int o,int l,int r,int x){
	if(!o||x<=l)return T[o];
	int m=(l+r)>>1;
	if(x<=m)return max(ask(lc[o],l,m,x),T[rc[o]]);
	return ask(rc[o],m+1,r,x);
}

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]),x[i]=inf;
		if(2*a[i]+1<=inf){
			p[i]=ask(rt,1,inf,2*a[i]+1);
			if(p[i])x[p[i]]=min(x[p[i]],i-p[i]);
		}
		ins(rt,1,inf,a[i],i);
	}
	rep(i,1,n)
		if(2*a[i]+1<=inf&&!p[i]){
			p[i]=ask(rt,1,inf,2*a[i]+1);
			if(p[i])x[p[i]]=min(x[p[i]],i+n-p[i]);
		}
	multiset<int> s; int delta=0;
	rep(i,1,n) s.insert(x[i]+i-1);
	rep(i,1,n){
		int res=*(s.begin())+delta;
		printf("%d ",res>=2*n+5?-1:res);
		s.erase(s.find(x[i]+i-1));
		s.insert(x[i]+n-delta);
		delta--;
	}
	return 0;
}