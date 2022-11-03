/*input
7
3 0 0 4 2 2 1
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , x[MAX];
vector<int> v[MAX] , ans;
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) v[x[i]].pb(i);

	int cnt = 0;
	while(cnt >= 0){
		if(v[cnt].size()){
			ans.pb(v[cnt].back());
			v[cnt].pop_back();
			cnt ++;
		}
		else {
			cnt -= 3;
		}
	}

	if(ans.size() == n){
		cout << "Possible" << endl;
		for(auto to : ans) cout << to << " " ; cout << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
    return 0;
}