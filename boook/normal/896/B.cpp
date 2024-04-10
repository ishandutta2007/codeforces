/*input

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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , c , x[MAX];
void P(int to , int val){
	x[to] = val;
	cout << to << endl;
	fflush(stdout);
}
int32_t main(){
	cin >> n >> m >> c;
	REP(i , 1 , n + 1) x[i] = -1;
	// 1 , n / 2 , n / 2 + 1 , n
	REP(i , 1 , m + 1){
		int id = -1 , val;
		cin >> val;
		if(val <= c / 2){
			REP(i , 1 , n / 2 + 1){
				if(x[i] == -1 || x[i] > val){
					P(i , val);
					id = 0;
					break;
				}
			}
			if(id == -1){
				REP(i , n / 2 + 1 , n + 1){
					if(x[i] == -1 || val < x[i] || i == n){
						P(i , val);
						break;
					}
				}
			}
		}
		else {
			RREP(i , n , n / 2 + 1){
				if(x[i] == -1 || x[i] < val){
					P(i , val);
					id = 0;
					break;
				}
			}
			if(id == -1){
				RREP(i , n / 2 , 1){
					if(x[i] == -1 || val > x[i] || i == 1){
						P(i , val);
						break;
					}
				}
			}
		}
		// cout << "BUG : " ;REP(i , 1 , n + 1) cout << x[i] << " "; cout << endl;

		int ok = 1;
		REP(i , 1 , n + 1) if(x[i] == -1) ok = 0;
		REP(i , 2 , n + 1) if(x[i - 1] > x[i]) ok = 0;
		if(ok) return 0;
	}
	cout << "get wrong answer" << endl;
    return 0;
}