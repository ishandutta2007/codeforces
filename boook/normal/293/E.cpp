/*input
4 4 6
1 3
1 4
1 3
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
// #define endl "\n"
///------------------------------------------------------------
#define int int_fast64_t
#define MAX 200900
#define INF 0x3f3f3f3f

int n , l , w , ans = 0;
int siz[MAX] , use[MAX] , bit[MAX];
vector<PII> v[MAX];
void update(int from , int val){
	// DBGG("update = " , from);
	for(int i = from + 10 ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	if(from < 0) return 0;
	// DBGG("query - " , from);
	int cnt = 0;
	for(int i = from + 10 ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
PII FindCenter(int now , int fa , int all){
	PII res = mp(INF , now);
	siz[now] = 1;
	int big = 0;
	for(auto to : v[now]) if(use[to.A] == 0 && to.A != fa){
		res = min(res , FindCenter(to.A , now , all));
		big = max(big , siz[to.A]);
		siz[now] += siz[to.A];
	}
	big = max(big , all - siz[now]);
	res = min(res , mp(big , now));
	return res;
}
int solve(vector<PII> a){
	if(a.size() == 0) return 0;
	int cnt = 0 , pos = 0;
	sort(ALL(a));
	RREP(i , a.size() - 1 , 0){
		if(a[i].A + a[i].A <= w && a[i].B + a[i].B <= l) cnt --;
		while(pos < a.size() && a[pos].A + a[i].A <= w)
			update(a[pos].B , 1) , pos ++;
		cnt += query(l - a[i].B);
	}
	while(pos - 1 >= 0) update(a[pos - 1].B , -1) , pos --;
	return cnt;
}
vector<PII> sol;
void Getdis(int now , int fa , int deep , int wei){
	if(deep <= l && wei <= w) ans += 2;
	else return ;
	sol.pb(mp(wei , deep));
	for(auto to : v[now]) if(use[to.A] == 0 && to.A != fa){
		Getdis(to.A , now , deep + 1 , wei + to.B);
	}
}
void solveinit(int now , int all){
	now = FindCenter(now , now , all).B;
	use[now] = 1;
	for(auto to : v[now]) if(use[to.A] == 0) solveinit(to.A , siz[to.A]);

	vector<PII> a;
	for(auto to : v[now]) if(use[to.A] == 0){
		sol.clear() , Getdis(to.A , now , 1 , to.B);
		ans -= solve(sol);
		for(auto thing : sol) a.pb(thing);
	}
	ans += solve(a);
	use[now] = 0;
}

int32_t main(){
	IOS;
	cin >> n >> l >> w;
	REP(i , 2 , n + 1){
		int p , q;
		cin >> p >> q;
		v[p].pb(mp(i , q));
		v[i].pb(mp(p , q));
	}
	solveinit(1 , n);
	cout << ans / 2 << endl;
    return 0;
}