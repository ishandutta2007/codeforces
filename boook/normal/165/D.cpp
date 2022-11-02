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
#define MAX 400090
#define INF 0x3f3f3f3f

int n , m;
VPII v[MAX];
int dep[MAX] , sp[MAX][20];
int bit[MAX] , dfspo;
int dotpo[MAX] , epo[MAX];

void update(int from , int v){ for(int i = from ; i < MAX ; i += i & -i) bit[i] += v; }
int Find(int now){
	int ans = 0;
	for(int i = now ; i > 0 ; i -= i & -i) ans += bit[i];
	return ans;
}
int query(int l , int r){
	if(l > r) swap(l , r);
	return Find(r - 1) - Find(l - 1);
}
void DFS(int now , int fa , int di){
	sp[now][0] = fa;
	dep[now] = di;
	dotpo[now] = dfspo;
	// cout << 58 ;DBGG(now , dfspo);
	for(auto i : v[now]){
		if(i.A == fa) continue;
		epo[i.B * 2] = dfspo++;
		DFS(i.A , now , di + 1);
		epo[i.B * 2 + 1] = dfspo++;
	}
}
void getsp(){
	REPNM(j , 1 , 20) REPNM(i , 1 , n + 1)
		sp[i][j] = sp[ sp[i][j - 1] ][j - 1];
}
int LCA(int a , int b){
	if(dep[a] != dep[b]){
		if(dep[a] < dep[b]) swap(a , b);
		RREP(i , 19 , 0){
			int to = sp[a][i];
			if(dep[to] > dep[b]) a = to;
		}
		a = sp[a][0];
	}
	if(a == b) return a;
	RREP(i , 19 , 0){
		int q = sp[a][i] , w = sp[b][i];
		if(q != w) a = q , b = w;
	}
	return sp[a][0];
}
int main(){
	RI(n);
	int q , w , e;
	REPNM(i , 1 , n) RII(q , w) , v[q].pb(mp(w , i)) , v[w].pb(mp(q , i));

    dfspo = 1 , DFS(1 , 0 , 0);
    getsp();
    
    // cout << "---" << endl;
    // REPNM(i , 1 , n) cout << epo[i + i] << "  " << epo[i * 2 + 1] << endl;
    // cout << "---" << endl;

    RI(m);
    REP(i , m){
    	RI(q);
    	if(q == 1){
    		RI(w);
    		update(epo[w * 2] , 1) , update(epo[w * 2 + 1] , -1);
    	}
    	else if(q == 2){
    		RI(w);
    		update(epo[w * 2] , -1) , update(epo[w * 2 + 1] , 1);
    	}
    	else if(q == 3){
    		RII(q , w);
    		int lca = LCA(q , w);
    		// DBGG("lca = " , lca);
    		int tma = query(dotpo[q] , dotpo[lca]);
    		int tmb = query(dotpo[w] , dotpo[lca]);
    		if(abs(tma) + abs(tmb) == 0) printf("%d\n", dep[q] + dep[w] - 2 * dep[lca]);
    		else puts("-1");
    	}
    }
    return 0;
}