/*input
7 5
1 3 2 1 4 2 3
1 1 4
2 2 3
1 1 7
2 4 5
1 1 7
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mid (l + r >> 1)

int bit[MAX];
void update(int from , int val){
	for(int i = from + 10 ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	int cnt = 0;
	for(int i = from + 10 ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
int query(int l , int r){ return query(r) - query(l - 1); }
struct node{ int ty , l , r , id; };
vector<node> sol;
set<int> cc[MAX];
int n , m , x[MAX] , ans[MAX] , qpo = 0;
int cmp(node a , node b){ return a.l < b.l; }
void solve(int l , int r){
	if(l == r) return ;
	else {
		vector<node> lth , rth;
		REP(i , l , mid + 0 + 1) if(sol[i].ty == 0) lth.pb(sol[i]);
		REP(i , mid + 1 , r + 1) if(sol[i].ty == 1) rth.pb(sol[i]);
		sort(ALL(lth) , cmp) , sort(ALL(rth) , cmp);
		int pos = 0;
		for(auto now : rth){
			while(pos < lth.size() && lth[pos].l <= now.l)
				update(lth[pos].r , lth[pos].id) , pos ++;
			ans[now.id] += query(now.r , n + 1);
		}
		while(pos - 1 >= 0) pos -- , update(lth[pos].r , -lth[pos].id);
		solve(l , mid + 0);
		solve(mid + 1 , r);
	}
}
void add(int id , int pre , int val){
	sol.pb(node{0 , id , pre , (id - pre) * val});
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cc[i].insert(0);
	REP(i , 1 , n + 1){
		int pre = *prev(cc[x[i]].end());
		sol.pb(node{0 , i , pre , i - pre});
		cc[x[i]].insert(i);
	}
	REP(i , 1 , n + 1) cc[i].insert(n + 1);
	REP(i , 1 , m + 1){
		int ty , a , b;
		cin >> ty >> a >> b;
		if(ty == 1){
			auto now = cc[x[a]].find(a);
			add(*now , *prev(now) , -1);
			add(*next(now) , *now , -1);
			add(*next(now) , *prev(now) , 1);
			cc[x[a]].erase(a);
			x[a] = b;
			cc[x[a]].insert(a);
			now = cc[x[a]].find(a);
			add(*now , *prev(now) , 1);
			add(*next(now) , *now , 1);
			add(*next(now) , *prev(now) , -1);
		}
		if(ty == 2) sol.pb(node{1 , b , a , ++qpo});
	}
	solve(0 , sol.size());
	REP(i , 1 , qpo + 1) cout << ans[i] << endl;
    return 0;
}