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
const int MAXN=2e5+10;
int T,n,k,ans;
set<int>e[MAXN],leaf[MAXN];
struct cmp{
	bool operator()(const int a,const int b)const{
		if(leaf[a].size()==leaf[b].size())return a>b;
		return leaf[a].size()>leaf[b].size();
	}
};
set<int,cmp>s;
void solve(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)e[i].clear(),leaf[i].clear();
	s.clear();ans=0;
	rep(i,1,n-1){
		int u,v; 
		scanf("%d%d",&u,&v);
		e[u].is(v);e[v].is(u);
	}
	rep(i,1,n){
		if(e[i].size()==1)leaf[*e[i].begin()].is(i);
	}
	rep(i,1,n)s.is(i);
	while(s.size()){
		int u=*s.begin();
		if((int)leaf[u].size()<k)break;
		rep(i,1,k){
			int v=*leaf[u].begin();
			e[u].erase(v);e[v].erase(u);
			s.erase(u);s.erase(v);
			leaf[u].erase(v);
			if(leaf[v].count(u))leaf[v].erase(u);
			if(e[u].size()==1){
				int w=*e[u].begin(); 
				s.erase(w);
				leaf[w].is(u);
				s.is(w);
			}
			s.is(u);s.is(v);
		}
		ans++;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}
/*
1
3 1
1 2
2 3
*/