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
const int MAXN=2010;
ll n,maxn,sum1,sum2;
ll depth[MAXN],fa[MAXN];
vector<ll>v[MAXN];
int main(){
	cin>>n;
	printf("? 1\n");
	fflush(stdout);
	rep(i,1,n){cin>>depth[i];depth[i]++;}
	rep(i,1,n){
		v[depth[i]].pb(i);
		if(depth[i]==2)fa[i]=1;
	}
	rep(i,1,n){
		if(odd(i))sum1+=v[i].size();
		else sum2+=v[i].size();
	}
	if(sum1<=(n+1)/2){
		//
		rep(i,3,n){if(even(i))continue;
			int sz=v[i].size();
			rep(j,0,sz-1){
				int u=v[i][j];
				printf("? %d\n",u);
				fflush(stdout);
				ll d;
				rep(x,1,n){
					cin>>d;
					if(d==1){
						if(depth[x]==depth[u]-1)fa[u]=x;
						else fa[x]=u;
					}
				}
			}
		} 
	}else{
		// 
		rep(i,2,n){if(odd(i))continue;
			int sz=v[i].size();
			rep(j,0,sz-1){
				int u=v[i][j];
				printf("? %d\n",u);
				fflush(stdout);
				ll d;
				rep(x,1,n){
					cin>>d;
					if(d==1){
						if(depth[x]==depth[u]-1)fa[u]=x;
						else fa[x]=u;
					}
				}
			}
		} 
	}
	printf("!\n");
	rep(i,2,n)printf("%lld %lld\n",fa[i],i);
	
	return 0;
}