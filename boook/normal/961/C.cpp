/*input
3
101
010
101
101
000
101
010
101
011
010
101
010
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
#define MAX 200
#define INF 0x3f3f3f3f

int n;
string s[4][MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(ii , 0 , 4) REP(i , 0 , n) cin >> s[ii][i];
	int ans = INF;
	REP(i , 0 , 4) REP(j , i + 1 , 4){
		int cnt = 0;
		REP(ii , 0 , 4){
			if(ii == i || ii == j){
				REP(a , 0 , n) REP(b , 0 , n){
					if((a + b) % 2 == 0) cnt += s[ii][a][b] == '0';
					if((a + b) % 2 == 1) cnt += s[ii][a][b] == '1';
				}
			}
			else {
				REP(a , 0 , n) REP(b , 0 , n){
					if((a + b) % 2 == 0) cnt += s[ii][a][b] == '1';
					if((a + b) % 2 == 1) cnt += s[ii][a][b] == '0';
				}
			}
		}
		ans = min(ans , cnt);
	}
	cout << ans << endl;
    return 0;
}