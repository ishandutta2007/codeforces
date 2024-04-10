/*input
7
10 9 5 5 4 3 2
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
#define int long long
#define INF 0x3f3f3f3f

int n , in;
map<int , int> cc;
priority_queue<int , vector<int> , greater<int> > pq;
int32_t main(){
	IOS;
	cin >> n;
	int all = 0 , ans = 0;
	REP(i , 1 , n + 1) cin >> in , cc[-in] ++ , ans += in;
	
	for(auto i : cc){
		int val = -i.A , cnt = min(i.B , all - pq.size() * 2) , pqadd = 0;
		vector<int> sol;
		REP(i , 0 , cnt) sol.pb(val);
		cnt = min(i.B , all) - cnt;

		// DB4("cnt = " , cnt , "" , "");
		for(int j = 1 ; j <= cnt ; j += 2){
			int tmp = pq.top(); pq.pop();
			if(tmp < val){
				sol.pb(val);
				if(j != cnt) sol.pb(val);
			} 
			else {
				sol.pb(tmp);
				if(j != cnt && val + val - tmp > 0) sol.pb(val + val - tmp);
			}
			
		}

		for(auto to : sol) pq.push(to);
		all += i.B;
		
		// vector<int> tmp;
		// while(pq.size()) tmp.pb(pq.top()) , pq.pop();
		// reverse(ALL(tmp));
		// for(auto to : tmp) cout << to << " " ;
		// cout << endl;
		// for(auto to : tmp) pq.push(to);
	}
	while(pq.size()) ans -= pq.top() , pq.pop();
	cout << ans << endl;
    return 0;
}