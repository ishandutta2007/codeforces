/*input
3
1337 1337 1337
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
const int MAX = 200900;
const int INF = 0x3f3f3f3f;

int n , x[MAX];
vector<int> v;
map<int , int> cc;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cc[x[i]] ++;
	for(auto to : cc) v.pb(to.S);
	sort(ALL(v));
	int ans = v.back();
	// cout << ans << endl;
	REP(i , 1 , v.back() + 1){
		int base = i , now = lower_bound(ALL(v) , i) - v.begin();
		int sum = i;
		REP(j , 2 , INF){
			base <<= 1 , sum += base;
			if(now + 1 == v.size() || v.back() < base) break;
			ans = max(ans , sum);
			if(v[now + 1] >= base) now ++;
			else now = lower_bound(ALL(v) , base) - v.begin();
		}
	}
	cout << ans << endl;
    return 0;
}