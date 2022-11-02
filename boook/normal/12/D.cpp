/*input
5
2 4 5 1 3
3 3 2 1 4
1 3 2 1 1
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
#define MAX 500900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , c[MAX];
vector<int> v[MAX];
void solveinit(){
	vector<int> uni;
	REP(i , 1 , n + 1) uni.pb(a[i]);
	sort(ALL(uni)) , uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 1 , n + 1) a[i] = lower_bound(ALL(uni) , a[i]) - uni.begin() + 1;

	uni.clear();
	REP(i , 1 , n + 1) uni.pb(b[i]);
	sort(ALL(uni)) , uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 1 , n + 1) b[i] = lower_bound(ALL(uni) , b[i]) - uni.begin() + 1;

	uni.clear();
	REP(i , 1 , n + 1) uni.pb(c[i]);
	sort(ALL(uni)) , uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 1 , n + 1) c[i] = lower_bound(ALL(uni) , c[i]) - uni.begin() + 1;
}
set<PII> cc;
void update(int a , int b){
	auto tmp = cc.lower_bound(mp(a , b));
	if((*tmp).B >= b) return ;
	tmp = prev(tmp);
	while(b >= (*tmp).B){
		auto nxt = prev(tmp);
		cc.erase(tmp);
		tmp = nxt;
	}
	cc.insert(mp(a , b));
}
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	REP(i , 1 , n + 1) cin >> c[i];

	solveinit();

	REP(i , 1 , n + 1) v[a[i]].pb(i);

	cc.insert(mp(0 , n + 1));
	cc.insert(mp(n + 1 , 0));
	int ans = 0;
	RREP(i , n , 1){
		for(auto to : v[i + 1]) update(b[to] , c[to]);
		for(auto to : v[i + 0]){
			auto tmp = cc.lower_bound(mp(b[to] , INF));
			if((*tmp).B > c[to]) ans ++;
		}
	}
	cout << ans << endl;
    return 0;
}