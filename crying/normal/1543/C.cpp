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
const db EPS=1e-7,INF=-1;
int t;
db a1,a2,a3,v,ans;
il int equ(const db& d1,const db& d2){
	return fabs(d1-d2)<EPS;
}
il int ge(const db& d1,const db& d2){return (d1-d2)>EPS;}
void dfs(db a1,db a2,db a3,db prob,int level){
	ans+=prob*a3*(level+1);
//	printf("%.2f %.2f %.2f %.2f %d\n",a1,a2,a3,prob,level);
	if(!equ(a1,INF)){
		if(ge(a1,v))dfs(a1-v,(equ(a2,INF))?INF:a2+v/2,equ(a2,INF)?a3+v:a3+v/2,prob*a1,level+1);
		else dfs(INF,(equ(a2,INF))?INF:a2+a1/2,equ(a2,INF)?a3+a1:a3+a1/2,prob*a1,level+1);
	}
	if(!equ(a2,INF)){
		if(ge(a2,v))dfs(equ(a1,INF)?INF:a1+v/2,a2-v,equ(a1,INF)?a3+v:a3+v/2,prob*a2,level+1);
		else dfs(equ(a1,INF)?INF:a1+a2/2,INF,equ(a1,INF)?a3+a2:a3+a2/2,prob*a2,level+1);
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>a1>>a2>>a3>>v;
		ans=0;
		dfs(a1,a2,a3,1,0);
		printf("%.6f\n",ans);
	}

	return 0;
}