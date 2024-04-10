/*input
2
6
5
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

int t , n;

int32_t main(){
	cin >> t ;
	REP(i , 1 , t + 1){
		cin >> n;
		int ok = 0;
		REP(i , 0 , n + 1){
			int tmp = n - 3 * i;
			if(tmp >= 0 && tmp % 7 == 0) ok = 1;
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}