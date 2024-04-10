/*input
9 2 5
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
#define MAX 
#define INF 0x3f3f3f3f

int n , m , k;
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 0 , n){
		int cnt = m * i;
		if(cnt > n) return cout << -1 << endl , 0;
		else {
			int las = n - cnt;
			if(las % k == 0){
				int aa = i , bb = las / k , pos = 1;
				REP(ii , 0 , aa){
					vector<int> cc;
					REP(jj , 0 , m) cc.pb(pos ++);
					cout << cc.back() << " " , cc.pop_back();
					REP(jj , 0 , cc.size()) cout << cc[jj] << " " ;
				}
				REP(ii , 0 , bb){
					vector<int> cc;
					REP(jj , 0 , k) cc.pb(pos ++);
					cout << cc.back() << " " , cc.pop_back();
					REP(jj , 0 , cc.size()) cout << cc[jj] << " " ;
				}cout << endl;
				return 0;
			}
		}
	}
    return 0;
}