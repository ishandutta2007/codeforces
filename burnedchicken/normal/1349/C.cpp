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
const int MOD=Mod;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=1005;
//i_am_noob
int n,m,t,a[maxn][maxn],x,y,p;
char c[maxn][maxn];
queue<pii> q;
bool flag,vis[maxn][maxn];
pii b;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m >> t;
	rep(n) rep1(j,m) cin >> c[i][j];
	rep(n) rep1(j,m){
		flag=false;
		if(i!=0) if(c[i][j]==c[i-1][j]) flag=true;
		if(i!=n-1) if(c[i][j]==c[i+1][j]) flag=true;
		if(j!=0) if(c[i][j]==c[i][j-1]) flag=true;
		if(j!=m-1) if(c[i][j]==c[i][j+1]) flag=true;
		if(flag){
			vis[i][j]=true;
			a[i][j]=0;
			q.push(mp(i,j));
		}
	}
	if(q.empty()){
		while(t--){
			cin >> x >> y >> p;
			x--,y--;
			print1(c[x][y]);
		}
		return 0;
	}
	while(!q.empty()){
		b=q.front();
		if(b.first!=0){
			if(!vis[b.first-1][b.second]){
				a[b.first-1][b.second]=a[b.first][b.second]+1;
				vis[b.first-1][b.second]=true;
				q.push(mp(b.first-1,b.second));
			}
		}
		if(b.first!=n-1){
			if(!vis[b.first+1][b.second]){
				a[b.first+1][b.second]=a[b.first][b.second]+1;
				vis[b.first+1][b.second]=true;
				q.push(mp(b.first+1,b.second));
			}
		}
		if(b.second!=0){
			if(!vis[b.first][b.second-1]){
				a[b.first][b.second-1]=a[b.first][b.second]+1;
				vis[b.first][b.second-1]=true;
				q.push(mp(b.first,b.second-1));
			}
		}
		if(b.second!=m-1){
			if(!vis[b.first][b.second+1]){
				a[b.first][b.second+1]=a[b.first][b.second]+1;
				vis[b.first][b.second+1]=true;
				q.push(mp(b.first,b.second+1));
			}
		}
		q.pop();
	}
	while(t--){
		cin >> x >> y >> p;
		x--,y--;
		print1((int)(c[x][y]-'0')^(max(0ll,p-a[x][y])&1));
	}
	return 0;
}