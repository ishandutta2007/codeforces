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
const int MAXN=1010;
int n,m,color[MAXN];
struct Query{
	int t,l,r;
}q[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d%d",&q[i].t,&q[i].l,&q[i].r);
	}
	rep(i,1,m){
		if(q[i].t==1){
			rep(j,q[i].l,q[i].r-1)color[j]=1; 
		}
	}
	rep(i,1,m){
		if(q[i].t==0){
			int flag=0;
			rep(j,q[i].l,q[i].r-1){
				if(!color[j])flag=1;
			}
			if(!flag){
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	int val=1e4;
	printf("%d ",val);
	rep(i,2,n){
		if(color[i-1])printf("%d ",val);
		else printf("%d ",--val); 
	}
	return 0;
}