#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a) 
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
using namespace __gnu_pbds;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=2005;
//i_am_noob
int n,m,deg[maxn][maxn]={0},x,y;
char c[maxn][maxn];
queue<pii> q;
bool ok;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	rep(n) rep1(j,m) cin >> c[i][j];
	rep(n) rep1(j,m) if(c[i][j]=='.'){
		if(i!=0) deg[i-1][j]++;
		if(i!=n-1) deg[i+1][j]++;
		if(j!=0) deg[i][j-1]++;
		if(j!=m-1) deg[i][j+1]++;
	}
	rep(n) rep1(j,m) if(c[i][j]!='.') deg[i][j]=-1;
	rep(n) rep1(j,m) if(deg[i][j]==1) q.push(mp(i,j));
	while(!q.empty()){
		x=q.front().first,y=q.front().second;
		if(x!=0) if(c[x-1][y]=='.'){
			c[x][y]='v',c[x-1][y]='^';
			deg[x][y]=deg[x-1][y]=-1;
			if(x!=1){
				deg[x-2][y]--;
				if(deg[x-2][y]==1) q.push(mp(x-2,y));
			}
			if(y!=0){
				deg[x-1][y-1]--;
				if(deg[x-1][y-1]==1) q.push(mp(x-1,y-1));
			}
			if(y!=m-1){
				deg[x-1][y+1]--;
				if(deg[x-1][y+1]==1) q.push(mp(x-1,y+1));
			}
		}
		if(x!=n-1) if(c[x+1][y]=='.'){
			c[x][y]='^',c[x+1][y]='v';
			deg[x][y]=deg[x+1][y]=-1;
			if(x!=n-2){
				deg[x+2][y]--;
				if(deg[x+2][y]==1) q.push(mp(x+2,y));
			}
			if(y!=0){
				deg[x+1][y-1]--;
				if(deg[x+1][y-1]==1) q.push(mp(x+1,y-1));
			}
			if(y!=m-1){
				deg[x+1][y+1]--;
				if(deg[x+1][y+1]==1) q.push(mp(x+1,y+1));
			}
		}
		if(y!=0) if(c[x][y-1]=='.'){
			c[x][y]='>',c[x][y-1]='<';
			deg[x][y]=deg[x][y-1]=-1;
			if(y!=1){
				deg[x][y-2]--;
				if(deg[x][y-2]==1) q.push(mp(x,y-2));
			}
			if(x!=0){
				deg[x-1][y-1]--;
				if(deg[x-1][y-1]==1) q.push(mp(x-1,y-1));
			}
			if(x!=n-1){
				deg[x+1][y-1]--;
				if(deg[x+1][y-1]==1) q.push(mp(x+1,y-1));
			}
		}
		if(y!=m-1) if(c[x][y+1]=='.'){
			c[x][y]='<',c[x][y+1]='>';
			deg[x][y]=deg[x][y+1]=-1;
			if(y!=m-2){
				deg[x][y+2]--;
				if(deg[x][y+2]==1) q.push(mp(x,y+2));
			}
			if(x!=0){
				deg[x-1][y+1]--;
				if(deg[x-1][y+1]==1) q.push(mp(x-1,y+1));
			}
			if(x!=n-1){
				deg[x+1][y+1]--;
				if(deg[x+1][y+1]==1) q.push(mp(x+1,y+1));
			}
		}
		q.pop();
	}
	ok=true;
	rep(n) rep1(j,m) if(c[i][j]=='.') ok=false;
	if(!ok) print1("Not unique");
	else{
		rep(n){
			rep1(j,m) cout << c[i][j];
			cout << '\n';
		}
	}
	return 0;
}