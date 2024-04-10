/*input
1 2
1 100
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
#define MAX 3030
#define INF 0x3f3f3f3f

int n , m , x[MAX][2] , cnt[MAX] , pri[MAX];
vector<int> v[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
	REP(i , 1 , n + 1){
		v[x[i][0]].pb(x[i][1]);
	}
	REP(i , 1 , m + 1) sort(ALL(v[i]) , greater<int>());

	int ans = INF * n;
	REP(i , 0 , n + 1){
		int cost = 0 , peo = v[1].size();
		vector<int> las;
		REP(j , 2 , m + 1){
			// for(auto to : v[j]) cout << to << " " ; cout << endl;
			REP(idx , 0 , v[j].size()){
				if(idx >= i) cost += v[j][idx] , peo ++;
				else las.pb(v[j][idx]);
			}
		}
		// DB4("cost = " , cost , "peo = " , peo);
		sort(ALL(las));
		// for(auto to : las) cout << to << " " ; cout << endl;
		REP(j , 0 , las.size()){
			if(peo <= i) cost += las[j] , peo ++;
		}
		// DB4("cost = " , cost , "peo = " , peo);
		if(peo > i) ans = min(ans , cost);
	}
	cout << ans << endl;
    return 0;
}