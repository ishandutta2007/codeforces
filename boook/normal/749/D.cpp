/*input
6
1 10
2 100
3 1000
1 10000
2 100000
3 1000000
3
1 3
2 2 3
2 1 2
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m;
map<int , int> big;
vector<int> v[MAX];
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		big[a] = b;
	}
	set<PII> cc;
	for(auto to : big) cc.insert(mp(to.B , to.A));

	cin >> m;
	REP(i , 1 , m + 1){
		int sum , in;
		cin >> sum;
		vector<int> sol;
		REP(i , 1 , sum + 1){
			cin >> in;
			if(big.find(in) == big.end()) continue;
			sol.pb(in);
			cc.erase(mp(big[in] , in));
		}
		if(cc.size() == 0) cout << "0 0" << endl;
		else {
			int now = (*prev(cc.end())).B;
			if(cc.size() == 1) cout << now << " " << v[now][0] << endl;
			else {
				int sec = (*prev(prev(cc.end()))).A;
				cout << now << " " << *lower_bound(ALL(v[now]) , sec) << endl;
			}
		}
		for(auto to : sol){
			cc.insert(mp(big[to] , to));
		}
	}
    return 0;
}