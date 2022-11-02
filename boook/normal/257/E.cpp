/*input
10 10
2 10 1
1 2 7
10 9 10
9 3 1
2 8 10
5 1 6
8 8 5
4 2 9
9 1 8
2 3 5
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int bit[MAX];
int update(int from , int val){
	for(int i = from ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	int cnt = 0;
	for(int i = from ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
int n , m , x[MAX] , s[MAX] , t[MAX];
int sol[MAX] , ans[MAX];
vector<int> wait[MAX];
int cmp(int a , int b){ return x[a] < x[b]; }
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i] >> s[i] >> t[i];
	REP(i , 1 , n + 1) sol[i] = i;
	sort(sol + 1 , sol + 1 + n , cmp);
	int now = 1 , times = 0 , po = 1;

	set<PII> cc;
	while(cc.size() || po <= n){
		if(cc.empty()){
			// cout << "A" << endl;
			times = x[sol[po]];
			cc.insert(mp(s[sol[po]] , sol[po]));
			update(s[sol[po]] , 1);
			wait[s[sol[po]]].pb(sol[po]) , po ++;
		}
		else if(po == n + 1){
			// cout << "B" << endl;
			int ups = (int)(cc.size()) - query(now) , dws = query(now);
			int to = (*cc.lower_bound(mp(now , 0))).A;
			if(dws > ups) to = (*prev(cc.lower_bound(mp(now , 0)))).A;

			times += abs(to - now) , now = to;
		}
		else {
			int ups = (int)(cc.size()) - query(now) , dws = query(now);
			int to = (*cc.lower_bound(mp(now , 0))).A;
			if(dws > ups) to = (*prev(cc.lower_bound(mp(now , 0)))).A;
			if(x[sol[po]] <= times + abs(now - to)){
				// cout << "CA" << endl;
				int dis = x[sol[po]] - times;
				now = (ups >= dws) ? now + dis : now - dis , times += dis;
				cc.insert(mp(s[sol[po]] , sol[po]));
				update(s[sol[po]] , 1);
				wait[s[sol[po]]].pb(sol[po]) , po ++;
			}
			else times += abs(to - now) , now = to;
		}

		for(auto id : wait[now]){
			cc.insert(mp(t[id] , id));
			update(t[id] , 1);
		} wait[now].clear();

		auto tmp = cc.lower_bound(mp(now , 0));
		while(tmp != cc.end() && (*tmp).A == now){
			auto nxt = next(tmp);
			ans[(*tmp).B] = times;
			update((*tmp).A , -1);
			cc.erase(tmp) , tmp = nxt;
		}
		// DB4("times = " , times , "now = " , now);
	}
	REP(i , 1 , n + 1) cout << ans[i] << endl;
    return 0;
}