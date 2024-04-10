/*input
2 4
DEF 0
ATK 0
0
0
1
1
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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m;
vector<int> a , b , v;
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , n + 1){
		string s; int in;
		cin >> s >> in;
		if(s == "ATK") a.pb(in);
		if(s == "DEF") b.pb(in);
	}
	REP(i , 1 , m + 1){
		int in; cin >> in;
		v.pb(in);
	}
	sort(ALL(a));
	sort(ALL(b));
	sort(ALL(v) , greater<int>());
	int ans = 0 , cnt = 0;
	REP(i , 0 , v.size()){
		if(i == a.size()) break;
		if(v[i] > a[i]) cnt += v[i] - a[i];
	}
	ans = max(ans , cnt) , cnt = 0;
	sort(ALL(v));
	for(auto to : b){
		int tmp = upper_bound(ALL(v) , to) - v.begin();
		if(tmp == v.size()) return cout << ans << endl , 0;
		else v.erase(v.begin() + tmp);
	}
	for(auto to : a){
		int tmp = lower_bound(ALL(v) , to) - v.begin();
		if(tmp == v.size()) return cout << ans << endl , 0;
		else cnt += v[tmp] - to , v.erase(v.begin() + tmp);
	}
	for(auto to : v) cnt += to;

	cout << max(cnt , ans) << endl;
    return 0;
}