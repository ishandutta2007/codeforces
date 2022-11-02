/*input
2
0 0 4 6
5 1 1000000000 1000000000
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
#define MAX 400900
#define INF 0x3f3f3f3f

set<PII> bit[MAX];
void update(int from , PII val){
	for(int i = from + 10 ; i < MAX ; i += i & -i)
		bit[i].insert(val);
}
int n , x[MAX][4] , dis[MAX] , p[MAX];
queue<int> qu;
void query(int xx , int yy , int val , int id){
	for(int i = xx + 10 ; i > 0 ; i -= i & -i){
		auto now = bit[i].begin();
		while(now != bit[i].end()){
			auto nxt = next(now);
			if((*now).A > yy) break;
			else if(dis[(*now).B] > val){
				dis[(*now).B] = val;
				p[(*now).B] = id;
				qu.push((*now).B);
			}
			bit[i].erase(now);
			now = nxt;
		}
	}
}
void solve(){
	REP(i , 0 , n) if(x[i][0] == 0 && x[i][1] == 0) dis[i] = 1 , qu.push(i);
	while(qu.size()){
		int now = qu.front(); qu.pop();
		query(x[now][2] , x[now][3] , dis[now] + 1 , now);
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 0 , n) REP(j , 0 , 4) cin >> x[i][j];

	vector<int> uni(1 , 0);
	REP(i , 0 , n) REP(j , 0 , 4) uni.pb(x[i][j]);
	sort(ALL(uni)) , uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 0 , n) REP(j , 0 , 4) x[i][j] = lower_bound(ALL(uni) , x[i][j]) - uni.begin();

	REP(i , 0 , n) dis[i] = INF , p[i] = -1;
	REP(i , 0 , n) update(x[i][0] , mp(x[i][1] , i));
	solve();
	vector<int> sol;
	int now = n - 1;
	while(now != -1) sol.pb(now) , now = p[now];
	if(dis[n - 1] == INF) cout << -1 << endl;
	else{
		cout << dis[n - 1] << endl;
		reverse(ALL(sol));
		for(auto to : sol) cout << to + 1 << " ";cout << endl;
	}
    return 0;
}