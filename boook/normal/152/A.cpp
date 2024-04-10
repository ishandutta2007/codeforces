/*input
3 5
91728
11828
11111
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
#define MAX 1000
#define INF 0x3f3f3f3f

int n , m , x[MAX];
string s[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];
	REP(i , 0 , n){
		REP(j , 0 , m) x[j] = max(x[j] , s[i][j] - '0');
	}
	int cnt = 0;
	REP(i , 0 , n){
		int ok = 0;
		REP(j , 0 , m){
			if(x[j] == s[i][j] - '0') ok = 1;
		}
		cnt += ok;
	}
	cout << cnt << endl;
    return 0;
}