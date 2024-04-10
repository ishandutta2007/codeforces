/*input
2
1 1
1 0
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX (1 << 18)
#define INF 0x3f3f3f3f

int n , d[MAX] , x[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 0 , n) cin >> d[i] >> x[i];
	priority_queue<PII , vector<PII> , greater<PII>> pq;
	REP(i , 0 , n) pq.push(mp(d[i] , i));
	vector<PII> ans;
	while(pq.size()){
		int dd = pq.top().A , id = pq.top().B;
		int xx = x[id];
		pq.pop();
		if(d[id] != dd || dd == 0) continue;
		else {
			if(dd != 1){
				assert(0);
			}
			else {
				ans.pb(mp(id , x[id]));
				d[x[id]] -- , x[x[id]] ^= id;
				pq.push(mp(d[x[id]] , x[id]));
			}
		}
	}
	cout << ans.size() << endl;
	for(auto to : ans) cout << to.A << " " << to.B << endl;
    return 0;
}