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
const ull base1=13331,base2=998244353; 
vector<pi>edge[MAXN];
int n,m,k,ans;
ull power1[MAXN],power2[MAXN];
ull hash1[10][10],hash2[10][10];
ll val1,val2,tgt1,tgt2;
void dfs(int r){
	if(r==k+1){
		if(val1==tgt1 && val2==tgt2)ans++;
		return;
	}
	rep(i,1,r){
		//c[r]
		val1+=hash1[r][i]; 
		val2+=hash2[r][i];
		dfs(r+1);
		val1-=hash1[r][i];
		val2-=hash2[r][i];
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);edge[u].pb(mp(w,v));
	}
	rep(i,1,n){sort(edge[i].begin(),edge[i].end());}
	power1[0]=power2[0]=1;rep(i,1,n)power1[i]=power1[i-1]*base1,power2[i]=power2[i-1]*base2;
	rep(i,1,n)tgt1+=power1[i],tgt2+=power2[i];
//	printf("%llu %llu\n",tgt1,tgt2);
	rep(i,1,k){
		rep(j,1,i){
			//c[i]j
			//printf("c[%d]:%d\n",i,j);
			rep(x,1,n){
				if(edge[x].size()!=i)continue;
				hash1[i][j]+=power1[edge[x][j-1].se];
				hash2[i][j]+=power2[edge[x][j-1].se];
			//	printf("%d->%d\n",x,edge[x][j-1].se);
			} 
		}
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}