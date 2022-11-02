/*input
10 4 3
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
#define MAX 400900
#define INF 0x3f3f3f3f

int n , d , k , o[MAX] , pos;
vector<PII> v;
void DFS(int deep , int now){
	// cout << deep << " " << now << endl;
	if(deep == 0) return ;
	REP(times , 2 , k + 1){
		if(pos <= n){
			v.pb(now , pos ++);
			DFS(deep - 1 , pos - 1);
		}
		else return;
	}
}
int32_t main(){
	IOS;
	cin >> n >> d >> k;
	REP(i , 2 , d + 2) v.pb(i - 1 , i);
	pos = d + 2;
	if(pos - 1 > n) return cout << "NO" << endl , 0;
	REP(i , 2 , d + 1){
		int v1 = i - 1 , v2 = d - v1;
		REP(times , 3 , k + 1){
			if(pos <= n){
				v.pb(pos++ , i);
				DFS(min(v1 , v2) - 1 , pos - 1);
			}
			else break;
		}
	}
	// DBGG("pos = " , pos);
	if(pos != n + 1) return cout << "NO" << endl , 0;
	for(auto to : v) o[to.A] ++ , o[to.B] ++;
	// REP(i , 1 , n + 1) cout << o[i] << " "; cout << endl;
	for(auto to : v) if(o[to.A] > k) return cout << "NO" << endl , 0;
	for(auto to : v) if(o[to.B] > k) return cout << "NO" << endl , 0;
	cout << "YES" << endl;
	for(auto to : v) cout << to.A << " " << to.B << endl;
    return 0;
}