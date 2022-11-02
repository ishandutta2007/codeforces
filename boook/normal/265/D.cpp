/*input
9
1 2 3 5 6 7 8 9 10
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX];
map<int , int> cc[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];

	int ans = 0;
	REP(i , 1 , n + 1){
		vector<int> in;
		REP(j , 1 , x[i] + 1){
			if(j * j > x[i]) break;
			if(x[i] % j == 0){
				if(j != 1) in.pb(j);
			 	if(j * j != x[i]) in.pb(x[i] / j);
			}
		}
		// for(auto to : in) cout << to << " "; cout << endl;
		int big = 1;
		for(auto to : in){
			auto tmp = cc[to].lower_bound(x[i]);
			if(tmp != cc[to].begin()) big = max(big , (*prev(tmp)).B + 1);
		}
		for(auto to : in){
			auto nxt = cc[to].lower_bound(x[i]);
			while(nxt != cc[to].end() && (*nxt).B <= big){
				auto tmp = next(nxt);
				cc[to].erase(nxt) , nxt = tmp;
			}
			cc[to][x[i]] = big;
		}
		ans = max(ans , big);
	}
	cout << ans << endl;
    return 0;
}