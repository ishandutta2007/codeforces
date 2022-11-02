#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
typedef pair< LL , LL > PLL;
typedef vector< int > VI;
typedef vector< LL > VLL;
typedef vector< PII > VPII;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 100090
#define INF 0x3f3f3f3f

int n , q , w , e , sp[MAX][20] , dep[MAX] , siz[MAX];
VI v[MAX];
int DFS(int now , int fa , int d){
	dep[now] = d;
	sp[now][0] = fa;
	siz[now] = 1;
	for(auto i : v[now]) if(i != fa) siz[now] += DFS(i , now , d + 1);
	return siz[now];
}
void solveinit(){
	DFS(1 , 0 , 1);
	REPNM(j , 1 , 20){
		REPNM(i , 1 , n + 1)
			sp[i][j] = sp[ sp[i][j - 1] ][j - 1];
	}
}
int Lca(int a , int b){
	if(dep[a] != dep[b]){
		if(dep[a] < dep[b]) swap(a , b);
		RREP(i , 19 , 0){
			int to = sp[a][i];
			if(dep[to] >= dep[b]) a = to;
		}
	}
	if(a == b) return a;
	RREP(i , 19 , 0){
		int toa = sp[a][i];
		int tob = sp[b][i];
		if(toa != tob) a = toa , b = tob;
	}
	return sp[a][0];
}
int solve(int a , int b){
	if(a == b) return n;
	if(dep[a] % 2 != dep[b] % 2) return 0;
	int lca = Lca(a , b);
	if(dep[a] == dep[b]){
		int dis = dep[a] - dep[lca];
		RREP(i , 19 , 0){
			if(dis > (1 << i)){
				dis -= (1 << i);
				a = sp[a][i];
				b = sp[b][i];
			}
		}
		return n - siz[a] - siz[b];
	}
	else {
		int dis = (dep[a] + dep[b] - dep[lca] * 2) / 2;
		int now = (dep[a] > dep[b]) ? a : b;
		RREP(i , 19 , 0){
			if(dis > (1 << i)){
				dis -= (1 << i);
				now = sp[now][i];
			}
		}
		int fa = sp[now][0];
		return siz[fa] - siz[now];
	}
}
int main(){
    IOS;
    cin >> n;
    REP(i , n - 1) cin >> q >> w , v[q].pb(w) , v[w].pb(q);
    solveinit();
    cin >> q;
    REP(i , q){
    	cin >> w >> e;
    	int ans = solve(w , e);
    	cout << ans << endl;
    }
    return 0;
}