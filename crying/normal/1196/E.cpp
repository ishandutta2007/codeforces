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
const int nextx[4]={1,0,-1,0},nexty[4]={0,1,0,-1};
set<pi>ans,ret;
int b,w,q;
void func1(){
	ans.clear();ret.clear();
	int x=1e8-1,y=1e8;
	ans.is(mp(x,y));
	b--;
	rep(k,0,3){
		ret.is(mp(x+nextx[k],y+nexty[k]));
	}
	while(b){
		x-=2;
		ans.is(mp(x,y));
		ans.is(mp(x+1,y));
		rep(k,0,3){
			ret.is(mp(x+nextx[k],y+nexty[k]));
		}
		ret.erase(mp(x+1,y));
		b--;
		w--;
	}
	if((int)ret.size()<w){
		printf("NO\n");return;
	}
	while(w){
		pi tmp=(*ret.begin());ret.erase(tmp);
		ans.is(tmp);w--; 
	}
	printf("YES\n");
	while(ans.size()){
		pi tmp=(*ans.begin());ans.erase(tmp);
		printf("%d %d\n",tmp.fr,tmp.se);
	}
}
void func2(){
	ans.clear();ret.clear();
	int x=1e8,y=1e8;
	ans.is(mp(x,y));
	w--;
	rep(k,0,3){
		ret.is(mp(x+nextx[k],y+nexty[k]));
	}
	while(w){
		x-=2;
		ans.is(mp(x,y));
		ans.is(mp(x+1,y));
		rep(k,0,3){
			ret.is(mp(x+nextx[k],y+nexty[k]));
		}
		ret.erase(mp(x+1,y));
		b--;
		w--;
	}
	if((int)ret.size()<b){
		printf("NO\n");return;
	}
	while(b){
		pi tmp=(*ret.begin());ret.erase(tmp);
		ans.is(tmp);b--; 
	}
	printf("YES\n");
	while(ans.size()){
		pi tmp=(*ans.begin());ans.erase(tmp);
		printf("%d %d\n",tmp.fr,tmp.se);
	}
}
void solve(){
	cin>>b>>w;
	if(b<=w)func1();
	else func2();
}
int main(){
	cin>>q;
	while(q--){
		solve();
	}

	return 0;
}