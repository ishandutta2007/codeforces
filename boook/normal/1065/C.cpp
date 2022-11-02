/*input
4 5
2 3 4 5
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , k , x[MAX];
map<int , int> cc;
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cc[x[i]] ++;
	priority_queue<PII> pq;
	for(auto to : cc) pq.push(to);

	int ans = 0 , sum = 0;
	while(pq.size() != 1){
		PII now = pq.top(); pq.pop();
		// DB4(now.A , now.B , "sum = " , sum);
		int have = k - sum;
		int to = min(now.A - pq.top().A , have / now.B);

		sum += to * now.B;
		now.A -= to;
		if(now.A == pq.top().A){
			PII nxt = pq.top(); pq.pop();
			pq.push(mp(nxt.A , nxt.B + now.B));
		}
		else pq.push(now);
		if(sum + pq.top().B > k) sum = 0 , ans ++;
	}
	if(sum != 0) ans ++;
	cout << ans << endl;
    return 0;
}