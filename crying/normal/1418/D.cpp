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
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
ll n,q,a[MAXN],opt,x;
set<int>s;
multiset<int>g;
il ll solve(){
	if(s.size()<=2)return 0;
	return *s.rbegin()-*s.begin()-*g.rbegin();
}
void Insert(ll x){
	s.is(x);
	sit it=s.find(x),pre=s.find(x),nxt=s.find(x);
	pre--;nxt++;
	int flag1=nxt!=s.end(),flag2=it!=s.begin();
	if(flag1){
		g.is(*nxt-x);
	}
	if(flag2){
		g.is(x-*pre);
	}
	if(flag1&&flag2){
		g.erase(g.find(*nxt-*pre));
	}
}
void Delete(ll x){
	sit it=s.find(x),pre=s.find(x),nxt=s.find(x);
	pre--;nxt++;
	int flag1=nxt!=s.end(),flag2=it!=s.begin();
	int val1,val2;
	if(flag1)val1=*nxt;
	if(flag2)val2=*pre;
	s.erase(x);
	if(flag1){
		g.erase(g.find(val1-x));
	}
	if(flag2){
		g.erase(g.find(x-val2));
	}
	if(flag1 && flag2){
		g.is(val1-val2);
	}
}
int main(){
	cin>>n>>q;
	rep(i,1,n){
		cin>>a[i];
		Insert(a[i]);
	}
	printf("%lld\n",solve());
	rep(i,1,q){
		cin>>opt>>x;
		if(!opt){
			// 
			Delete(x);
		}else{
			// 
			Insert(x);
		}
		printf("%lld\n",solve());
	}
	return 0;
}