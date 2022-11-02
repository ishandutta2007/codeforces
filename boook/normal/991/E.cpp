/*input
2028
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
#define MAX 100
#define INF 0x3f3f3f3f

string s;
int a[MAX] , d[MAX] , t[MAX] , c[MAX][MAX];
int32_t main(){
	IOS;
	cin >> s;
	REP(i , 0 , MAX) REP(j , 0 , i + 1){
		if(i == j) c[i][j] = 1;
		else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	REP(i , 0 , s.size()) a[s[i] - '0'] ++;
	d[0] = 1;
	RREP(ii , 9 , 0){
		if(a[ii] == 0) continue;
		else {
			REP(j , 0 , 50) t[j] = 0;
			// cout << a[ii] << endl;
			REP(j , 0 , 50){
				REP(k , 1 , a[ii] + 1){
					t[j + k] += d[j] * c[j + k - (ii == 0)][j - (ii == 0)];
				}
			}
			REP(j , 0 , 50) d[j] = t[j];
		}
			// REP(j , 0 , 50) cout << d[j] << " " ; cout << endl;
	}
	int ans = 0;
	REP(i , 0 , 50) ans += d[i];
	cout << ans << endl;
    return 0;
}