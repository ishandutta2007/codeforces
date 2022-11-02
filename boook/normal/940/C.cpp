/*input
2 3
ba
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , use[MAX] , x[MAX];
string s;

int32_t main(){
	IOS;
	cin >> n >> m >> s;
	string ans = s;

	REP(i , 0 , s.size()) use[s[i] - 'a'] = 1;
	REP(i , 1 , 30) use[i] += use[i - 1];
	if(m > n){
		cout << s ;
		REP(i , n , m){
			int now = 0;
			RREP(j , 30 , 0){
				if(use[j] == 1) now = j;
			}
			cout << char('a' + now);
		}
		cout << endl;
	}
	else {
		REP(i , 0 , m) x[i] = use[s[i] - 'a'] - 1;
		x[m - 1] ++;
		// cout << use[25] << endl;
		// REP(i , 0 , m) cout << x[i] << " " ; cout << endl;
		RREP(i , m - 1 , 0){
			if(x[i] == use[25]) x[i - 1] ++ , x[i] = 0;
		}
		REP(i , 0 , m){
			int now = 0;
			RREP(j , 30 , 0){
				if(use[j] == x[i] + 1) now = j;
			}
			cout << char('a' + now);
		}
		cout << endl;
	}
    return 0;
}