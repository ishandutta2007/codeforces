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
const int MAXN=3e3+10,INF=1e9;
int T,n,a[MAXN],ans;
int f[MAXN][MAXN];
vector<int>occ[MAXN];
void solve(){
	scanf("%d",&n);ans=INF;
	rep(i,1,n){
		occ[i].clear();
		scanf("%d",&a[i]);
	}
	rep(i,1,n){
		occ[a[i]].pb(i); 
	}
	rep(i,1,n){
		rep(j,i,n){
			if(i==j)f[i][j]=0;
			else f[i][j]=INF;
		}
	}
	rep(len,2,n){
		rep(i,1,n){
			int j=i+len-1;if(j>n)break;
			f[i][j]=min(f[i][j],1+f[i+1][j]);
			int sz=occ[a[i]].size();
			int L=lower_bound(occ[a[i]].begin(),occ[a[i]].end(),i)-occ[a[i]].begin();
			rep(R,L+1,sz-1){
				if(occ[a[i]][R]>j)break;
				f[i][j]=min(f[i][j],f[i][occ[a[i]][R]-1]+f[occ[a[i]][R]][j]);
			}
		}
	}
	printf("%d\n",f[1][n]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve(); 
	}

	return 0;
}