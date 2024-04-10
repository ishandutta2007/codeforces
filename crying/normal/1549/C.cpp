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
const int MAXN=2e5+10;
int n,m,u,v,q,op,ans;
set<int,greater<int> >s[MAXN];
il int check(int i){
	return (*s[i].begin())<=i;
}
int main(){
	cin>>n>>m;
	rep(i,1,n)s[i].is(i);
	rep(i,1,m){
		cin>>u>>v;
		s[u].is(v);s[v].is(u);
	}
	rep(i,1,n){
		if(check(i))ans++;
	}
	cin>>q;
	rep(i,1,q){
		cin>>op;
		if(op==1){
			cin>>u>>v;
			int flag1=check(u),flag2=check(v); 
			s[u].is(v);
			s[v].is(u);
			int tmp1=check(u),tmp2=check(v);
			if(flag1 && !tmp1)ans--;
			if(flag2 && !tmp2)ans--;
			if(!flag1 && tmp1)ans++;
			if(!flag2 && tmp2)ans++; 
		}else if(op==2){
			cin>>u>>v;
			int flag1=check(u),flag2=check(v); 
			s[u].erase(v);
			s[v].erase(u);
			int tmp1=check(u),tmp2=check(v);
			if(flag1 && !tmp1)ans--;
			if(flag2 && !tmp2)ans--;
			if(!flag1 && tmp1)ans++;
			if(!flag2 && tmp2)ans++; 		
		}else{
			
			cout<<ans<<endl;
		}
	}
	return 0;
}