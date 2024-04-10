/*input
5
3 3 3 1 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
const int MAX = 10090;
const int INF = 0x3f3f3f3f;

int n , x[MAX];
bitset<MAX> bb[110];
map<int , int> cc;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cc[x[i]] ++;
	int ans = 0;
	for(auto to : cc){
		REP(times , 1 , to.S + 1){

			int cnt = to.S - times + 1 , idx = 0;
			REP(i , 0 , n + 1) bb[i].reset();
			bb[0][0] = 1;

			int ok = 1 , pre = -1;
			REP(i , 1 , n + 1){
				if(cnt && x[i] == to.F) cnt --;
				else {
					if(pre == -1) pre = x[i];
					else ok = pre == x[i] ? ok : 0;

					RREP(j , times , 1){
						bb[j] |= bb[j - 1] << x[i];
					}
				}
			}
			if(bb[times][to.F * times] == 0){
				if(ok == 1) ans = n;
				else ans = max(ans , times);
			}
		}
	}
	cout << ans << endl;
    return 0;
}