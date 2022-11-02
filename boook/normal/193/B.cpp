/*input
2 1 0
1 1
1 1
1 -1
1 2
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
#define MAX 40
#define INF 100000000000000000LL

int n , t , r , b[MAX] , k[MAX] , p[MAX] , ans = -INF;
void DFS(vector<int> &a , int floor , int pre){
	if(floor % 2 == t % 2){
		int val = 0;
		REP(i , 1 , n + 1) val += a[i] * k[i];
		ans = max(ans , val);
	}
	if(floor == t) return ;
	vector<int> sol(n + 1) , add(n + 1);

	if(pre == 1){
		REP(i , 1 , n + 1) sol[i] = a[i] ^ b[i];
		DFS(sol , floor + 1 , 0);
	}
	if(pre == 0 || pre == 1){
		REP(i , 1 , n + 1) add[i] = a[p[i]] + r;
		DFS(add , floor + 1 , 1);
	}
}
int32_t main(){
	IOS;
	cin >> n >> t >> r;
	vector<int> sol(n + 1);
	REP(i , 1 , n + 1) cin >> sol[i];
	REP(i , 1 , n + 1) cin >> b[i];
	REP(i , 1 , n + 1) cin >> k[i];
	REP(i , 1 , n + 1) cin >> p[i];
	DFS(sol , 0 , 1);
	cout << ans << endl;
    return 0;
}