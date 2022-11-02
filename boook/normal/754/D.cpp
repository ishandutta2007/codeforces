/*input
4 2
1 100
40 70
120 130
125 180
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
#define MAX 300900
#define INF 0x3f3f3f3f

struct N{ int id , x , y; } x[MAX];
int cmp(N a , N b){ return a.x < b.x; }

int n , k , ans = 0;
void solve(int ok){
	priority_queue<PII , vector<PII> , greater<PII>> pq;
	REP(i , 1 , n + 1){
		pq.push(mp(x[i].y , i));
		while(pq.size() > k) pq.pop();
		if(pq.size() == k){
			if(ok == 0) ans = max(ans , pq.top().A - x[i].x + 1);
			if(ok == 1){
				if(pq.top().A - x[i].x + 1 == ans){
					cout << ans << endl;
					while(pq.size()){
						cout << x[pq.top().B].id << " ";
						pq.pop();
					}
					cout << endl;
					exit(0);
				}
			}
		}
	}
}
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) x[i].id = i , cin >> x[i].x >> x[i].y;
	sort(x + 1 , x + 1 + n , cmp);
	solve(0);
	solve(1);
	cout << ans << endl;
	REP(i , 1 , k + 1) cout << i << " "; cout << endl;
    return 0;
}