/*input
10
12 16
3 16
15 3
11 3
5 3
19 11
10 9
4 11
6 13
17 9
10
59 69 96 63 98 78 96 97 84 86
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f
#define N 30


PII operator + (PII x , PII y){ return mp(x.A + y.A , x.B + y.B); }
int n , m , q[MAX] , c[MAX] , x[MAX];
int cmp1(int a , int b){
	if(q[a] != q[b]) return q[a] > q[b];
	if(q[a] == q[b]) return c[a] < c[b];
}
int val[MAX] , ans[MAX] , now[MAX];
PII sml[35][MAX];

int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> c[i] >> q[i];
	REP(i , 1 , n + 1) x[i] = i;
	sort(x + 1 , x + 1 + n , cmp1);
	REP(i , 1 , n + 1) x[i] = c[x[i]];

	REP(i , 0 , N + 1) REP(j , 1 , n + 1) if(x[j] < (1 << i)) sml[i][j] = mp(x[j] , 1);
	REP(i , 0 , N + 1) REP(j , 1 , n + 1) sml[i][j] = sml[i][j] + sml[i][j - 1];

	cin >> m;
	REP(i , 1 , m + 1) cin >> val[i];

	// REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;

	RREP(bit , N , 0){
		vector<PII> sol , big;
		REP(i , 1 , m + 1) if(val[i] >= (1 << bit)) sol.pb(val[i] + sml[bit][now[i]].A , i);
		REP(i , 1 , n + 1) if(x[i] >= (1 << bit)) big.pb(x[i] + sml[bit][i].A , i);
		sort(ALL(sol));
		sort(ALL(big));
		if(sol.size() == 0) continue;
		// DB4("bit ------------------------------= " , bit , "1 << bit = " , (1 << bit));
		// for(auto to : sol) cout << to.A << "-" << to.B << "(" << now[to.B] << ")" << "  "; cout << endl;
		// for(auto to : sol) cout << val[to.B] << "  "; cout << endl;
		set<int> cc;
		int pos = 0;
		while(pos < sol.size() && big.size() && sol[pos].A < big[0].A) pos ++;
		// DBGG("possize = " , big.size());
		auto it = big.begin();
		while(it != big.end()){
			int nextVal = next(it) == big.end() ? INF : next(it)->A;
			cc.insert(it->B);
			// DBGG("insert" , it->B);
			while(pos < sol.size() && sol[pos].A < nextVal){
				auto tmp = cc.upper_bound(now[sol[pos].B]);
				if(tmp != cc.end()){
					// DBGG("tmp ======= " , (*tmp));
					int idx = sol[pos].B;
					int from = now[idx];
					int to = *tmp;
					val[idx] -= sml[bit][to].A - sml[bit][from].A + x[to];
					ans[idx] += sml[bit][to].B - sml[bit][from].B + 1;
					now[idx] = to;
				}
				pos ++;
			}
			it ++;
		}
		for(auto it : sol) if(val[it.B] >= (1 << bit)){
			// cout << "here" << endl;
			int from = now[it.B];
			RREP(i , 30 , 0){
				int to = from + (1 << i);
				if(to <= n && sml[bit][to].A - sml[bit][now[it.B]].A <= val[it.B]) from = to;
			}
			val[it.B] -= sml[bit][from].A - sml[bit][now[it.B]].A;
			ans[it.B] += sml[bit][from].B - sml[bit][now[it.B]].B;
			now[it.B] = from;
		}
	}
	REP(i , 1 , m + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}